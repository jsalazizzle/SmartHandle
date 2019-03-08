#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <math.h>

//-------------------------------------------------------------//

void LightControl_Init();
void LightControl_ConfigureLight(uint8 light_color, uint8 light_pattern, uint8 cycles, uint8 brightness);
void LightControl_BypassSettings(uint8 light_color, uint8 light_brightness);

//-------------------------------------------------------------//

#endif /* LIGHTCONTROL_H */