
#include <PressSense.h>
#include <UserInterface.h>
#include <KinOS.h>

#include "debug.h"

extern bool press_detected;

static void Press1Handler()
{
    Cy_GPIO_ClearInterrupt(Press1_PORT, Press1_NUM);
    
    press_detected = true;
    NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);
    
    NVIC_ClearPendingIRQ(Press1_IRQ_cfg.intrSrc);
}
void PressSense_Init()
{
    Cy_SysInt_Init(&Press1_IRQ_cfg, Press1Handler);        
    Cy_GPIO_ClearInterrupt(Press1_PORT, Press1_NUM);
    NVIC_ClearPendingIRQ(Press1_IRQ_cfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)Press1_IRQ_cfg.intrSrc);
}
//-------------------------------------------------------------//