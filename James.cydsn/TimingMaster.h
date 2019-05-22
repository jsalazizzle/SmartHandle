#ifndef TIMINGMASTER_H
#define TIMINGMASTER_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <stdlib.h>
    
//-------------------------------------------------------------//

#define MAX_TIMERS 20
    
//-------------------------------------------------------------//

void TimingMaster_Init();
static void TimingMaster_Update(uint32 elapsed_count);
void WatchDogHandler();
bool TimingMaster_ConfigureTimer(uint8 id, uint64 period_us);

//-------------------------------------------------------------//

#endif /* TIMINGMASTER_H */
