/*******************************************************************************
* File Name: ChimeOutput.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the ChimeOutput
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ChimeOutput_CY_TCPWM_PWM_PDL_H)
#define ChimeOutput_CY_TCPWM_PWM_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_pwm.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  ChimeOutput_initVar;
extern cy_stc_tcpwm_pwm_config_t const ChimeOutput_config;
/** @} group_globals */


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void ChimeOutput_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t ChimeOutput_Init(cy_stc_tcpwm_pwm_config_t const *config);
__STATIC_INLINE void ChimeOutput_DeInit(void);
__STATIC_INLINE void ChimeOutput_Enable(void);
__STATIC_INLINE void ChimeOutput_Disable(void);
__STATIC_INLINE uint32_t ChimeOutput_GetStatus(void);
__STATIC_INLINE void ChimeOutput_SetCompare0(uint32_t compare0);
__STATIC_INLINE uint32_t ChimeOutput_GetCompare0(void);
__STATIC_INLINE void ChimeOutput_SetCompare1(uint32_t compare1);
__STATIC_INLINE uint32_t ChimeOutput_GetCompare1(void);
__STATIC_INLINE void ChimeOutput_EnableCompareSwap(bool enable);
__STATIC_INLINE void ChimeOutput_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t ChimeOutput_GetCounter(void);
__STATIC_INLINE void ChimeOutput_SetPeriod0(uint32_t period0);
__STATIC_INLINE uint32_t ChimeOutput_GetPeriod0(void);
__STATIC_INLINE void ChimeOutput_SetPeriod1(uint32_t period1);
__STATIC_INLINE uint32_t ChimeOutput_GetPeriod1(void);
__STATIC_INLINE void ChimeOutput_EnablePeriodSwap(bool enable);
__STATIC_INLINE void ChimeOutput_TriggerStart(void);
__STATIC_INLINE void ChimeOutput_TriggerReload(void);
__STATIC_INLINE void ChimeOutput_TriggerKill(void);
__STATIC_INLINE void ChimeOutput_TriggerSwap(void);
__STATIC_INLINE uint32_t ChimeOutput_GetInterruptStatus(void);
__STATIC_INLINE void ChimeOutput_ClearInterrupt(uint32_t source);
__STATIC_INLINE void ChimeOutput_SetInterrupt(uint32_t source);
__STATIC_INLINE void ChimeOutput_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t ChimeOutput_GetInterruptMask(void);
__STATIC_INLINE uint32_t ChimeOutput_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define ChimeOutput_HW                 (ChimeOutput_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define ChimeOutput_CNT_HW             (ChimeOutput_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define ChimeOutput_CNT_NUM            (ChimeOutput_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define ChimeOutput_CNT_MASK           (1UL << ChimeOutput_CNT_NUM)
/** @} group_macros */

#define ChimeOutput_INPUT_MODE_MASK    (0x3U)
#define ChimeOutput_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: ChimeOutput_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t ChimeOutput_Init(cy_stc_tcpwm_pwm_config_t const *config)
{
    return(Cy_TCPWM_PWM_Init(ChimeOutput_HW, ChimeOutput_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: ChimeOutput_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_DeInit(void)                   
{
    Cy_TCPWM_PWM_DeInit(ChimeOutput_HW, ChimeOutput_CNT_NUM, &ChimeOutput_config);
}

/*******************************************************************************
* Function Name: ChimeOutput_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(ChimeOutput_HW, ChimeOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeOutput_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(ChimeOutput_HW, ChimeOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetStatus(void)                
{
    return(Cy_TCPWM_PWM_GetStatus(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_SetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetCompare0(uint32_t compare0)      
{
    Cy_TCPWM_PWM_SetCompare0(ChimeOutput_HW, ChimeOutput_CNT_NUM, compare0);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetCompare0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetCompare0(void)              
{
    return(Cy_TCPWM_PWM_GetCompare0(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_SetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetCompare1(uint32_t compare1)      
{
    Cy_TCPWM_PWM_SetCompare1(ChimeOutput_HW, ChimeOutput_CNT_NUM, compare1);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetCompare1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCompare1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetCompare1(void)              
{
    return(Cy_TCPWM_PWM_GetCompare1(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_EnableCompareSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnableCompareSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_EnableCompareSwap(bool enable)  
{
    Cy_TCPWM_PWM_EnableCompareSwap(ChimeOutput_HW, ChimeOutput_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: ChimeOutput_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetCounter(uint32_t count)          
{
    Cy_TCPWM_PWM_SetCounter(ChimeOutput_HW, ChimeOutput_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetCounter(void)               
{
    return(Cy_TCPWM_PWM_GetCounter(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_SetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetPeriod0(uint32_t period0)          
{
    Cy_TCPWM_PWM_SetPeriod0(ChimeOutput_HW, ChimeOutput_CNT_NUM, period0);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetPeriod0
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod0() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetPeriod0(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod0(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_SetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_SetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetPeriod1(uint32_t period1)
{
    Cy_TCPWM_PWM_SetPeriod1(ChimeOutput_HW, ChimeOutput_CNT_NUM, period1);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetPeriod1
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_GetPeriod1() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetPeriod1(void)                
{
    return(Cy_TCPWM_PWM_GetPeriod1(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_EnablePeriodSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_PWM_EnablePeriodSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_EnablePeriodSwap(bool enable)
{
    Cy_TCPWM_PWM_EnablePeriodSwap(ChimeOutput_HW, ChimeOutput_CNT_NUM, enable);
}


/*******************************************************************************
* Function Name: ChimeOutput_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(ChimeOutput_HW, ChimeOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeOutput_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(ChimeOutput_HW, ChimeOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeOutput_TriggerKill
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_TriggerKill(void)
{
    Cy_TCPWM_TriggerStopOrKill(ChimeOutput_HW, ChimeOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeOutput_TriggerSwap
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_TriggerSwap(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(ChimeOutput_HW, ChimeOutput_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(ChimeOutput_HW, ChimeOutput_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ChimeOutput_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(ChimeOutput_HW, ChimeOutput_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ChimeOutput_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeOutput_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(ChimeOutput_HW, ChimeOutput_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: ChimeOutput_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeOutput_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeOutput_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(ChimeOutput_HW, ChimeOutput_CNT_NUM));
}

#endif /* ChimeOutput_CY_TCPWM_PWM_PDL_H */


/* [] END OF FILE */
