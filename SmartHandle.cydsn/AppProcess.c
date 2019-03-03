
#include <AppProcess.h>
#include <KinOS.h>

#include "debug.h"

#define BT_CONFIG_LIGHT     0x0001
#define BT_CONFIG_ALARM     0x0002
#define BT_REGISTER_DEV     0x0003
#define BT_SET_LIGHT_COLOR  0x0004
#define BT_TIME_SYNC        0x0005


void AppProcess_Start()
{
    DEBUG_PRINTF("AppProcess_Start 1 \r\n");     
    DEBUG_WAIT_UART_TX_COMPLETE();
    
    uint8 *sample_data;
    sample_data = (uint8*) malloc(100);
    int prev_x, prev_y, prev_z;
    float sample_acc_raw_x, sample_acc_raw_y, sample_acc_raw_z;
    
    DEBUG_PRINTF("Configuring Sensor... ");     
    DEBUG_WAIT_UART_TX_COMPLETE();
//    KinOS_ConfigureSensor(ACC, SAMPLE_RATE_PERIOD, -45);
//    KinOS_ConfigureSensor(GYR, SAMPLE_RATE_PERIOD, -10);
    DEBUG_PRINTF("Finished \r\n");     
    DEBUG_WAIT_UART_TX_COMPLETE();
    
    /* NOTE:
     *
     * Service UUID = 0x185E
     * 
     * Inbound BT Characteristic:
     *      Handle = 0x0012
     *      UUID   = 0x7C1B
     * 
     * Outbound BT Characteristic:
     *      Handle = 0x0014
     *      UUID   = 0xB6DB
     *
     *
     * TODO:
     * 
     * Increase packet size to 6 bytes to allow to set date (not that it's necessary)
     * Can remove set light color command -> use configure light command instead
     * Maybe add command to send battery voltage?
     * Maybe remove hardware identification command?
     */
    
    
    uint8 msg;
    while(true) {
        if(KinOS_CheckInbox(sizeof(uint8),&msg))
        {
            uint8 dt_buffer[6];
            KinOS_CheckInbox(sizeof(dt_buffer),(uint8*)&dt_buffer);
            switch(msg)
            {
                case BT_CONFIG_LIGHT:
                    DEBUG_PRINTF("0x01 Recieved \r\n");
                    KinOS_ConfigureLight(dt_buffer[0], dt_buffer[1], dt_buffer[2], dt_buffer[3]);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_CONFIG_ALARM:
                    DEBUG_PRINTF("0x02 Recieved \r\n");
                    KinOS_ConfigureChime(dt_buffer[0], dt_buffer[1]);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_REGISTER_DEV:
                    DEBUG_PRINTF("0x03 Recieved \r\n");
                    uint8 token = 0xFF;
                    KinOS_SendResult(1,&token);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_SET_LIGHT_COLOR: //unnecessary
                    DEBUG_PRINTF("0x04 Recieved \r\n");
                    KinOS_ConfigureLight(dt_buffer[0], dt_buffer[1], dt_buffer[2], dt_buffer[3]);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_TIME_SYNC:
                    DEBUG_PRINTF("0x05 Recieved \r\n");
                    KinOS_SetDateAndTime(dt_buffer[0],dt_buffer[1],dt_buffer[2],
                                         dt_buffer[3],dt_buffer[4],dt_buffer[5]);
                    DEBUG_PRINTF("epoch recieved:   ");
                    DEBUG_PRINTF("year:     %d\r\n",dt_buffer[0]);
                    DEBUG_PRINTF("                  month:    %d\r\n",dt_buffer[1]);
                    DEBUG_PRINTF("                  day:      %d\r\n",dt_buffer[2]);
                    DEBUG_PRINTF("                  hour:     %d\r\n",dt_buffer[3]); 
                    DEBUG_PRINTF("                  minute:   %d\r\n",dt_buffer[4]);
                    DEBUG_PRINTF("                  second:   %d\r\n",dt_buffer[5]);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
            }
        }
    }
}
