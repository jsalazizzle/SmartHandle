#ifndef CHIMECONTROL_H
#define CHIMECONTROL_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>

//-------------------------------------------------------------//

void ChimeControl_Init();
void ChimeControl_ConfigureChime(uint8 pattern, uint8 cycles);

//-------------------------------------------------------------//

#endif /* CHIMECONTROL_H */
