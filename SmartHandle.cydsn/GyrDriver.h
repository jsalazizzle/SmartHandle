#ifndef GYRDRIVER_H
#define GYRDRIVER_H

//-----------------------------------------//
    
#include <project.h>
#include <stdbool.h>
    
//-----------------------------------------//
    
void GyrDriver_Init();
bool GyrDriver_OperationDone();

int32 GyrDriver_UpdateSetting(uint8 setting_type, int32 setting_value);

//-----------------------------------------//

#endif /* GYRDRIVER_H */
