/*******************************************************************************
* \file RealTimeClock.c
* \version 2.0
*
* This file provides the source code to the API for the RTC Component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RealTimeClock.h"

/** Indicates whether or not the RealTimeClock has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  RealTimeClock_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the RealTimeClock_Start() routine.
*/
uint8_t RealTimeClock_initVar = 0u;

/** The instance-specific configuration structure. This should be used in the 
*  associated RealTimeClock_Init() function.
*/
cy_stc_rtc_config_t const RealTimeClock_config =
{
    /* Initiate time and date */
    .sec       = RealTimeClock_INITIAL_DATE_SEC,
    .min       = RealTimeClock_INITIAL_DATE_MIN,
    .hour      = RealTimeClock_INITIAL_DATE_HOUR,
    .hrFormat  = RealTimeClock_INITIAL_DATE_HOUR_FORMAT,
    .dayOfWeek = RealTimeClock_INITIAL_DATE_DOW,
    .date      = RealTimeClock_INITIAL_DATE_DOM,
    .month     = RealTimeClock_INITIAL_DATE_MONTH,
    .year      = RealTimeClock_INITIAL_DATE_YEAR,
};

    /** RealTimeClock_rtcDstStatus variable which is for DST feature and is 
    *  called in Cy_RTC_Interrupt() PDL driver function. This variable is 
    *  defined as true if DST is enabled and as false if DST is disabled
    */
    bool RealTimeClock_rtcDstStatus = false;

#if(0u != RealTimeClock_INITIAL_DST_STATUS)

    /** The instance-specific daylight saving time structure. This should be 
    * used in the associated DTS functions.
    */
    cy_stc_rtc_dst_t const RealTimeClock_dstConfig =
    {
        /* DST Start time */
        .startDst.format      = (cy_en_rtc_dst_format_t) RealTimeClock_INITIAL_DST_DATE_TYPE,
        .startDst.hour        = RealTimeClock_INITIAL_DST_START_HRS,
        .startDst.dayOfMonth  = RealTimeClock_INITIAL_DST_START_DOM,
        .startDst.weekOfMonth = RealTimeClock_INITIAL_DST_START_WOM,
        .startDst.dayOfWeek   = RealTimeClock_INITIAL_DST_START_DOW,
        .startDst.month       = RealTimeClock_INITIAL_DST_START_MONTH,

        /* DST Stop time */
        .stopDst.format      = (cy_en_rtc_dst_format_t) RealTimeClock_INITIAL_DST_DATE_TYPE,
        .stopDst.hour        = RealTimeClock_INITIAL_DST_STOP_HRS,
        .stopDst.dayOfMonth  = RealTimeClock_INITIAL_DST_STOP_DOM,
        .stopDst.weekOfMonth = RealTimeClock_INITIAL_DST_STOP_WOM,
        .stopDst.dayOfWeek   = RealTimeClock_INITIAL_DST_STOP_DOW,
        .stopDst.month       = RealTimeClock_INITIAL_DST_STOP_MONTH,
    };
#else

    /* Default DST structure in condition that DST is disabled */
    cy_stc_rtc_dst_t const RealTimeClock_dstConfig;
#endif /* (0u != RealTimeClock_INITIAL_DST_STATUS) */


/*******************************************************************************
* Function Name: RealTimeClock_Start
****************************************************************************//**
*
* Optionally calls the RealTimeClock_Init() when called the first time and 
* configure the RealTimeClock as it is set in the customizer. For subsequent 
* calls the configuration is left unchanged and the component is just 
* configured. Invokes RealTimeClock_EnableDstTime() if the DST is enabled.
*
* \globalvars
* \ref RealTimeClock_initVar
*
*******************************************************************************/
void RealTimeClock_Start(void)
{
    #if(0u != RealTimeClock_INITIAL_DST_STATUS)
        cy_stc_rtc_config_t curTimeAndDate;
    #endif /* (0u != RealTimeClock_INITIAL_DST_STATUS) */
    
    if(0u == RealTimeClock_initVar)
    {
        #if(0u != RealTimeClock_TIME_RESET_ON_START)

            /* Configure the component if power cycle and the external 
            *  reset occurred
            */
            if(Cy_RTC_IsExternalResetOccurred())
            {
                (void) Cy_RTC_Init(&RealTimeClock_config);
            }
        #endif /* (0u != RealTimeClock_TIME_RESET_ON_START) */

        #if(0u != RealTimeClock_INITIAL_IRQ_STATUS)

            /* Hook the interrupt service routine */
            #if defined(RealTimeClock_RTC_IRQ__INTC_ASSIGNED)
                (void) Cy_SysInt_Init(&RealTimeClock_RTC_IRQ_cfg, &RealTimeClock_Interrupt);
            #endif /* defined(RealTimeClock_RTC_IRQ__INTC_ASSIGNED) */
        #endif /* (0u != RealTimeClock_INITIAL_IRQ_STATUS) */

        /* The component is configured */
        RealTimeClock_initVar = 1u;
    }

    #if(0u != RealTimeClock_INITIAL_IRQ_STATUS)
        #if defined(RealTimeClock_RTC_IRQ__INTC_ASSIGNED)
            NVIC_EnableIRQ(RealTimeClock_RTC_IRQ_cfg.intrSrc);
        #endif /* defined(RealTimeClock_RTC_IRQ__INTC_ASSIGNED) */

        #if(0u != RealTimeClock_INITIAL_DST_STATUS)
            #if(0u != RealTimeClock_TIME_RESET_ON_START)
                
                /* Wait for previous RTC update */
                Cy_SysLib_Delay(RealTimeClock_DELAY_BEFORE_DST);
            #endif /* (0u != RealTimeClock_TIME_RESET_ON_START) */
                
            Cy_RTC_GetDateAndTime(&curTimeAndDate);
            
            /* Set the DST configuration */
            if(Cy_RTC_EnableDstTime(&RealTimeClock_dstConfig, &curTimeAndDate) != CY_RTC_SUCCESS)
            {
                /* DST Setting failed */
                CY_ASSERT(0u != 0u);
            }
        #endif /* (0u != RealTimeClock_INITIAL_DST_STATUS) */
    #endif /* (0u != RealTimeClock_INITIAL_IRQ_STATUS) */
}


/* [] END OF FILE */
