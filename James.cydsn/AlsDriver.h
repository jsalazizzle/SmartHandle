#ifndef ALSDRIVER_H
#define ALSDRIVER_H

//-----------------------------------------//
    
#include <project.h>
#include <stdbool.h>
    
//---------------ALS Macros----------------//
    
#define ALS_ADDR             0x44 //  SA0/SDO if Vdd: 0x1D // if gnd: 0x1E
#define ALS_RESULT           0x00
#define ALS_CONFIG           0x01
#define ALS_INT_LOW_THRES    0x02
#define ALS_INT_HIGH_THRES   0x03
#define ALS_MFR_ID_ADDR      0x7E
#define ALS_MFR_ID_VAL       0x5449
#define ALS_DEV_ID_ADDR      0x7F
#define ALS_DEV_ID_VAL       0x3001
    
#define ALS_RES_MASK         0x1FFF
    
    
//-----------------------------------------//
    
void AlsDriver_Init();
bool AlsDriver_OperationDone();

int32 AlsDriver_UpdateSetting(uint8 setting_type, int32 setting_value);

//-----------------------------------------//

#endif /* ALSDRIVER_H */
