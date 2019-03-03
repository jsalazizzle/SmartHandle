/*******************************************************************************
* File Name: ChimeTimer.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the ChimeTimer
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ChimeTimer.h"

/** Indicates whether or not the ChimeTimer has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  ChimeTimer_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the ChimeTimer_Start() routine.
*/
uint8_t ChimeTimer_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated ChimeTimer_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const ChimeTimer_config =
{
        .period = 64UL,
        .clockPrescaler = 0UL,
        .runMode = 0UL,
        .countDirection = 1UL,
        .compareOrCapture = 2UL,
        .compare0 = 16384UL,
        .compare1 = 16384UL,
        .enableCompareSwap = false,
        .interruptSources = 1UL,
        .captureInputMode = 3UL,
        .captureInput = CY_TCPWM_INPUT_CREATOR,
        .reloadInputMode = 3UL,
        .reloadInput = CY_TCPWM_INPUT_CREATOR,
        .startInputMode = 3UL,
        .startInput = CY_TCPWM_INPUT_CREATOR,
        .stopInputMode = 3UL,
        .stopInput = CY_TCPWM_INPUT_CREATOR,
        .countInputMode = 3UL,
        .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: ChimeTimer_Start
****************************************************************************//**
*
*  Calls the ChimeTimer_Init() when called the first time and enables 
*  the ChimeTimer. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref ChimeTimer_initVar
*
*******************************************************************************/
void ChimeTimer_Start(void)
{
    if (0U == ChimeTimer_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(ChimeTimer_HW, ChimeTimer_CNT_NUM, &ChimeTimer_config); 

        ChimeTimer_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(ChimeTimer_HW, ChimeTimer_CNT_MASK);
    
    #if (ChimeTimer_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(ChimeTimer_HW, ChimeTimer_CNT_MASK);
    #endif /* (ChimeTimer_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
