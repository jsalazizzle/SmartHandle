
#include <TimingMaster.h>
#include <SystemCore.h>

#include "debug.h"

//-------------------------------------------------------------//

typedef struct
{
    uint8  id;    // Unique Timer ID
    uint32 period;  // In LFCLK cycles
    uint32 remaining; // In LFCLK cycles
}
Timer;

#define EXPIRATION_PREEMPTION 10 // 305 us

uint8  num_timers = 0;
Timer  timers[MAX_TIMERS];

//-------------------------------------------------------------//
//-----------------------TIMER-MAINTENANCE---------------------//
//-------------------------------------------------------------//

static void TimingMaster_Update(uint32 elapsed_count)
{
    uint8 num_expired = 0;
    Timer* expired[MAX_TIMERS];
    uint8 shortest_expiration_id = 0;
    
    for(uint8 i = 0; i < num_timers; i++)
    {
        // Determine which timers are considered expired
        if(elapsed_count + EXPIRATION_PREEMPTION >= timers[i].remaining)
        {
            timers[i].remaining = timers[i].period;
            expired[num_expired++] = &timers[i];
        }
        // If not expired update remaining count
        else
        {
            timers[i].remaining = timers[i].remaining - elapsed_count;
        }
        // Find active timer with shortest expiration
        if(timers[i].remaining < timers[shortest_expiration_id].remaining)
        {
            shortest_expiration_id = i;
        }
    }
    
    // Setup WDT0 and WDT1 for shortest expiration
    if(timers[shortest_expiration_id].remaining < 65535)
    {
        Cy_MCWDT_SetMatch(MCWDT_HW, CY_MCWDT_COUNTER0, timers[shortest_expiration_id].remaining, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
        Cy_MCWDT_SetMatch(MCWDT_HW, CY_MCWDT_COUNTER1, 0, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
    }
    else
    {
        Cy_MCWDT_SetMatch(MCWDT_HW, CY_MCWDT_COUNTER0, 65535, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
        Cy_MCWDT_SetMatch(MCWDT_HW, CY_MCWDT_COUNTER1, (timers[shortest_expiration_id].remaining / 65535) - 1, MCWDT_TWO_LF_CLK_CYCLES_DELAY); // New MCWDT counter offset by 1
    }
    // Not a critical failure. Sanity check just incase.
    if(Cy_MCWDT_GetCount(MCWDT_HW, CY_MCWDT_COUNTER1) >= Cy_MCWDT_GetMatch(MCWDT_HW, CY_MCWDT_COUNTER1))
    {
        // ** Throw warning
        Cy_MCWDT_ResetCounters(MCWDT_HW, CY_MCWDT_CTR0|CY_MCWDT_CTR1, MCWDT_TWO_LF_CLK_CYCLES_DELAY);        
    }
    // Service all expired timers
    for(uint8 i = 0; i < num_expired; i++)
    {
        SystemCore_TimerHandler(expired[i]->id);
    }
}
void WatchDogHandler()
{
    uint32 src = Cy_MCWDT_GetInterruptStatus(MCWDT_HW);
    
    if(0u != (src & CY_MCWDT_CTR1))
    {        
        Cy_MCWDT_ClearInterrupt(MCWDT_HW, CY_MCWDT_CTR1);
        
        uint32 match1 = Cy_MCWDT_GetMatch(MCWDT_HW, CY_MCWDT_COUNTER1);
        uint32 match0 = Cy_MCWDT_GetMatch(MCWDT_HW, CY_MCWDT_COUNTER0);
        uint32 elapsed_count = (match1+1)*match0; // Counter1 is zero-indexed, so +1 to get real match value
        
        // In cascade mode, counter0 clears on match value, counter1 free running which requires software reset.
        // May change in the future (counter1 to clear on match) as Cypress updates the WDT peripheral.
        Cy_MCWDT_ResetCounters(MCWDT_HW, CY_MCWDT_CTR1, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
        
        TimingMaster_Update(elapsed_count+1); // Handler adds 1 count       
    }
    
    NVIC_ClearPendingIRQ(WatchDog_IRQ_cfg.intrSrc);
}
//-------------------------------------------------------------//
//-----------------------TIMER-MANAGEMENT----------------------//
//-------------------------------------------------------------//

bool TimingMaster_ConfigureTimer(uint8 id, uint64 period_ms)
{
    uint32 period_count = (uint32)(period_ms * 65535 / 2 / 1000);
    int8 timer_match_index = -1;
    
    // Scan for id index in timer list
    for(uint8 i = 0; i < num_timers; i++)
    {
        if(timers[i].id == id) timer_match_index = i;
    }
    // If existing timer then modify
    if( (period_ms != 0) && (timer_match_index != -1) )
    {
        timers[timer_match_index].period = period_count;
        timers[timer_match_index].remaining = period_count;
    }
    // If new timer then create
    else if( (period_ms != 0) && (timer_match_index == -1) )
    {
        timers[num_timers].id = id;
        timers[num_timers].period = period_count;
        timers[num_timers].remaining = period_count;
        
        if(num_timers++ == 0)
        {
            Cy_MCWDT_Enable(MCWDT_HW, CY_MCWDT_CTR0|CY_MCWDT_CTR1, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
        }
    }
    // If existing and period = 0 then remove
    else if( (period_ms == 0) && (timer_match_index != -1) )
    {
        for(uint8 i = timer_match_index; i < num_timers - 1; i++)
        {
            timers[i] = timers[i+1];
        }
        if(--num_timers == 0)
        {
            Cy_MCWDT_Disable(MCWDT_HW, CY_MCWDT_CTR0|CY_MCWDT_CTR1, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
        }
    }
    // Invalid ID, do nothing and exit
    else
    {
        // ** Throw error
        return false;
    }
    // Update virtual WDT internal state
    uint32 counter1 = Cy_MCWDT_GetCount(MCWDT_HW, CY_MCWDT_COUNTER1);
    uint32 counter0 = Cy_MCWDT_GetCount(MCWDT_HW, CY_MCWDT_COUNTER0);
    uint32 match0 = Cy_MCWDT_GetMatch(MCWDT_HW, CY_MCWDT_COUNTER0);
    
    Cy_MCWDT_ResetCounters(MCWDT_HW, CY_MCWDT_CTR0|CY_MCWDT_CTR1, MCWDT_TWO_LF_CLK_CYCLES_DELAY);
    
    uint32 elapsed_count = counter0 + (match0 * counter1);
    if(num_timers > 0) TimingMaster_Update(elapsed_count);
    return true;
}
//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void TimingMaster_Init()
{
    cy_en_sysint_status_t intrReturnValue = Cy_SysInt_Init(&WatchDog_IRQ_cfg, WatchDogHandler);
    if(intrReturnValue == CY_SYSINT_SUCCESS)
    {
        NVIC_ClearPendingIRQ(WatchDog_IRQ_cfg.intrSrc);
        NVIC_EnableIRQ(WatchDog_IRQ_cfg.intrSrc);
    	Cy_MCWDT_SetInterruptMask(MCWDT_HW, CY_MCWDT_CTR1);
        
        cy_en_mcwdt_status_t wdtReturnValue = Cy_MCWDT_Init(MCWDT_HW, &MCWDT_config);
        if(wdtReturnValue != CY_MCWDT_SUCCESS)
        {
            // ** Throw error
        }
    }
    else
    {
        // ** Throw error
    }
}
//-------------------------------------------------------------//