/*******************************************************************************
* File Name: ChimeOutput.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the ChimeOutput
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ChimeOutput.h"

/** Indicates whether or not the ChimeOutput has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  ChimeOutput_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the ChimeOutput_Start() routine.
*/
uint8_t ChimeOutput_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated ChimeOutput_Init() function.
*/ 
cy_stc_tcpwm_pwm_config_t const ChimeOutput_config =
{
    .pwmMode = 4UL,
    .clockPrescaler = 0UL,
    .pwmAlignment = 0UL,
    .deadTimeClocks = 0UL,
    .runMode = 0UL,
    .period0 = 250UL,
    .period1 = 32768UL,
    .enablePeriodSwap = false,
    .compare0 = 50UL,
    .compare1 = 16384UL,
    .enableCompareSwap = false,
    .interruptSources = 0UL,
    .invertPWMOut = 0UL,
    .invertPWMOutN = 0UL,
    .killMode = 2UL,
    .swapInputMode = 3UL,
    .swapInput = CY_TCPWM_INPUT_CREATOR,
    .reloadInputMode = 3UL,
    .reloadInput = CY_TCPWM_INPUT_CREATOR,
    .startInputMode = 3UL,
    .startInput = CY_TCPWM_INPUT_CREATOR,
    .killInputMode = 3UL,
    .killInput = CY_TCPWM_INPUT_CREATOR,
    .countInputMode = 3UL,
    .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: ChimeOutput_Start
****************************************************************************//**
*
*  Calls the ChimeOutput_Init() when called the first time and enables 
*  the ChimeOutput. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref ChimeOutput_initVar
*
*******************************************************************************/
void ChimeOutput_Start(void)
{
    if (0U == ChimeOutput_initVar)
    {
        (void) Cy_TCPWM_PWM_Init(ChimeOutput_HW, ChimeOutput_CNT_NUM, &ChimeOutput_config);

        ChimeOutput_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(ChimeOutput_HW, ChimeOutput_CNT_MASK);
    
    #if (ChimeOutput_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(ChimeOutput_HW, ChimeOutput_CNT_MASK);
    #endif /* (ChimeOutput_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
