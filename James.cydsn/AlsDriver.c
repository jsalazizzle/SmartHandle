#include <AlsDriver.h>
#include <DataBuffer.h>
#include <KinOS.h>

#include "debug.h"

#define DEBUG_ALS 0

static cy_stc_scb_i2c_master_xfer_config_t register_setting;
static uint8 rbuff[256]; // Read buffer: 32 sample fifo x 3 axis x 2 bytes
static uint8 wbuff[3];   // Write buffer

static uint16 ReadRegister(uint8 reg_addr)
{
    cy_en_scb_i2c_status_t i2cReturnValue;
    
    wbuff[0] = reg_addr;    
    register_setting.buffer = wbuff; register_setting.bufferSize = 1; register_setting.xferPending = true;
    
    i2cReturnValue = SensorBus_MasterWrite(&register_setting);
    if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
    {
        // ** Throw error
    }
    
    uint16 counter = 0;
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY))
    {
        if(++counter > 1000) 
        {
            // ** Throw error
            return 0;         
        }
        else
        {
            CyDelayUs(1);  // Keep Waiting
        }
    }
    
    register_setting.buffer = rbuff; register_setting.bufferSize = 2; register_setting.xferPending = false;
    
    i2cReturnValue = SensorBus_MasterRead(&register_setting);
    if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
    {
        // ** Throw error
    }
    
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY)){}
    {
        if(++counter > 1000) 
        {
            // ** Throw error
            return 0;
        }
        else
        {
            CyDelayUs(1);  // Keep Waiting
        }
    }
    return rbuff[0] << 8 | rbuff[1];
}

static void WriteRegister(uint8 reg_addr, uint16 data)
{
    wbuff[0] = reg_addr; wbuff[1] = data >> 8; wbuff[2] = data;
    register_setting.buffer = wbuff; register_setting.bufferSize = 3; register_setting.xferPending = false;        
    
    cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterWrite(&register_setting);
    if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
    {
        // ** Throw error
    }
    
    uint16 counter = 0;
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY)){}
    {
        if(++counter > 1000)
        {
            // ** Throw error
            return;
        }
        else
        {
            CyDelayUs(1);  // Keep Waiting
        }
    }
    return;
}

void AlsDriver_Init()
{
    register_setting.slaveAddress = ALS_ADDR;
    if(ReadRegister(ALS_DEV_ID_ADDR) != ALS_DEV_ID_VAL) // Verify Chip ID          W[0x88 0x7F] R[0x89 0x30 0x01]
    {
        // ** Throw error
        CyDelayUs(1);
    }
    
    WriteRegister(ALS_INT_LOW_THRES, 0x1A45);  //0x1a45 set lower limit to 67.25 lux
    WriteRegister(ALS_INT_HIGH_THRES, 0x339A); //0x339a set upper limit to 100.360 lux
    WriteRegister(ALS_CONFIG, 0xCC0A);         //Continuous conversion mode, hysteresis-style, inverted polarity, four fault count
    
    #if DEBUG_ALS
    uint16 raw_val;
    uint8 raw_exp;
    float lux_val;
    for(;;){
        CyDelay(800);                // Delay needed for 800 ms conversion
        raw_val = ReadRegister(ALS_RESULT);
        raw_exp = 1 << (raw_val >> 0xD);    // exp = 2 ^ (3 most sig bits of result)
        lux_val = 0.01 * raw_exp * (raw_val & ALS_RES_MASK);
        DEBUG_PRINTF("raw val: %x\tdec vale:%0.3f\r\n",raw_val,lux_val);
        DEBUG_WAIT_UART_TX_COMPLETE();
    }
    #endif
    return;
}

