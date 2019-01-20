#ifndef CALENDARTIME_H
#define CALENDARTIME_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <KinOS.h>
    
//-------------------------------------------------------------//

void CalendarTime_Init();
void CalendarTime_SetDateAndTime(uint8 year, uint8 month, uint8 day,
                                 uint8 hour, uint8 minute, uint8 second);
epoch CalendarTime_GetDateAndTime();

//-------------------------------------------------------------//

#endif /* CALENDARTIME_H */
