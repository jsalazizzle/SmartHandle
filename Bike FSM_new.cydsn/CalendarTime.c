
#include <CalendarTime.h>
#include <SystemCore.h>

#include "debug.h"

//-------------------------------------------------------------//
//---------------------UPDATE-DATE-AND-TIME--------------------//
//-------------------------------------------------------------//

void CalendarTime_SetDateAndTime(uint8 year, uint8 month, uint8 day, uint8 hour, uint8 minute, uint8 second)
{    
    cy_en_rtc_status_t rtcReturnValue = Cy_RTC_SetDateAndTimeDirect(second, minute, hour, day, month, year);
    if(rtcReturnValue != CY_RTC_SUCCESS)
    {
        // ** Throw error
    }
}
epoch CalendarTime_GetDateAndTime()
{
    cy_stc_rtc_config_t dt;
    Cy_RTC_GetDateAndTime(&dt);
    
    epoch date_time;
    date_time.year   = dt.year;
    date_time.month  = dt.month;
    date_time.day    = dt.date;
    date_time.hour   = dt.hour;
    date_time.minute = dt.min;
    date_time.second = dt.sec;
    
    return date_time;
}
//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void CalendarTime_Init()
{    
    cy_en_rtc_status_t rtcReturnValue;
    
    rtcReturnValue = Cy_RTC_Init(&RealTimeClock_config);
    if(rtcReturnValue == CY_RTC_SUCCESS)
    {
        rtcReturnValue = Cy_RTC_SetHoursFormat(CY_RTC_24_HOURS);
        if(rtcReturnValue != CY_RTC_SUCCESS)
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
