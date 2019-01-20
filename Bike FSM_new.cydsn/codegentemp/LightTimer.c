/*******************************************************************************
* File Name: LightTimer.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the LightTimer
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LightTimer.h"

/** Indicates whether or not the LightTimer has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  LightTimer_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the LightTimer_Start() routine.
*/
uint8_t LightTimer_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated LightTimer_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const LightTimer_config =
{
        .period = 42UL,
        .clockPrescaler = 0UL,
        .runMode = 0UL,
        .countDirection = 0UL,
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
* Function Name: LightTimer_Start
****************************************************************************//**
*
*  Calls the LightTimer_Init() when called the first time and enables 
*  the LightTimer. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref LightTimer_initVar
*
*******************************************************************************/
void LightTimer_Start(void)
{
    if (0U == LightTimer_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(LightTimer_HW, LightTimer_CNT_NUM, &LightTimer_config); 

        LightTimer_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(LightTimer_HW, LightTimer_CNT_MASK);
    
    #if (LightTimer_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(LightTimer_HW, LightTimer_CNT_MASK);
    #endif /* (LightTimer_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
