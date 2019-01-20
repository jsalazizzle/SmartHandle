/*******************************************************************************
* File Name: MotorTimer.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the MotorTimer
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "MotorTimer.h"

/** Indicates whether or not the MotorTimer has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  MotorTimer_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the MotorTimer_Start() routine.
*/
uint8_t MotorTimer_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated MotorTimer_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const MotorTimer_config =
{
        .period = 90UL,
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
* Function Name: MotorTimer_Start
****************************************************************************//**
*
*  Calls the MotorTimer_Init() when called the first time and enables 
*  the MotorTimer. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref MotorTimer_initVar
*
*******************************************************************************/
void MotorTimer_Start(void)
{
    if (0U == MotorTimer_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(MotorTimer_HW, MotorTimer_CNT_NUM, &MotorTimer_config); 

        MotorTimer_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(MotorTimer_HW, MotorTimer_CNT_MASK);
    
    #if (MotorTimer_INPUT_DISABLED == 7UL)
        Cy_TCPWM_TriggerStart(MotorTimer_HW, MotorTimer_CNT_MASK);
    #endif /* (MotorTimer_INPUT_DISABLED == 7UL) */    
}


/* [] END OF FILE */
