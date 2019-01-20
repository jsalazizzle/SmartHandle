
#include <AppProcess.h>
#include <KinOS.h>
#include <HoverSense.h>

#include "debug.h"

void AppProcess_Start()
{
    DEBUG_PRINTF("AppProcess_Start 1 \r\n");     
    DEBUG_WAIT_UART_TX_COMPLETE();
    
    int pinVal;
    
//    KinOS_ConfigureSensor(ACC, SAMPLE_RATE_PERIOD, -45);
//    KinOS_ConfigureSensor(GYR, SAMPLE_RATE_PERIOD, -10);

    while(true)
    {
        HoverSense_Tick();
        
        pinVal = Cy_GPIO_Read(Pin_Shake_0_PORT,Pin_Shake_0_NUM);
        DEBUG_PRINTF("%.2d:%.2d:%.2d\t",KinOS_GetDateAndTime().hour,KinOS_GetDateAndTime().minute,KinOS_GetDateAndTime().second);
        if(pinVal){
            KinOS_SetupTimerB(5000);
            DEBUG_PRINTF("Update TIMER");
        }
        DEBUG_PRINTF("\t");
        
        uint8 msg;						// sync time
		if (KinOS_CheckInbox(sizeof(uint8), &msg)) {
            DEBUG_PRINTF("%x\t",msg);
			if (msg == 0x02) {
				uint8 dt_buffer[6];
                
				KinOS_CheckInbox(sizeof(dt_buffer), (uint8*)&dt_buffer);
                DEBUG_PRINTF("%d-%d-%d  %d:%d:%d\t",dt_buffer[0], dt_buffer[1], dt_buffer[2],
					dt_buffer[3], dt_buffer[4], dt_buffer[5]);
				KinOS_SetDateAndTime(dt_buffer[0], dt_buffer[1], dt_buffer[2],
					dt_buffer[3], dt_buffer[4], dt_buffer[5]);
				
			}
		}
        DEBUG_PRINTF("\r\n");
        CyDelay(200);
    }
}
