
#include <ShakeSense.h>
#include <UserInterface.h>
#include <KinOS.h>

#include "debug.h"

extern bool shake_detected;

static void ShakeHandler()
{
    shake_detected = true;
    NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);
    
    NVIC_ClearPendingIRQ(Shake_IRQ_cfg.intrSrc);
}
void ShakeSense_Init()
{
    Cy_SysInt_Init(&Shake_IRQ_cfg, ShakeHandler);
    NVIC_ClearPendingIRQ(Shake_IRQ_cfg.intrSrc);
    NVIC_EnableIRQ(Shake_IRQ_cfg.intrSrc);
}
//-------------------------------------------------------------//