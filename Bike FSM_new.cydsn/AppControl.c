
#include <AppControl.h>
#include <KinOS.h>

#include "debug.h"

enum { FSM_1_IDLE, FSM_1_CHECK_MOTION, FSM_1_VERIFY_USER, FSM_1_STOLEN, FSM_1_DAY_MODE, FSM_1_NIGHT_MODE, FSM_1_CRASH };

void AppControlHandler() {
	bool update_done = false;


	static uint8 current_state = FSM_1_IDLE;
	static uint8 next_state = FSM_1_IDLE;

	do  //-----------------------------------------------------//
	{   //-------------------State-Transitions-----------------//

		switch (current_state) {
			case FSM_1_IDLE:
			{
				if (KinOS_PressDetected()) {
					next_state = FSM_1_CHECK_MOTION;
				}
				break;
			}
			case FSM_1_CHECK_MOTION:
			{
				//if (KinOS_CheckTimerA() && !KinOS_CheckTimerB()) {
                if (KinOS_HoverDetected()) {
					next_state = FSM_1_VERIFY_USER;
				} else if(KinOS_CheckTimerA()) {
					next_state = FSM_1_IDLE;
				}
				break;
			}
			case FSM_1_VERIFY_USER:
			{
				if (!KinOS_IsConnected() && !KinOS_IsAdvertising()) {
					next_state = FSM_1_STOLEN;
				} else if (KinOS_IsConnected()) {
					
                    next_state = FSM_1_DAY_MODE;/*
					if (KinOS_GetDateAndTime().hour < 20) {
						next_state = FSM_1_DAY_MODE;
					} else {
						next_state = FSM_1_NIGHT_MODE;
					}*/
				}
				break;
			}
			case FSM_1_STOLEN:
			{
				if (KinOS_IsConnected()) {
					if (KinOS_GetDateAndTime().hour < 20) {
						next_state = FSM_1_DAY_MODE;
					} else {
						next_state = FSM_1_NIGHT_MODE;
					}
				}
                if(KinOS_CheckTimerB()) {
					next_state = FSM_1_IDLE;
				}

				/*if (!KinOS_IsConnected() && !KinOS_IsAdvertising() && !KinOS_PressDetected()) {
					next_state = FSM_1_IDLE;
				}*/
				break;
			}
			case FSM_1_DAY_MODE:
			{
				if (!(KinOS_GetDateAndTime().hour < 20)) {
					next_state = FSM_1_NIGHT_MODE;
				}
				if (KinOS_CheckTimerB()) {
					next_state = FSM_1_IDLE;
				}
                /*
				if (KinOS_PressDetected()) {
					next_state = FSM_1_CRASH;
				}*/
				break;
			}

			case FSM_1_NIGHT_MODE:
			{
				if (KinOS_GetDateAndTime().hour < 20) {
					next_state = FSM_1_DAY_MODE;
				}
				if (!KinOS_CheckTimerB()) {
					next_state = FSM_1_IDLE;
				}/*
				if (KinOS_PressDetected()) {
					next_state = FSM_1_CRASH;
				}*/
				break;
			}

			case FSM_1_CRASH:
			{
				/*if (KinOS_GetDateAndTime().hour < 20 && !KinOS_PressDetected()) {
					next_state = FSM_1_DAY_MODE;
				} else if (!(KinOS_GetDateAndTime().hour < 20) && !KinOS_PressDetected()) {
					next_state = FSM_1_IDLE;
				}
				if (!KinOS_CheckTimerA()) {
					next_state = FSM_1_IDLE;
				}*/
				break;
			}
		}
		//-----------------------------------------------------//
		//------------------Transition-Outputs-----------------//

		switch (current_state) {
			case FSM_1_IDLE:
			{
                DEBUG_PRINTF("FSM_1_IDLE \r\n");
                KinOS_Disconnect();
                switch(next_state)
                {
                    case FSM_1_CHECK_MOTION:
                    {
                        KinOS_SetupTimerA(10000);
                        //KinOS_SetupTimerB(5000);
                        break;
                    }
                }
				break;
			}
			case FSM_1_CHECK_MOTION:
			{
                DEBUG_PRINTF("FSM_1_CHECK_MOTION \r\n");
                switch(next_state)
                {
                    case FSM_1_VERIFY_USER:
                    {
                        KinOS_Advertise(20, 100);		//advertise for 20 sec
				        //Cy_BLE_ProcessEvents();
                        break;
                    }
                }
				break;
			}
			case FSM_1_VERIFY_USER:
			{
                DEBUG_PRINTF("FSM_1_VERIFY_USER \r\n");
			    switch(next_state)
                {
                    case FSM_1_STOLEN:
                    {
                        KinOS_Advertise(300, 100);		//advertise for 5 min
				        //Cy_BLE_ProcessEvents();
                        break;
                    }
                }
				break;
			}
			case FSM_1_STOLEN:
			{
                DEBUG_PRINTF("FSM_1_STOLEN \r\n");
				break;
			}
			case FSM_1_DAY_MODE:
			{
                DEBUG_PRINTF("FSM_1_DAY_MODE \r\n");
				//KinOS_ConfigureSensor(ACC, SAMPLE_RATE_PERIOD, -50);
                break;
			}
			case FSM_1_NIGHT_MODE:
			{
                DEBUG_PRINTF("FSM_1_NIGHT_MODE \r\n");
				//KinOS_ConfigureSensor(ACC, SAMPLE_RATE_PERIOD, -50);
                break;
			}
            case FSM_1_CRASH:
			{
                DEBUG_PRINTF("FSM_1_CRASH \r\n");
                break;
			}

		}
		//-----------------------------------------------------//
		//-----------------------------------------------------//

		update_done = (current_state == next_state);
		current_state = next_state; // Update state
	} while (!update_done);
	NVIC_ClearPendingIRQ(AppControl_IRQ_cfg.intrSrc);
}
