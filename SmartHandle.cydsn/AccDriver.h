#ifndef ACCDRIVER_H
#define ACCDRIVER_H

//-----------------------------------------//
    
#include <project.h>
#include <stdbool.h>
#include "KinOS.h"
    
//---------------ACC Macros----------------//
    
#define ACC_ADDR 0x1E //  SA0/SDO if Vdd: 0x1D // if gnd: 0x1E
#define ACC_WHO_AM_I_ADDR 0x0F
#define ACC_WHO_AM_I_VAL 0x43
#define ACC_CTRL1 0x20
#define ACC_CTRL2 0x21
#define ACC_CTRL3 0x22
#define ACC_CTRL4 0x23
#define ACC_CTRL5 0x24
#define ACC_STATUS 0x27

#define ACC_OUT_X_L 0x28
#define ACC_OUT_X_H 0x29
#define ACC_OUT_Y_L 0x2A
#define ACC_OUT_Y_H 0x2B
#define ACC_OUT_Z_L 0x2C
#define ACC_OUT_Z_H 0x2D

#define ACC_WAKE_UP_DUR 0x34
#define ACC_WAKE_UP_THS 0x33
#define ACC_WAKE_UP_SRC 0x37

#define ACC_DRDY 0x01
#define ACC_SIG_MOTION_INT2 0x08
#define ACC_FUNC_CTRL 0x3F
#define ACC_FUNC_CK_GATE 0x3D
#define ACC_MODULE_ON 0x20
#define ACC_SIGN_MOT_ON 0x02
#define ACC_SM_THS 0x34
    
//-----------------------------------------//

typedef struct                                          
{                                                       
    uint8  sensor_type;     // Is set to ACC      
    epoch timestamp;        // Timestamp in us    
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
void readAccData(acc_sample);
int32 AccDriver_UpdateSetting(uint8 setting_type, int32 setting_value);

//-----------------------------------------//

#endif /* ACCDRIVER_H */
