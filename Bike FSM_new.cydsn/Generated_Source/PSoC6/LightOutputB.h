/*******************************************************************************
* File Name: LightOutputB.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the LightOutputB
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(LightOutputB_CY_TCPWM_PWM_PDL_H)
#define LightOutputB_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  LightOutputB_initVar;
extern cy_stc_tcpwm_pwm_config_t const LightOutputB_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void LightOutputB_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t LightOutputB_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void LightOutputB_DeInit(void);
__STATIC_INLINE void LightOutputB_Enable(void);
__STATIC_INLINE void LightOutputB_Disable(void);
__STATIC_INLINE uint32_t LightOutputB_GetStatus(void);
__STATIC_INLINE void LightOutputB_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t LightOutputB_GetCompare0(void);
__STATIC_INLINE void LightOutputB_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t LightOutputB_GetCompare1(void);
__STATIC_INLINE void LightOutputB_EnableCompareSwap(bool enable);
__STATIC_INLINE void LightOutputB_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t LightOutputB_GetCounter(void);
__STATIC_INLINE void LightOutputB_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t LightOutputB_GetPeriod0(void);
__STATIC_INLINE void LightOutputB_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t LightOutputB_GetPeriod1(void);
__STATIC_INLINE void LightOutputB_EnablePeriodSwap(bool enable);
__STATIC_INLINE void LightOutputB_TriggerStart(void);
__STATIC_INLINE void LightOutputB_TriggerReload(void);
__STATIC_INLINE void LightOutputB_TriggerKill(void);
__STATIC_INLINE void LightOutputB_TriggerSwap(void);
__STATIC_INLINE uint32_t LightOutputB_GetInterruptStatus(void);
__STATIC_INLINE void LightOutputB_ClearInterrupt(uint32_t source);
__STATIC_INLINE void LightOutputB_SetInterrupt(uint32_t source);
__STATIC_INLINE void LightOutputB_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t LightOutputB_GetInterruptMask(void);
__STATIC_INLINE uint32_t LightOutputB_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define LightOutputB_HW                 (LightOutputB_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define LightOutputB_CNT_HW             (LightOutputB_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define LightOutputB_CNT_NUM            (LightOutputB_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define LightOutputB_CNT_MASK           (1UL << LightOutputB_CNT_NUM)
/** @} group_macros */

#define LightOutputB_INPUT_MODE_MASK    (0x3U)
#define LightOutputB_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: LightOutputB_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t LightOutputB_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(LightOutputB_HW, LightOutputB_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: LightOutputB_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(LightOutputB_HW, LightOutputB_CNT_NUM, &LightOutputB_config);
}

/*******************************************************************************
* Function Name: LightOutputB_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(LightOutputB_HW, LightOutputB_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputB_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(LightOutputB_HW, LightOutputB_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputB_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(LightOutputB_HW, LightOutputB_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: LightOutputB_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(LightOutputB_HW, LightOutputB_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: LightOutputB_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(LightOutputB_HW, LightOutputB_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LightOutputB_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(LightOutputB_HW, LightOutputB_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: LightOutputB_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(LightOutputB_HW, LightOutputB_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: LightOutputB_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(LightOutputB_HW, LightOutputB_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: LightOutputB_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(LightOutputB_HW, LightOutputB_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LightOutputB_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(LightOutputB_HW, LightOutputB_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputB_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(LightOutputB_HW, LightOutputB_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputB_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(LightOutputB_HW, LightOutputB_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputB_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(LightOutputB_HW, LightOutputB_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputB_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(LightOutputB_HW, LightOutputB_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightOutputB_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(LightOutputB_HW, LightOutputB_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightOutputB_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputB_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(LightOutputB_HW, LightOutputB_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: LightOutputB_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(LightOutputB_HW, LightOutputB_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputB_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputB_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(LightOutputB_HW, LightOutputB_CNT_NUM));
}

#endif /* LightOutputB_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
