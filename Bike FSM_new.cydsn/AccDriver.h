#ifndef ACCDRIVER_H
#define ACCDRIVER_H

//-----------------------------------------//
    
#include <project.h>
#include <stdbool.h>
    
//-----------------------------------------//

typedef struct                                          
{                                                       
    uint8  sensor_type;     // Is set to ACC      
    uint64 timestamp;       // Timestamp in us    
    int16  x_raw;           // Raw x-axis         
    int16  y_raw;           // Raw y-axis         
    int16  z_raw;           // Raw z-axis         
    uint32 denominator;     // Denominator all         
}  
acc_struct;
    
enum Settings
{ 
    ACC_1E_RATE_800_HZ,    // Sampling rate 800 Hz
    ACC_1E_RATE_400_HZ,    // Sampling rate 400 Hz
    ACC_1E_RATE_200_HZ,    // Sampling rate 200 Hz
    ACC_1E_RATE_100_HZ,    // Sampling rate 100 Hz
    ACC_1E_RATE_50_HZ,     // Sampling rate 50 Hz
    ACC_1E_RATE_25_HZ,     // Sampling rate 25 Hz
    ACC_1E_RATE_12_5_HZ,   // Sampling rate 12.5 Hz
    ACC_1E_RATE_1_HZ,      // Sampling rate 1 Hz
    ACC_1E_OFF             // Sensor off
};     
    
    
void AccDriver_Init();
bool AccDriver_OperationDone();

int32 AccDriver_UpdateSetting(uint8 setting_type, int32 setting_value);

//-----------------------------------------//

#endif /* ACCDRIVER_H */
