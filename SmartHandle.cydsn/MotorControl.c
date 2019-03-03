
#include <MotorControl.h>
#include <UserInterface.h>
#include <KinOS.h>

//-------------------------------------------------------------//

static const uint8 pattern_map[3][20] = 
{
    // WakeUp pattern
    {64,127,255,255,255,255,255,127,64,0,0,64,127,255,
     255,255,255,255,127,64},
    
    // Recoil pattern
    {64,127,255,255,127,64,0,0,64,127,255,255,255,255,
     255,255,255,255,127,64},
    
    // Hummer pattern
    {35,50,65,80,95,110,125,140,155,170,185,200,215,
     230,245,255,255,255,127,64}
};

//-------------------------------------------------------------//

static uint8 pattern = WAKEUP;
static uint8 cycles = 1;

static uint8 next_pattern = WAKEUP;

//-------------------------------------------------------------//
//--------------------TIMING-COORDINATION----------------------//
//-------------------------------------------------------------//

static void MotorTimerHandler()
{
    static uint8 index = 0;

    MotorTimer_ClearInterrupt(MotorTimer_GetInterruptMask());
    
    // Iterate through each element of the pattern map
    if(index == 20)
    {
        if(--cycles == 0)
        {
            MotorTimer_TriggerStop();
            MotorTimer_Disable();
            MotorOutput_SetCompare0(0);
            MotorOutput_Disable();
            
            UserInterface_BusySemaphore(false);
        }
        index = 0;
        pattern = next_pattern;
    }
    else
    {
        MotorTimer_Start();
        MotorOutput_Start();
        MotorOutput_SetCompare0(pattern_map[pattern][index]);
        
        index = index + 1;
    }
    
    NVIC_ClearPendingIRQ(MotorTimer_IRQ_cfg.intrSrc);
}
//-------------------------------------------------------------//
//-----------------INITIALIZE-MOTOR-CONTROL--------------------//
//-------------------------------------------------------------//

void MotorControl_Init()
{
    cy_en_sysint_status_t intrReturnValue = Cy_SysInt_Init(&MotorTimer_IRQ_cfg, MotorTimerHandler);
    if(intrReturnValue == CY_SYSINT_SUCCESS)
    {
        MotorTimer_ClearInterrupt(MotorTimer_GetInterruptMask());
        NVIC_ClearPendingIRQ(MotorTimer_IRQ_cfg.intrSrc);
        NVIC_EnableIRQ(MotorTimer_IRQ_cfg.intrSrc);
        NVIC_SetPendingIRQ(MotorTimer_IRQ_cfg.intrSrc); // Necessary?
         
        MotorTimer_Start();
        MotorOutput_Start();
        MotorOutput_SetCompare0(0);
        MotorOutput_Disable();
    }
    else
    {
        // ** Throw error
    }
}
//-------------------------------------------------------------//
//--------------------SET-MOTOR-PARAMETERS---------------------//
//-------------------------------------------------------------//

void MotorControl_ConfigureMotor(uint8 new_pattern, uint8 new_cycles)
{
    next_pattern = new_pattern;

    // Turn on motor
    if(cycles == 0 && new_cycles > 0)
    {
        UserInterface_BusySemaphore(true);
        
        pattern = new_pattern;
        cycles = new_cycles;
        
        MotorOutput_Start();
        MotorTimer_Start();
    }
    // Turn off motor
    else if(cycles > 0 && new_cycles == 0)
    {
        cycles = 1;
    }
    // If motor on update motor
    else if(cycles > 0 && new_cycles > 0)
    {
        cycles = new_cycles + 1;
    }
}
//-------------------------------------------------------------//
