#ifndef USERINTERFACE_H
#define USERINTERFACE_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
    
//-------------------------------------------------------------//

void UserInterface_Init();
void UserInterface_BusySemaphore(bool request);
void UserInterface_ConfigureLight(uint8 color, uint8 pattern, uint8 cycles, uint8 brightness);
void UserInterface_BypassSettings(uint8 color, uint8 brightness);
void UserInterface_ConfigureChime(uint8 pattern, uint8 cycles);
void UserInterface_ConfigureMotor(uint8 pattern, uint8 cycles);

//-------------------------------------------------------------//

#endif /* USERINTERFACE_H */
