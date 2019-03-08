
#include <UserInterface.h>
#include <KinOS.h>

#include <PressSense.h>
#include <Tap2xSense.h>
#include <HoverSense.h>
#include <ShakeSense.h>
#include <MotorControl.h>
#include <ChimeControl.h>
#include <LightControl.h>

#include "debug.h"

//-------------------------------------------------------------//

bool interface_busy = true;  // Global to SystemCore.c
bool press_detected = false;  // Global to KinOS.c/PressSense.c
bool tap2x_detected = false;  // Global to KinOS.c/TapTapSense.c
bool hover_detected = false;  // Global to KinOS.c/HoverSense.c
bool shake_detected = false;  // Global to KinOS.c/ShakeSense.c

//-------------------------------------------------------------//
//----------------------RESOURCE-TRACKING----------------------//
//-------------------------------------------------------------//

void UserInterface_BusySemaphore(bool request)
{
    static uint8 users = 3;
    
    if(request) users++;
    else users--;
    
    interface_busy = (users > 0);
}
//-------------------------------------------------------------//
//----------------------INTERFACE-CONTROLS---------------------//
//-------------------------------------------------------------//

void UserInterface_ConfigureLight(uint8 color, uint8 pattern, uint8 cycles, uint8 brightness)
{
    LightControl_ConfigureLight(color,pattern,cycles,brightness);
}
void UserInterface_BypassSettings(uint8 color, uint8 brightness)
{
    LightControl_BypassSettings(color,brightness);
}
void UserInterface_ConfigureChime(uint8 pattern, uint8 cycles)
{
    ChimeControl_ConfigureChime(pattern,cycles);
}
void UserInterface_ConfigureMotor(uint8 pattern, uint8 cycles)
{
    MotorControl_ConfigureMotor(pattern,cycles);
}
//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void UserInterface_Init()
{
//    PressSense_Init();
//    Tap2xSense_Init();
    HoverSense_Init();
 //   ShakeSense_Init();
    
 //   LightControl_Init();
 //   ChimeControl_Init();
  //  MotorControl_Init();
    
    DEBUG_PRINTF("UserInterface_Init 1 \r\n");
    DEBUG_WAIT_UART_TX_COMPLETE();
}
//-------------------------------------------------------------//
