/*******************************************************************************
* File Name: LightOutputC.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the LightOutputC
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(LightOutputC_CY_TCPWM_PWM_PDL_H)
#define LightOutputC_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  LightOutputC_initVar;
extern cy_stc_tcpwm_pwm_config_t const LightOutputC_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void LightOutputC_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t LightOutputC_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void LightOutputC_DeInit(void);
__STATIC_INLINE void LightOutputC_Enable(void);
__STATIC_INLINE void LightOutputC_Disable(void);
__STATIC_INLINE uint32_t LightOutputC_GetStatus(void);
__STATIC_INLINE void LightOutputC_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t LightOutputC_GetCompare0(void);
__STATIC_INLINE void LightOutputC_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t LightOutputC_GetCompare1(void);
__STATIC_INLINE void LightOutputC_EnableCompareSwap(bool enable);
__STATIC_INLINE void LightOutputC_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t LightOutputC_GetCounter(void);
__STATIC_INLINE void LightOutputC_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t LightOutputC_GetPeriod0(void);
__STATIC_INLINE void LightOutputC_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t LightOutputC_GetPeriod1(void);
__STATIC_INLINE void LightOutputC_EnablePeriodSwap(bool enable);
__STATIC_INLINE void LightOutputC_TriggerStart(void);
__STATIC_INLINE void LightOutputC_TriggerReload(void);
__STATIC_INLINE void LightOutputC_TriggerKill(void);
__STATIC_INLINE void LightOutputC_TriggerSwap(void);
__STATIC_INLINE uint32_t LightOutputC_GetInterruptStatus(void);
__STATIC_INLINE void LightOutputC_ClearInterrupt(uint32_t source);
__STATIC_INLINE void LightOutputC_SetInterrupt(uint32_t source);
__STATIC_INLINE void LightOutputC_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t LightOutputC_GetInterruptMask(void);
__STATIC_INLINE uint32_t LightOutputC_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define LightOutputC_HW                 (LightOutputC_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define LightOutputC_CNT_HW             (LightOutputC_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define LightOutputC_CNT_NUM            (LightOutputC_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define LightOutputC_CNT_MASK           (1UL << LightOutputC_CNT_NUM)
/** @} group_macros */

#define LightOutputC_INPUT_MODE_MASK    (0x3U)
#define LightOutputC_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: LightOutputC_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t LightOutputC_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(LightOutputC_HW, LightOutputC_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: LightOutputC_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(LightOutputC_HW, LightOutputC_CNT_NUM, &LightOutputC_config);
}

/*******************************************************************************
* Function Name: LightOutputC_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(LightOutputC_HW, LightOutputC_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputC_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(LightOutputC_HW, LightOutputC_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputC_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(LightOutputC_HW, LightOutputC_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: LightOutputC_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(LightOutputC_HW, LightOutputC_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: LightOutputC_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(LightOutputC_HW, LightOutputC_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LightOutputC_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(LightOutputC_HW, LightOutputC_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: LightOutputC_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(LightOutputC_HW, LightOutputC_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: LightOutputC_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(LightOutputC_HW, LightOutputC_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: LightOutputC_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(LightOutputC_HW, LightOutputC_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LightOutputC_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(LightOutputC_HW, LightOutputC_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputC_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(LightOutputC_HW, LightOutputC_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputC_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(LightOutputC_HW, LightOutputC_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputC_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(LightOutputC_HW, LightOutputC_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputC_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(LightOutputC_HW, LightOutputC_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightOutputC_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(LightOutputC_HW, LightOutputC_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightOutputC_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputC_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(LightOutputC_HW, LightOutputC_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: LightOutputC_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(LightOutputC_HW, LightOutputC_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputC_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputC_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(LightOutputC_HW, LightOutputC_CNT_NUM));
}

#endif /* LightOutputC_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
