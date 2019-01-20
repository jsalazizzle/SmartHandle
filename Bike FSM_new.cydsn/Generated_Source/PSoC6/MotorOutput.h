/*******************************************************************************
* File Name: MotorOutput.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the MotorOutput
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(MotorOutput_CY_TCPWM_PWM_PDL_H)
#define MotorOutput_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  MotorOutput_initVar;
extern cy_stc_tcpwm_pwm_config_t const MotorOutput_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void MotorOutput_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t MotorOutput_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void MotorOutput_DeInit(void);
__STATIC_INLINE void MotorOutput_Enable(void);
__STATIC_INLINE void MotorOutput_Disable(void);
__STATIC_INLINE uint32_t MotorOutput_GetStatus(void);
__STATIC_INLINE void MotorOutput_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t MotorOutput_GetCompare0(void);
__STATIC_INLINE void MotorOutput_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t MotorOutput_GetCompare1(void);
__STATIC_INLINE void MotorOutput_EnableCompareSwap(bool enable);
__STATIC_INLINE void MotorOutput_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t MotorOutput_GetCounter(void);
__STATIC_INLINE void MotorOutput_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t MotorOutput_GetPeriod0(void);
__STATIC_INLINE void MotorOutput_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t MotorOutput_GetPeriod1(void);
__STATIC_INLINE void MotorOutput_EnablePeriodSwap(bool enable);
__STATIC_INLINE void MotorOutput_TriggerStart(void);
__STATIC_INLINE void MotorOutput_TriggerReload(void);
__STATIC_INLINE void MotorOutput_TriggerKill(void);
__STATIC_INLINE void MotorOutput_TriggerSwap(void);
__STATIC_INLINE uint32_t MotorOutput_GetInterruptStatus(void);
__STATIC_INLINE void MotorOutput_ClearInterrupt(uint32_t source);
__STATIC_INLINE void MotorOutput_SetInterrupt(uint32_t source);
__STATIC_INLINE void MotorOutput_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t MotorOutput_GetInterruptMask(void);
__STATIC_INLINE uint32_t MotorOutput_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define MotorOutput_HW                 (MotorOutput_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define MotorOutput_CNT_HW             (MotorOutput_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define MotorOutput_CNT_NUM            (MotorOutput_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define MotorOutput_CNT_MASK           (1UL << MotorOutput_CNT_NUM)
/** @} group_macros */

#define MotorOutput_INPUT_MODE_MASK    (0x3U)
#define MotorOutput_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: MotorOutput_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t MotorOutput_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(MotorOutput_HW, MotorOutput_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: MotorOutput_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(MotorOutput_HW, MotorOutput_CNT_NUM, &MotorOutput_config);
}

/*******************************************************************************
* Function Name: MotorOutput_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(MotorOutput_HW, MotorOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorOutput_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(MotorOutput_HW, MotorOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorOutput_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(MotorOutput_HW, MotorOutput_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: MotorOutput_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(MotorOutput_HW, MotorOutput_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: MotorOutput_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(MotorOutput_HW, MotorOutput_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: MotorOutput_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(MotorOutput_HW, MotorOutput_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: MotorOutput_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(MotorOutput_HW, MotorOutput_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: MotorOutput_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(MotorOutput_HW, MotorOutput_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: MotorOutput_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(MotorOutput_HW, MotorOutput_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: MotorOutput_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(MotorOutput_HW, MotorOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorOutput_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(MotorOutput_HW, MotorOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorOutput_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(MotorOutput_HW, MotorOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorOutput_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(MotorOutput_HW, MotorOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorOutput_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(MotorOutput_HW, MotorOutput_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: MotorOutput_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(MotorOutput_HW, MotorOutput_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: MotorOutput_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorOutput_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(MotorOutput_HW, MotorOutput_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: MotorOutput_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(MotorOutput_HW, MotorOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorOutput_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorOutput_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(MotorOutput_HW, MotorOutput_CNT_NUM));
}

#endif /* MotorOutput_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
