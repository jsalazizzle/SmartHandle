
#include <BusManager.h>
#include <SystemCore.h>
#include <KinOS.h>

#include <AccDriver.h>
#include <GyrDriver.h>
#include <AlsDriver.h>

#include "debug.h"

//-------------------------------------------------------------//

bool local_bus_busy = false;  // Global to BusManager.c

//-------------------------------------------------------------//

#define NUM_OPERATIONS 11

static uint8 operation_fifo[NUM_OPERATIONS];

static uint8 head = 0; // FIFO Head
static uint8 tail = 0; // FIFO Tail
static uint8 size = 0; // FIFO Size

//-------------------------------------------------------------//
//-------------------------XXXXXXXXXXX-------------------------//
//-------------------------------------------------------------//

static bool SensorBusBusy()
{
    return (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY);
}
void LaunchPending()
{
    if(SensorBusBusy() || (size==0) ) return;
    
    if(!local_bus_busy) {local_bus_busy = true; SensorBus_Enable();}
        
    switch(operation_fifo[tail])
    {
        case ACC:
        {
            if(!AccDriver_OperationDone()) return;
            break;
        }
        case GYR:
        {
            if(!GyrDriver_OperationDone()) return;
            break;
        }
        case NONE:
        {
            break;
        }
    }
    
    operation_fifo[tail] = NONE;
    tail = (tail+1) % NUM_OPERATIONS;
    size = size - 1;

    if(local_bus_busy) {SensorBus_Disable(); local_bus_busy = false;}
}
bool BusManager_UpdateSetting(uint8 sensor_type, uint8 setting_type, int32 setting_value)
{
    int32 period_ms = -1;
    
    switch(sensor_type)
    {
        case ACC: period_ms = AccDriver_UpdateSetting(setting_type,setting_value); break;
        case GYR: period_ms = GyrDriver_UpdateSetting(setting_type,setting_value); break;
    }
    if(period_ms == -1)
    {
        return false;
    }
    else
    {
        SystemCore_SetBusManagerTimer(sensor_type, period_ms);
        return true;
    }
}

//-------------------------------------------------------------//
//--------------------TIMING-AND-TRIGGERING--------------------//
//-------------------------------------------------------------//

void BusManager_Tick(uint8 sensor_type)
{
    if(size < NUM_OPERATIONS)
    {
        operation_fifo[head] = sensor_type;
        head = (head+1) % NUM_OPERATIONS;
        size = size + 1;
        LaunchPending();
    }
}
//-------------------------------------------------------------//
//----------------------SENSOR-ARBITRATION---------------------//
//-------------------------------------------------------------//

static void SensorBus_ExitCallback(uint32_t event)
{
    if (0UL != (CY_SCB_I2C_MASTER_WR_CMPLT_EVENT & event) | 0UL != (CY_SCB_I2C_MASTER_RD_CMPLT_EVENT & event))
    {        
        if(SensorBusBusy() == false)
        {
            LaunchPending();
        }
    }
}
//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void BusManager_Init()
{
    DataBuffer_Init();
    
    local_bus_busy = true; SensorBus_Start();
    
    SensorBus_RegisterEventCallback((cy_cb_scb_i2c_handle_events_t) SensorBus_ExitCallback);
    
    //AlsDriver_Init();
    
    DEBUG_PRINTF("Configuring Sensor... ");     
    DEBUG_WAIT_UART_TX_COMPLETE();

    AccDriver_Init();
    
    DEBUG_PRINTF("Finished \r\n");     
    DEBUG_WAIT_UART_TX_COMPLETE();
    //GyrDriver_Init();
    
    //SensorBus_Disable(); local_bus_busy = false;
    
    CyDelay(10); // Sensor boot delay
    
    DEBUG_PRINTF("BusManager_Init 1\r\n");
    DEBUG_WAIT_UART_TX_COMPLETE();
}
//-------------------------------------------------------------//
