
#include <KinOS.h>

#include <SystemCore.h>
#include <BusManager.h>
#include <Transmission.h>
#include <UserInterface.h>

#include "AccDriver.h"

#include <AppControl.h>
#include <AppProcess.h>

#include "debug.h"

//-------------------------------------------------------------//

bool app_timeout_a, app_timeout_b, app_timeout_c;

extern epoch  date_time;        // The date and time
extern uint16 battery_voltage;  // Battery voltage in mV
extern  bool  is_advertising;   // BLE advertising
extern  bool  is_connected;     // Client connected
extern  bool  is_enabled;       // Notifications on

extern  int8  press_detected;   // Which button pressed
extern  bool  tap2x_detected;   // Double tap detected
extern  bool  hover_detected;   // CapSense hover detected
extern  bool  shake_detected;   // Shake detected

//-------------------------------------------------------------//
//--------------------SYSTEM-CORE-FUNCTIONS--------------------//
//-------------------------------------------------------------//

void KinOS_Boot()
{
    UART_DEBUG_START();
    DEBUG_PRINTF("\r\n");
    DEBUG_WAIT_UART_TX_COMPLETE();
    DEBUG_PRINTF("KinOS_Boot 1 \r\n");
    DEBUG_WAIT_UART_TX_COMPLETE();
    
    __enable_irq(); // Start the event driven operating system and enable global interrupts
    
    SystemCore_Init(); // Setup watchdog, ADC, flash manager etc
    BusManager_Init();  // Setup data buses, acc and data buffer
    Transmission_Init(); // Setup bluetooth and send buffer
    UserInterface_Init(); // Setup light, chime, motor feedback
    
    //KinOS_Advertise(60,50);
    
    //KinOS_ConfigureLight(GREEN,ZIGZAG,25,100);
    
    CyDelay(1000); // Wait for subsystems to finish initialization
    
    Cy_SysInt_Init(&AppControl_IRQ_cfg, AppControlHandler); // State machine IRQ
    NVIC_ClearPendingIRQ(AppControl_IRQ_cfg.intrSrc);
    NVIC_EnableIRQ(AppControl_IRQ_cfg.intrSrc);
    NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc); // Trigger AppControl state machine
    
    AppProcess_Start(); // Start the application main process loop
}
uint16 KinOS_BatteryVoltage()
{
    return battery_voltage; // Updated in SystemCore.c
}
void KinOS_SetDateAndTime(uint8 year, uint8 month, uint8 day,
                          uint8 hour, uint8 minute, uint8 second)
{
    SystemCore_SetDateAndTime(year,month,day,hour,minute,second);
}
epoch KinOS_GetDateAndTime()
{
    return System_Core_GetDateAndTime();
    
}
//-------------------------------------------------------------//

void KinOS_SetupTimerA(uint32 timeout_ms)
{
    SystemCore_SetApplicationTimerA(timeout_ms);
}
void KinOS_SetupTimerB(uint32 timeout_ms)
{
    SystemCore_SetApplicationTimerB(timeout_ms);
}
void KinOS_SetupTimerC(uint32 timeout_ms)
{
    SystemCore_SetApplicationTimerC(timeout_ms);
}
//-------------------------------------------------------------//

bool KinOS_CheckTimerA()
{
    bool timeout = app_timeout_a;
    app_timeout_a = false;  // Clear on read
    return timeout;  // Updated in SystemCore.c
}
bool KinOS_CheckTimerB()
{
    bool timeout = app_timeout_b;
    app_timeout_b = false;  // Clear on read
    return timeout;  // Updated in SystemCore.c
}
bool KinOS_CheckTimerC()
{
    bool timeout = app_timeout_c;
    app_timeout_c = false;  // Clear on read
    return timeout;  // Updated in SystemCore.c
}
//-------------------------------------------------------------//
//--------------------BUS-MANAGER-FUNCTIONS--------------------//
//-------------------------------------------------------------//

void KinOS_ReadAcc(acc_sample* sample)
{
    return readAccData(sample);
}


bool KinOS_ReadSample(uint8 *data)
{
    static uint8* rsample_ptr;
    
    uint16 slot = 0;
    slot = DataBuffer_QueryNextJob();
    switch(slot)
    {            
        case GYR20SLOT:
        {
            static struct dGyr20Slot rsample_gyr;
            rsample_ptr = (uint8*) &rsample_gyr;
            gyr_sample* gyr_sample_ptr = (gyr_sample*) data;
            if(DataBuffer_OpenReadSlot((uint8**) &rsample_ptr, GYR20SLOT, sizeof(struct dGyr20Slot)))
            {                
                DataBuffer_CloseReadSlot((uint8**)&rsample_ptr,GYR20SLOT);                
            }
            gyr_sample_ptr->sensor_type = GYR;
            gyr_sample_ptr->x_numerator = ((uint16) rsample_gyr.x_msb << 8) | rsample_gyr.x_lsb;
            gyr_sample_ptr->y_numerator = ((uint16) rsample_gyr.y_msb << 8) | rsample_gyr.y_lsb;
            gyr_sample_ptr->z_numerator = ((uint16) rsample_gyr.z_msb << 8) | rsample_gyr.z_lsb; 
            gyr_sample_ptr->denominator = denominators[GYR20SLOT];
            break;
        }
        case ACC1ESLOT:
        {
            static struct dAcc1ESlot rsample_acc;
            rsample_ptr = (uint8*) &rsample_acc;
            acc_sample* acc_sample_ptr = (acc_sample*) data;
            if(DataBuffer_OpenReadSlot((uint8**) &rsample_ptr, ACC1ESLOT, sizeof(struct dAcc1ESlot)))
            {
                DataBuffer_CloseReadSlot((uint8**)&rsample_ptr,ACC1ESLOT);                
            }             
            acc_sample_ptr->sensor_type = ACC;
            acc_sample_ptr->x_raw = rsample_acc.x_raw;
            acc_sample_ptr->y_raw = rsample_acc.y_raw;
            acc_sample_ptr->z_raw = rsample_acc.z_raw;
            acc_sample_ptr->denominator = denominators[ACC1ESLOT];
            acc_sample_ptr->numerator = numerators[ACC1ESLOT];
            break;
        }
        default:
        {
            data[0] = NONE;
//            SystemCore_TryToSleep();
            return false;
        }
    }
    return true;
}
bool KinOS_ConfigureSensor(uint8 sensor_type, uint8 setting_type, int32 setting_value)
{
    return BusManager_UpdateSetting(sensor_type,setting_type,setting_value);
}
//-------------------------------------------------------------//
//--------------------TRANSMISSION-FUNCTIONS-------------------//
//-------------------------------------------------------------//

bool KinOS_IsAdvertising()
{
    return is_advertising;
}
bool KinOS_IsConnected()
{
    return is_connected;
}
//-------------------------------------------------------------//

bool KinOS_Advertise(uint16 timeout_s, uint16 interval_ms)
{
    return Transmission_Advertise(timeout_s,interval_ms);
}
bool KinOS_Disconnect()
{
    return Transmission_Disconnect();
}
bool KinOS_CheckInbox(uint32 num_bytes, uint8 *data)
{
    return Transmission_CheckInbox(num_bytes,data);
}
bool KinOS_SendResult(uint32 num_bytes, uint8 *data)
{
   return Transmission_SendResult(num_bytes,data);
}
void KinOS_SendAcc(acc_sample* acc_data)
{
    return Transmission_SendAcc(acc_data);
}

//-------------------------------------------------------------//
//----------------USER-INTERFACE-INPUT-FUNCTIONS---------------//
//-------------------------------------------------------------//

uint8 KinOS_PressDetected()
{
    bool pressed = press_detected;
    press_detected = false;  // Clear on read
    return pressed;  // Updated in PressSense.c
}
bool KinOS_Tap2xDetected()
{
    bool tapped = tap2x_detected;
    tap2x_detected = false;  // Clear on read
    return tapped;  // Updated in Tap2xSense.c
}
bool KinOS_HoverDetected()
{
    bool hovered = hover_detected;
    hover_detected = false;  // Clear on read
    return hovered;  // Updated in HoverSense.c
}
bool KinOS_ShakeDetected()
{
    bool shaked = shake_detected;
    shake_detected = false;  // Clear on read
    return shaked;  // Updated in ShakeSense.c
}
//-------------------------------------------------------------//
//---------------USER-INTERFACE-OUTPUT-FUNCTIONS---------------//
//-------------------------------------------------------------//

void KinOS_ConfigureLight(uint8 color, uint8 pattern, uint8 cycles, uint8 brightness)
{
    UserInterface_ConfigureLight(color,pattern,cycles,brightness);
}
void KinOS_BypassSettings(uint8 color, uint8 brightness)
{
    UserInterface_BypassSettings(color,brightness);
}
void KinOS_ConfigureChime(uint8 pattern, uint8 cycles)
{
    UserInterface_ConfigureChime(pattern,cycles);
}
void KinOS_ConfigureMotor(uint8 pattern, uint8 cycles)
{
    UserInterface_ConfigureMotor(pattern,cycles);
}
//-------------------------------------------------------------//
