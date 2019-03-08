#ifndef BUSMANAGER_H
#define BUSMANAGER_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <stdlib.h>
    
#include <DataBuffer.h>
    
//-------------------------------------------------------------//

void BusManager_Init();
bool BusManager_UpdateSetting(uint8 sensor_type, uint8 setting_type, int32 setting_value);
void BusManager_Tick(uint8 sensor_type);

//-------------------------------------------------------------//

#endif /* BUSMANAGER_H */
