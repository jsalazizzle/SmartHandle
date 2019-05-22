/*******************************************************************************
* File Name: LightOutputA.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the LightOutputA
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(LightOutputA_CY_TCPWM_PWM_PDL_H)
#define LightOutputA_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  LightOutputA_initVar;
extern cy_stc_tcpwm_pwm_config_t const LightOutputA_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void LightOutputA_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t LightOutputA_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void LightOutputA_DeInit(void);
__STATIC_INLINE void LightOutputA_Enable(void);
__STATIC_INLINE void LightOutputA_Disable(void);
__STATIC_INLINE uint32_t LightOutputA_GetStatus(void);
__STATIC_INLINE void LightOutputA_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t LightOutputA_GetCompare0(void);
__STATIC_INLINE void LightOutputA_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t LightOutputA_GetCompare1(void);
__STATIC_INLINE void LightOutputA_EnableCompareSwap(bool enable);
__STATIC_INLINE void LightOutputA_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t LightOutputA_GetCounter(void);
__STATIC_INLINE void LightOutputA_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t LightOutputA_GetPeriod0(void);
__STATIC_INLINE void LightOutputA_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t LightOutputA_GetPeriod1(void);
__STATIC_INLINE void LightOutputA_EnablePeriodSwap(bool enable);
__STATIC_INLINE void LightOutputA_TriggerStart(void);
__STATIC_INLINE void LightOutputA_TriggerReload(void);
__STATIC_INLINE void LightOutputA_TriggerKill(void);
__STATIC_INLINE void LightOutputA_TriggerSwap(void);
__STATIC_INLINE uint32_t LightOutputA_GetInterruptStatus(void);
__STATIC_INLINE void LightOutputA_ClearInterrupt(uint32_t source);
__STATIC_INLINE void LightOutputA_SetInterrupt(uint32_t source);
__STATIC_INLINE void LightOutputA_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t LightOutputA_GetInterruptMask(void);
__STATIC_INLINE uint32_t LightOutputA_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define LightOutputA_HW                 (LightOutputA_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define LightOutputA_CNT_HW             (LightOutputA_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define LightOutputA_CNT_NUM            (LightOutputA_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define LightOutputA_CNT_MASK           (1UL << LightOutputA_CNT_NUM)
/** @} group_macros */

#define LightOutputA_INPUT_MODE_MASK    (0x3U)
#define LightOutputA_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: LightOutputA_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t LightOutputA_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(LightOutputA_HW, LightOutputA_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: LightOutputA_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(LightOutputA_HW, LightOutputA_CNT_NUM, &LightOutputA_config);
}

/*******************************************************************************
* Function Name: LightOutputA_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(LightOutputA_HW, LightOutputA_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputA_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(LightOutputA_HW, LightOutputA_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputA_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(LightOutputA_HW, LightOutputA_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: LightOutputA_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(LightOutputA_HW, LightOutputA_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: LightOutputA_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(LightOutputA_HW, LightOutputA_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LightOutputA_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(LightOutputA_HW, LightOutputA_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: LightOutputA_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(LightOutputA_HW, LightOutputA_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: LightOutputA_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(LightOutputA_HW, LightOutputA_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: LightOutputA_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(LightOutputA_HW, LightOutputA_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: LightOutputA_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(LightOutputA_HW, LightOutputA_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputA_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(LightOutputA_HW, LightOutputA_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputA_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(LightOutputA_HW, LightOutputA_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputA_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(LightOutputA_HW, LightOutputA_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightOutputA_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(LightOutputA_HW, LightOutputA_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightOutputA_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(LightOutputA_HW, LightOutputA_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightOutputA_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightOutputA_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(LightOutputA_HW, LightOutputA_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: LightOutputA_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(LightOutputA_HW, LightOutputA_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightOutputA_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightOutputA_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(LightOutputA_HW, LightOutputA_CNT_NUM));
}

#endif /* LightOutputA_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
