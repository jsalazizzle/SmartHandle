
#include <HoverSense.h>
#include "debug.h"

extern uint8 hover_detected;
//static uint8 initializeCapSenseBaseline = 1;

void HoverSense_Init()
{
    DEBUG_PRINTF("HoverSense_Init\r\n");
    cy_status capSenseApiResult = CapSense_Start();
    
    /* Check if the operation has been successful */
    if (capSenseApiResult== CY_RET_SUCCESS) {
        DEBUG_PRINTF("Success  : Proximity - CapSense initialization\r\n");
    } else {
        DEBUG_PRINTF("Failure! : Proximity - CapSense initialization error\r\n");
    }
     CapSense_ScanAllWidgets(); 
}

void HoverSense_Tick()
{
    
    hover_detected = false;
    if (CapSense_IsBusy() == CapSense_NOT_BUSY) {
		CapSense_ProcessAllWidgets();
        hover_detected = (bool) CapSense_IsProximitySensorActive(CapSense_PROXIMITY0_WDGT_ID,CapSense_PROXIMITY0_SNS0_ID);
        if(hover_detected){
            NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);
        }
        CapSense_ScanAllWidgets();
	}
}
