
#include <LightControl.h>
#include <UserInterface.h>
#include <KinOS.h>

#include "debug.h"

//-------------------------------------------------------------//

const uint8 logscale[256] = {0,0,0,0,0,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,
    2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,
    6,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,11,11,11,12,12,
    12,13,13,14,14,15,15,15,16,16,17,17,18,18,19,19,
    20,21,21,22,22,23,23,24,25,25,26,27,27,28,29,29,
    30,31,31,32,33,34,34,35,36,37,38,38,39,40,41,42,
    43,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,
    58,59,60,61,62,63,65,66,67,68,69,70,72,73,74,75,
    77,78,79,80,82,83,84,86,87,88,90,91,93,94,95,97,
    98,100,101,103,104,106,107,109,111,112,114,115,
    117,119,120,122,124,125,127,129,131,132,134,136,
    138,140,141,143,145,147,149,151,153,155,157,159,
    161,163,165,167,169,171,173,175,177,179,181,183,
    186,188,190,192,194,197,199,201,203,206,208,210,
    213,215,218,220,222,225,227,230,232,235,237,240,
    242,245,248,250,253,255,255};

static const uint8 pattern_map[4][60] = 
{
    // Smooth pattern
    {0,14,27,40,54,67,79,92,104,116,128,139,150,161,
     171,181,190,199,207,214,221,228,234,239,243,247,
     250,252,254,255,255,255,254,252,250,247,243,238,
     233,228,221,214,207,198,190,180,171,161,150,139,
     128,116,104,91,79,66,53,40,27,13},
    
    // Bounce pattern
    {13,26,38,51,64,77,89,102,115,128,140,153,166,179,
     191,204,217,230,242,255,247,240,232,224,217,209,
     201,194,186,179,186,194,201,209,217,224,232,240,
     247,255,242,230,217,204,191,179,166,153,140,128,
     115,102,89,77,64,51,38,26,13,0},
    
    // ZigZag pattern
    {0,12,43,89,142,192,232,253,252,230,191,140,87,41,
     11,1,12,45,91,144,194,233,253,252,229,189,138,85,
     40,10,1,13,46,93,146,196,234,254,251,228,187,135,
     83,38,9,1,14,48,95,148,198,235,254,251,226,185,
     133,81,37,8},
    
    // Bypass padding
    {255,255,255,255,255,255,255,255,255,255,255,255,
     255,255,255,255,255,255,255,255,255,255,255,255,
     255,255,255,255,255,255,255,255,255,255,255,255,
     255,255,255,255,255,255,255,255,255,255,255,255,
     255,255,255,255,255,255,255,255,255,255,255,255}
};

const uint8 density_map[7][3] = 
{
    { 255 ,  0  ,  0  },  // Red
    { 127 , 127 ,  0  },  // Yellow
    {  0  , 255 ,  0  },  // Green
    {  0  , 127 , 127 },  // Cyan
    {  0  ,  0  , 255 },  // Blue
    { 127 ,  0  , 127 },  // Magenta
    {  85 ,  85 ,  85 }   // White
};

//-------------------------------------------------------------//

static uint8 color = RED;
static uint8 pattern = SMOOTH;
static uint8 cycles = 1;
static uint8 brightness = 255;

static uint8 next_color = RED;
static uint8 next_pattern = SMOOTH;
static uint8 next_brightness = 255;

//-------------------------------------------------------------//
//--------------------TIMING-COORDINATION----------------------//
//-------------------------------------------------------------//

static void LightTimerHandler()
{
    static uint8 index = 0;
    static uint16 r,g,b;
    
    LightTimer_ClearInterrupt(LightTimer_GetInterruptMask());

    // Iterate through each element of the pattern map
    if(index == 60)
    {
        if(--cycles == 0)
        {
            LightTimer_TriggerStop();
            LightTimer_Disable();
            
            LightOutputA_SetCompare0(0);
            LightOutputB_SetCompare0(0);
            LightOutputC_SetCompare0(0);
            
            LightOutputA_Disable();
            LightOutputB_Disable();
            LightOutputC_Disable();
            
            UserInterface_BusySemaphore(false);
        }
        index = 0;
        color = next_color;
        pattern = next_pattern;
        brightness = next_brightness;
    }
    else
    {
        r = brightness * density_map[color][0] / 255;
        r = r * pattern_map[pattern][index] / 255;

        g = brightness * density_map[color][1] / 255;
        g = g * pattern_map[pattern][index] / 255;
        
        b = brightness * density_map[color][2] / 255;
        b = b * pattern_map[pattern][index] / 255;
        
//        LightTimer_Start(); // Necessary?
        
        LightOutputA_Start(); // Red
        LightOutputB_Start(); // Blue
        LightOutputC_Start(); // Green
        
        LightOutputA_SetCompare0(logscale[r]);
        LightOutputB_SetCompare0(logscale[b]);
        LightOutputC_SetCompare0(logscale[g]);
        
        index = index + 1;
    }
    
    NVIC_ClearPendingIRQ(LightTimer_IRQ_cfg.intrSrc);
}
//-------------------------------------------------------------//
//------------------INITIALIZE-LIGHT-CONTROL-------------------//
//-------------------------------------------------------------//

void LightControl_Init()
{
    cy_en_sysint_status_t intrReturnValue = Cy_SysInt_Init(&LightTimer_IRQ_cfg, LightTimerHandler);
    if(intrReturnValue == CY_SYSINT_SUCCESS)
    {
        LightTimer_ClearInterrupt(LightTimer_GetInterruptMask());
        NVIC_ClearPendingIRQ(LightTimer_IRQ_cfg.intrSrc);
        NVIC_EnableIRQ(LightTimer_IRQ_cfg.intrSrc);
        
        LightTimer_Start();
    
        LightOutputA_Start();
        LightOutputA_SetCompare0(0);
        LightOutputA_Disable();
        
        LightOutputB_Start();
        LightOutputB_SetCompare0(0);
        LightOutputB_Disable();
        
        LightOutputC_Start();
        LightOutputC_SetCompare0(0);
        LightOutputC_Disable();
    }
    else
    {
        // ** Throw error
    }
}
//-------------------------------------------------------------//
//--------------------SET-LIGHT-PARAMETERS---------------------//
//-------------------------------------------------------------//

void LightControl_ConfigureLight(uint8 new_color, uint8 new_pattern, uint8 new_cycles, uint8 new_brightness)
{
    next_color = new_color;
    next_pattern = new_pattern;
    next_brightness = new_brightness;

    // Turn on light
    if(cycles == 0 && new_cycles > 0)
    {
        UserInterface_BusySemaphore(true);
        
        color = new_color;
        pattern = new_pattern;
        cycles = new_cycles;
        brightness = new_brightness;
        
        LightOutputA_Start();
        LightOutputB_Start();
        LightOutputC_Start();
        LightTimer_Start();
    }
    // Turn off light
    else if(cycles > 0 && new_cycles == 0)
    {
        cycles = 1;
    }
    // If light on update light
    else if(cycles > 0 && new_cycles > 0)
    {
        cycles = new_cycles + 1;
    }
}
void LightControl_BypassSettings(uint8 new_color, uint8 new_brightness)
{
    if(pattern == BYPASS)
    {
        color = new_color;
        brightness = new_brightness;
    }
}
//-------------------------------------------------------------//
