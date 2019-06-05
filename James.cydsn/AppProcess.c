
#include <AppProcess.h>
#include <KinOS.h>

#include "debug.h"

#define BT_CONFIG_LIGHT     0x0000
#define BT_CONFIG_ALARM     0x0002
#define BT_REGISTER_DEV     0x0003
#define BT_SET_LIGHT_COLOR  0x0004
#define BT_TIME_SYNC        0x0005

uint8_t reg_number[6] = {6, 5, 4, 3, 2, 1};
int RegSent = 0;


void AppProcess_Start()
{
    DEBUG_PRINTF("AppProcess_Start 1 \r\n");     
    DEBUG_WAIT_UART_TX_COMPLETE();
    
    epoch current_time, prev_time;
    uint8 dt_buffer[7],battery_percentage = 100;
    acc_sample data;
    int16 counts;
    float32 battery_voltage;
    uint32 z;
    uint8 reg_check;
    
    while(true) {
        
        current_time = KinOS_GetDateAndTime();
        if((abs(current_time.second - prev_time.second)) >= 5 && KinOS_IsConnected() && RegSent){
            //KinOS_SendResult(1, &battery_percentage);
            //KinOS_ReadAcc(&data);
            
            counts = ADC_GetResult16(0UL);
            battery_voltage = ADC_CountsTo_Volts(0UL, counts);
            DEBUG_PRINTF("v_bat: %f\r\n", battery_voltage);
            DEBUG_WAIT_UART_TX_COMPLETE();
        
            z = Cy_GPIO_Read(ALS_INT_PORT, ALS_INT_NUM);

            data.x_raw = (int16) battery_percentage;
            prev_time = current_time;
            //DEBUG_PRINTF("x: %#6x\ty: %#6x\tz: %#6x\r\n\n",(uint16) data.x_raw, (uint16) data.y_raw, (uint16) data.z_raw);
            Cy_BLE_BASS_SetCharacteristicValue(CY_BLE_BATTERY_SERVICE_INDEX, CY_BLE_BAS_BATTERY_LEVEL, 1, &battery_percentage);
            //KinOS_SendAcc(&data);
            battery_percentage = (battery_percentage) ? battery_percentage - 3 : 100;
        }
        
        if(KinOS_CheckInbox(7 * sizeof(uint8),(uint8*)&dt_buffer))
        {
            switch(dt_buffer[0])
            {
                case BT_CONFIG_LIGHT:
                    DEBUG_PRINTF("0x00 Received \r\n");
                    KinOS_ConfigureLight(dt_buffer[1], BYPASS , 10, dt_buffer[3]);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_CONFIG_ALARM:
                    DEBUG_PRINTF("0x02 Received \r\n");
                    KinOS_ConfigureChime(dt_buffer[1], dt_buffer[2]);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_REGISTER_DEV:
                    DEBUG_PRINTF("0x03 Received \r\n");
                    uint8 token = 0xFF;
                    
                    if(RegSent == 0) {
                        for(int i = 0; i < 6; i++) {
                            if(dt_buffer[i + 1] != reg_number[i]) {
                                reg_check = 1;
                                break;
                            }
                            reg_check = 2;
                        }
                    
                        Cy_BLE_BASS_SetCharacteristicValue(CY_BLE_BATTERY_SERVICE_INDEX, CY_BLE_BAS_BATTERY_LEVEL, 1, &reg_check);
                    } else if(dt_buffer[2] == 9){
                        RegSent = 1;
                    }
                    
                    
                    KinOS_SendResult(1,&token);
                    DEBUG_WAIT_UART_TX_COMPLETE();
                break;
                    
                case BT_TIME_SYNC:
                    DEBUG_PRINTF("0x04 Received \r\n");
                    KinOS_SetDateAndTime(dt_buffer[1],dt_buffer[2],dt_buffer[3],
                                         dt_buffer[4],dt_buffer[5],dt_buffer[6]);
                    DEBUG_PRINTF("epoch received:   ");
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
