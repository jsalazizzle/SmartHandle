
#include <AppProcess.h>
#include <KinOS.h>

#include "debug.h"

void AppProcess_Start() {
	DEBUG_PRINTF("AppProcess_Start 1 \r\n");
	DEBUG_WAIT_UART_TX_COMPLETE();

    uint8_t  currentProxData = 0u;

    CapSense_ScanAllWidgets();
	while (true) {
		/*if (CapSense_IsBusy() == CapSense_NOT_BUSY) {
			CapSense_ProcessAllWidgets();
            currentProxData = CapSense_IsProximitySensorActive(CapSense_PROXIMITY0_WDGT_ID,CapSense_PROXIMITY0_SNS0_ID);
            CapSense_ScanAllWidgets();
		}*/
        //DEBUG_PRINTF("currentProxData: %d \r\n",currentProxData);
        CyDelay(50);
    }
}
