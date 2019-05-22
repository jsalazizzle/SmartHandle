
#include <Transmission.h>
#include <CalendarTime.h>
#include <ErrorLogging.h>
#include <PowerMonitor.h>
#include <TimingMaster.h>
#include <UseProfiling.h>
#include <SystemCore.h>
#include <BusManager.h>
#include <HoverSense.h>

#include "debug.h"

//-------------------------------------------------------------//

extern bool app_timeout_a, app_timeout_b, app_timeout_c;
extern bool local_bus_busy; // I2C or I2S data bus busy
extern bool interface_busy; // LED, Chime or Motor in use
extern bool power_mon_busy; // Power Monitor ADC in use

extern bool is_connected;
extern bool is_advertising;

//-------------------------------------------------------------//
//------------------VIRTUAL-WATCH-DOG-TIMERS-------------------//
//-------------------------------------------------------------//

void SystemCore_TimerHandler(uint8 id)
{
    switch(id)
    {
        case 0xA1:  // Application Timer A
        {
            app_timeout_a = true;
            TimingMaster_ConfigureTimer(0xA1,0);
            NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);
            break;
        }
        case 0xA2:  // Application Timer B
        {
            app_timeout_b = true;
            TimingMaster_ConfigureTimer(0xA2,0);
            NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);            
            break;
        }
        case 0xA3:  // Application Timer C
        {
            app_timeout_c = true;
            TimingMaster_ConfigureTimer(0xA3,0);
            NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);            
            break;
        }
        case 0xBA:  // Power Monitor Timer
        {
//            PowerMonitor_Tick();
            break;
        }
        case 0xEE:  // Use Profiling Timer
        {
//            UseProfiling_Tick();
            break;
        }
        default:    // Bus Manager Timer
        {
            if((id & 0xF0) == 0xC0) 
            {
                BusManager_Tick(id & 0x0F);
            }
            break;
        }
        case 0x0E:  // Hover Sense Timer
        {
//            HoverSense_Tick();
            break;
        }
    }
}
//-------------------------------------------------------------//

void SystemCore_SetDateAndTime(uint8 year, uint8 month, uint8 day,
                               uint8 hour, uint8 minute, uint8 second)
{
    CalendarTime_SetDateAndTime(year,month,day,hour,minute,second);
}
epoch System_Core_GetDateAndTime()
{
    return CalendarTime_GetDateAndTime();
}
//-------------------------------------------------------------//

void SystemCore_SetApplicationTimerA(uint32 period_ms)
{
    TimingMaster_ConfigureTimer(0xA1,period_ms);
}
void SystemCore_SetApplicationTimerB(uint32 period_ms)
{
    TimingMaster_ConfigureTimer(0xA2,period_ms);
}
void SystemCore_SetApplicationTimerC(uint32 period_ms)
{
    TimingMaster_ConfigureTimer(0xA3,period_ms);
}
//-------------------------------------------------------------//

void SystemCore_SetPowerMonitorTimer(uint32 period_ms)
{
    TimingMaster_ConfigureTimer(0xBA,period_ms);
}
void SystemCore_SetUseProfilingTimer(uint32 period_ms)
{
    TimingMaster_ConfigureTimer(0xEE,period_ms);
}
//-------------------------------------------------------------//

void SystemCore_SetBusManagerTimer(uint8 sensor_type, uint32 period_ms)
{
    TimingMaster_ConfigureTimer((0xC0 | sensor_type),period_ms);
}
void SystemCore_SetHoverSenseTimer(uint32 period_ms)
{
    TimingMaster_ConfigureTimer(0x0E,period_ms);
}
//-------------------------------------------------------------//
//---------------------LOW-POWER-TRANSITION--------------------//
//-------------------------------------------------------------//

void SystemCore_TryToSleep()
{
    if(!Cy_SysPm_Cm0IsLowPower())
    {
        Cy_SysPm_EnterLowPowerMode();
    }
    
    cy_en_ble_bless_state_t bleSsState = Cy_BLE_StackGetBleSsState();    
    
    if(bleSsState == CY_BLE_BLESS_STATE_ACTIVE || bleSsState == CY_BLE_BLESS_STATE_ECO_STABLE ||
        local_bus_busy || interface_busy /*|| power_mon_busy*/)
    {
        /*
            Example of logic analyzer use to test result of API call
        */
        cy_en_syspm_status_t apiResult = Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
        if(apiResult != CY_SYSPM_SUCCESS)
        {
            Cy_GPIO_Inv(DB_0_PORT,DB_0_NUM);    // Doesn't work
        }
        else
        {
            Cy_GPIO_Inv(DB_1_PORT,DB_1_NUM);    // Work
        }
    }
    else
    {        
        Cy_BLE_ProcessEvents();
        
        cy_en_syspm_status_t apiResult = Cy_SysPm_DeepSleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
        if(apiResult != CY_SYSPM_SUCCESS)
        {
            Cy_GPIO_Inv(DB_2_PORT,DB_2_NUM);    // Doesn't work
        }
        else
        {
            Cy_GPIO_Inv(DB_3_PORT,DB_3_NUM);    // Work
        }
    }
}
//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void SystemCore_Init()
{
    TimingMaster_Init();
    ADC_Start();
    ADC_StartConvert();
//    CalendarTime_Init();
//    ErrorLogging_Init();
//    PowerMonitor_Init();
//    UseProfiling_Init();
    
    DEBUG_PRINTF("SystemCore_Init 1 \r\n");
    DEBUG_WAIT_UART_TX_COMPLETE();
}
//-------------------------------------------------------------//
