/***************************************************************************//**
* \file SensorBus.c
* \version 2.0
*
*  This file provides the source code to the API for the I2C Component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SensorBus.h"
#include "sysint/cy_sysint.h"
#include "cyfitter_sysint.h"
#include "cyfitter_sysint_cfg.h"


#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*     Global variables
***************************************/

/** SensorBus_initVar indicates whether the SensorBus
*  component has been initialized. The variable is initialized to 0
*  and set to 1 the first time SensorBus_Start() is called.
*  This allows  the component to restart without reinitialization
*  after the first call to the SensorBus_Start() routine.
*
*  If re-initialization of the component is required, then the
*  SensorBus_Init() function can be called before the
*  SensorBus_Start() or SensorBus_Enable() function.
*/
uint8_t SensorBus_initVar = 0U;

/** The instance-specific configuration structure.
* The pointer to this structure should be passed to Cy_SCB_I2C_Init function
* to initialize component with GUI selected settings.
*/
cy_stc_scb_i2c_config_t const SensorBus_config =
{
    .i2cMode    = CY_SCB_I2C_MASTER,

    .useRxFifo = false,
    .useTxFifo = false,

    .slaveAddress        = 0U,
    .slaveAddressMask    = 0U,
    .acceptAddrInFifo    = false,
    .ackGeneralAddr      = false,

    .enableWakeFromSleep = false
};

/** The instance-specific context structure.
* It is used while the driver operation for internal configuration and
* data keeping for the I2C. The user should not modify anything in this
* structure.
*/
cy_stc_scb_i2c_context_t SensorBus_context;


/*******************************************************************************
* Function Name: SensorBus_Start
****************************************************************************//**
*
* Invokes SensorBus_Init() and SensorBus_Enable().
* Also configures interrupt and low and high oversampling phases.
* After this function call the component is enabled and ready for operation.
* This is the preferred method to begin component operation.
*
* \globalvars
* \ref SensorBus_initVar - used to check initial configuration,
* modified  on first function call.
*
*******************************************************************************/
void SensorBus_Start(void)
{
    if (0U == SensorBus_initVar)
    {
        /* Configure component */
        (void) Cy_SCB_I2C_Init(SensorBus_HW, &SensorBus_config, &SensorBus_context);

    #if (SensorBus_ENABLE_MASTER)
        /* Configure desired data rate */
        (void) Cy_SCB_I2C_SetDataRate(SensorBus_HW, SensorBus_DATA_RATE_HZ, SensorBus_CLK_FREQ_HZ);

        #if (SensorBus_MANUAL_SCL_CONTROL)
            Cy_SCB_I2C_MasterSetLowPhaseDutyCycle (SensorBus_HW, SensorBus_LOW_PHASE_DUTY_CYCLE);
            Cy_SCB_I2C_MasterSetHighPhaseDutyCycle(SensorBus_HW, SensorBus_HIGH_PHASE_DUTY_CYCLE);
        #endif /* (SensorBus_MANUAL_SCL_CONTROL) */
    #endif /* (SensorBus_ENABLE_MASTER) */

        /* Hook interrupt service routine */
    #if defined(SensorBus_SCB_IRQ__INTC_ASSIGNED)
        (void) Cy_SysInt_Init(&SensorBus_SCB_IRQ_cfg, &SensorBus_Interrupt);
    #endif /* (SensorBus_SCB_IRQ__INTC_ASSIGNED) */

        SensorBus_initVar = 1U;
    }

    /* Enable interrupt in NVIC */
#if defined(SensorBus_SCB_IRQ__INTC_ASSIGNED)
    NVIC_EnableIRQ((IRQn_Type) SensorBus_SCB_IRQ_cfg.intrSrc);
#endif /* (SensorBus_SCB_IRQ__INTC_ASSIGNED) */

    Cy_SCB_I2C_Enable(SensorBus_HW);
}

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
