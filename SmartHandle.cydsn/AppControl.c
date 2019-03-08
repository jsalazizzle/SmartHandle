
#include <AppControl.h>
#include <KinOS.h>

#include "debug.h"

enum{   FSM_INITIALIZE, 
        FSM_IDLE, 
        FSM_CHECK_MOTION, 
        FSM_VERIFY_USER, 
        FSM_STOLEN,
        FSM_DAY,
        FSM_NIGHT,
        FSM_RIDE
    };

// Control Parameters
// NIGHT DAY
uint16 morningThreshold = 7;
uint16 nightThreshold = 20;
uint32 rideNightCheck_ms = 60000;
// VERIFY
uint16 verifyAdvertise_s = 30;
uint8 verifyLightCycles = 8;
// STOLEN
uint16 stolenAdvertise_s = 30;
uint8 stolenLightCycles = 15;

void AppControlHandler()
{
    static bool motion_latch = false;
    
    bool update_done = false;
    static uint8 current_state = FSM_INITIALIZE;
    static uint8 next_state    = FSM_INITIALIZE;
        
    do  //-----------------------------------------------------//
    {   //-------------------State-Transitions-----------------//
        
        switch(current_state)
        {
            case FSM_INITIALIZE: 
            {
                DEBUG_PRINTF("FSM_INITIALIZE\r\n"); 
                DEBUG_WAIT_UART_TX_COMPLETE();
                KinOS_Advertise(30,50);
                next_state = FSM_IDLE;
                break;
            }
            case FSM_IDLE:
            {
                DEBUG_PRINTF("FSM_IDLE\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                if (KinOS_ShakeDetected()) 
                {
                    next_state = FSM_CHECK_MOTION;
                }
                KinOS_Advertise(verifyAdvertise_s,50);
                break;
            }
            case FSM_CHECK_MOTION:
            {
                DEBUG_PRINTF("FSM_CHECK_MOTION\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                // latch the first 2 seconds
                if (KinOS_CheckTimerB()) 
                {
                    motion_latch = false;
                }
                
                if (motion_latch)
                {
                    KinOS_ShakeDetected();
                }
                else if (KinOS_CheckTimerA())
                {
                    if (KinOS_ShakeDetected())
                    {
                        next_state = FSM_VERIFY_USER;
                    }
                    else
                    {
                        next_state = FSM_IDLE;
                    }
                }
                break;
            }
            case FSM_VERIFY_USER:
            {
                DEBUG_PRINTF("FSM_VERIFY_USER\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                if (KinOS_IsConnected()) 
                {
                    next_state = FSM_RIDE;
                }
                else if (!KinOS_IsAdvertising())
                {
                    next_state = FSM_STOLEN;
                }
                break;
            }
            case FSM_STOLEN:
            {
                DEBUG_PRINTF("FSM_STOLEN\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                if (KinOS_IsConnected())
                {
                    next_state = FSM_RIDE;
                }    
                else if (!KinOS_IsAdvertising())
                {
                    if (KinOS_ShakeDetected())
                    {
                        next_state = FSM_STOLEN;
                    }
                    else
                    {
                        next_state = FSM_IDLE;
                    }
                }
                break;
            }
            case FSM_RIDE:
            {
                DEBUG_PRINTF("FSM_RIDE\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                if (KinOS_CheckTimerA())
                {
                    if (KinOS_ShakeDetected())
                    {
                        epoch dateAndTime = KinOS_GetDateAndTime();
                        if (dateAndTime.hour > morningThreshold && 
                            dateAndTime.hour < nightThreshold)
                        {
                            next_state = FSM_DAY;
                        }
                        else
                        {
                            next_state = FSM_NIGHT;
                        }
                    }
                    else
                    {
                        next_state = FSM_IDLE;
                    }
                }
                break;
            }
            case FSM_DAY:
            {
                DEBUG_PRINTF("FSM_DAY\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                next_state = FSM_RIDE;
                break;
            }
            case FSM_NIGHT:
            {
                DEBUG_PRINTF("FSM_NIGHT\r\n");
                DEBUG_WAIT_UART_TX_COMPLETE();
                next_state = FSM_RIDE;
                break;
            }
        }
        //-----------------------------------------------------//
        //------------------Transition-Outputs-----------------//
        
        switch(current_state)
        {
            case FSM_INITIALIZE: 
            {
                break;
            }
            case FSM_IDLE:
            {
                switch(next_state)
                {
                    case FSM_CHECK_MOTION:
                    {
                        KinOS_SetupTimerA(10000);
                        KinOS_SetupTimerB(4000);
                        motion_latch = true;
                        break;
                    }
                }
                break;
            }
            case FSM_CHECK_MOTION:
            {
                switch(next_state)
                {
                    case FSM_VERIFY_USER:
                    {
                        KinOS_ConfigureLight(BLUE,BOUNCE,verifyLightCycles,255);
                        KinOS_Advertise(verifyAdvertise_s,50);
                        break;
                    }
                }
                break;
            }
            case FSM_VERIFY_USER:
            {
                switch(next_state)
                {
                    case FSM_STOLEN:
                    {
                        KinOS_ConfigureChime(BOOBOO,stolenLightCycles);
                        KinOS_ConfigureLight(RED,SMOOTH,stolenLightCycles,255);
                        KinOS_Advertise(stolenAdvertise_s,50);
                        break;
                    }
                    case FSM_RIDE:
                    {
                        KinOS_SetupTimerA(5);
                        break;
                    }
                }
                break;
            }
            case FSM_STOLEN:
            {
                switch(next_state)
                {
                    case FSM_IDLE:
                    {
                        KinOS_ConfigureChime(BOOBOO,0);
                        KinOS_ConfigureLight(WHITE,SMOOTH,0,0);
                        break;
                    }
                    case FSM_STOLEN:
                    {
                        KinOS_ConfigureChime(BOOBOO,rideNightCheck_ms);
                        KinOS_ConfigureLight(RED,SMOOTH,stolenLightCycles,255);
                        KinOS_Advertise(stolenAdvertise_s,50);
                        break;
                    }
                    case FSM_RIDE:
                    {
                        KinOS_SetupTimerA(5);
                        break;
                    }
                }
                break;
            }
            case FSM_RIDE:
            {
                switch(next_state)
                {
                    case FSM_DAY:
                    {
                        KinOS_ConfigureLight(WHITE,BYPASS,0,0);
                        break;
                    }
                    case FSM_NIGHT:
                    {
                        KinOS_ConfigureLight(WHITE,BYPASS,30,255);
                        KinOS_BypassSettings(WHITE,255);
                        break;
                    }
                    case FSM_IDLE:
                    {
                        KinOS_ConfigureLight(WHITE,BYPASS,0,0);
                        KinOS_Disconnect();
                        break;
                    }
                }
                break;
            }
            case FSM_DAY:
            {
                switch(next_state)
                {
                    case FSM_RIDE:
                    {
                        KinOS_SetupTimerA(rideNightCheck_ms);
                        break;
                    }
                }
                break;
            }
            case FSM_NIGHT:
            {
                switch(next_state)
                {
                    case FSM_RIDE:
                    {
                        KinOS_SetupTimerA(rideNightCheck_ms);
                        break;
                    }
                }
                break;
            }
        }
        //-----------------------------------------------------//
        //-----------------------------------------------------//
        
        update_done = (current_state == next_state);
        current_state = next_state; // Update state
    }
    while(!update_done);
    NVIC_ClearPendingIRQ(AppControl_IRQ_cfg.intrSrc);
}
