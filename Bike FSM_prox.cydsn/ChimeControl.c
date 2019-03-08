
#include <ChimeControl.h>
#include <UserInterface.h>
#include <KinOS.h>

// +-----------------------------------------------+
// |              Freq / Timer Period              |
// |-------------+---------+-------------+---------|
// |  14.00 kHz  |    72   |  14.50 kHz  |    70   |
// |  13.00 kHz  |    76   |  13.50 kHz  |    74   |
// |  12.00 kHz  |    82   |  12.50 kHz  |    80   |
// |  11.00 kHz  |    90   |  11.50 kHz  |    88   |
// |  10.00 kHz  |   100   |  10.50 kHz  |    96   |
// |   9.00 kHz  |   110   |   9.50 kHz  |   106   |
// |   8.00 kHz  |   126   |   8.50 kHz  |   118   |
// |   7.00 kHz  |   142   |   7.50 kHz  |   132   |
// |   6.00 kHz  |   166   |   6.50 kHz  |   154   |
// |   5.00 kHz  |   200   |   5.50 kHz  |   180   |
// |   4.00 kHz  |   250   |   4.50 kHz  |   222   |
// |   3.00 kHz  |   332   |   3.50 kHz  |   286   |
// +-----------------------------------------------+      

//-------------------------------------------------------------//

static const uint16 pattern_map[3][40] = 
{
    // Tweets pattern
    {250,200,166,142,126,110,100,90,82,76,76,82,90,
     100,110,126,142,166,200,250,250,200,166,142,
     126,110,100,90,82,76,76,82,90,100,110,126,142,
     166,200,250},
   
    // Cyborg pattern
    {110,110,110,72,72,72,110,110,110,332,332,332,
     110,110,110,72,72,72,110,110,110,110,110,72,
     72,72,110,110,110,332,332,332,110,110,110,72,
     72,72,110,110},
    
    // BooBoo pattern
    {82,332,126,100,82,250,110,76,142,90,76,90,142,
     82,110,76,200,100,82,100,82,332,126,100,82,250,
     110,76,142,90,76,90,142,82,110,76,200,100,82,100}
};

//-------------------------------------------------------------//

static uint8 pattern = TWEETS;
static uint8 cycles = 1;

static uint8 next_pattern = TWEETS;

//-------------------------------------------------------------//
//--------------------TIMING-COORDINATION----------------------//
//-------------------------------------------------------------//

static void ChimeTimerHandler()
{
    static uint8 index = 0;
    
    ChimeTimer_ClearInterrupt(ChimeTimer_GetInterruptMask());

    // Iterate through each element of the pattern map
    if(index == 40)
    {
        if(--cycles == 0)
        {
//            ChimeTimer_TriggerStop(); // Necessary?
            ChimeTimer_Disable();
            ChimeOutput_SetCompare0(0);
            ChimeOutput_Disable();
            
            UserInterface_BusySemaphore(false);
        }
        index = 0;
        pattern = next_pattern;
    }
    else 
    {
        ChimeTimer_Start();
        ChimeOutput_Start();
        ChimeOutput_SetPeriod0(pattern_map[pattern][index]);
        ChimeOutput_SetCompare0((pattern_map[pattern][index])/2);
        ChimeOutput_SetCounter(0);
        
        index = index + 1;
    }
    
    NVIC_ClearPendingIRQ(ChimeTimer_IRQ_cfg.intrSrc);
}
//-------------------------------------------------------------//
//-----------------INITIALIZE-CHIME-CONTROL--------------------//
//-------------------------------------------------------------//

void ChimeControl_Init()
{
    cy_en_sysint_status_t intrReturnValue = Cy_SysInt_Init(&ChimeTimer_IRQ_cfg, ChimeTimerHandler);
    if(intrReturnValue == CY_SYSINT_SUCCESS)
    {
        ChimeTimer_ClearInterrupt(ChimeTimer_GetInterruptMask());
        NVIC_ClearPendingIRQ(ChimeTimer_IRQ_cfg.intrSrc);
        NVIC_EnableIRQ(ChimeTimer_IRQ_cfg.intrSrc);
        NVIC_SetPendingIRQ(ChimeTimer_IRQ_cfg.intrSrc); // Necessary?
        
        ChimeTimer_Start();
        ChimeOutput_Start();
        ChimeOutput_SetCompare0(0);
        ChimeOutput_Disable();
    }
    else
    {
        // ** Throw error
    }
}
//-------------------------------------------------------------//
//--------------------SET-CHIME-PARAMETERS---------------------//
//-------------------------------------------------------------//

void ChimeControl_ConfigureChime(uint8 new_pattern, uint8 new_cycles)
{
    next_pattern = new_pattern;

    // Turn on chime
    if(cycles == 0 && new_cycles > 0)
    {
        UserInterface_BusySemaphore(true);
        
        pattern = new_pattern;
        cycles = new_cycles;
        
        ChimeOutput_Start();
        ChimeTimer_Start();
    }
    // Turn off chime
    else if(cycles > 0 && new_cycles == 0)
    {
        cycles = 1;
    }
    // If chime on update chime
    else if(cycles > 0 && new_cycles > 0)
    {
        cycles = new_cycles + 1;
    }
}
//-------------------------------------------------------------//
