#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>

//-------------------------------------------------------------//

void MotorControl_Init();
void MotorControl_ConfigureMotor(uint8 pattern, uint8 cycles);

//-------------------------------------------------------------//

#endif /* MOTORCONTROL_H */
