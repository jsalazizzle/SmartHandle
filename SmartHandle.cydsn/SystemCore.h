#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <KinOS.h>
    
//-------------------------------------------------------------//

void SystemCore_Init();
void SystemCore_TimerHandler(uint8 id);
void SystemCore_SetDateAndTime(uint8 year, uint8 month, uint8 day,
                               uint8 hour, uint8 minute, uint8 second);
epoch System_Core_GetDateAndTime();
void SystemCore_SetApplicationTimerA(uint32 period_ms);
void SystemCore_SetApplicationTimerB(uint32 period_ms);
void SystemCore_SetApplicationTimerC(uint32 period_ms);
void SystemCore_SetPowerMonitorTimer(uint32 period_ms);
void SystemCore_SetUseProfilingTimer(uint32 period_ms);
void SystemCore_SetBusManagerTimer(uint8 sensor_type, uint32 period_ms);
void SystemCore_SetHoverSenseTimer(uint32 period_ms);

void SystemCore_TryToSleep();

//-------------------------------------------------------------//

#endif /* SYSTEMCORE_H */
