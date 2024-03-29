/*******************************************************************************
* File Name: LightTimer.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the LightTimer
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(LightTimer_CY_TCPWM_COUNTER_PDL_H)
#define LightTimer_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  LightTimer_initVar;
extern cy_stc_tcpwm_counter_config_t const LightTimer_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define LightTimer_INIT_COMPARE_OR_CAPTURE    (2UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void LightTimer_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t LightTimer_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void LightTimer_DeInit(void);
__STATIC_INLINE void LightTimer_Enable(void);
__STATIC_INLINE void LightTimer_Disable(void);
__STATIC_INLINE uint32_t LightTimer_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == LightTimer_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t LightTimer_GetCapture(void);
    __STATIC_INLINE uint32_t LightTimer_GetCaptureBuf(void);
#else
    __STATIC_INLINE void LightTimer_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t LightTimer_GetCompare0(void);
    __STATIC_INLINE void LightTimer_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t LightTimer_GetCompare1(void);
    __STATIC_INLINE void LightTimer_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == LightTimer_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void LightTimer_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t LightTimer_GetCounter(void);
__STATIC_INLINE void LightTimer_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t LightTimer_GetPeriod(void);
__STATIC_INLINE void LightTimer_TriggerStart(void);
__STATIC_INLINE void LightTimer_TriggerReload(void);
__STATIC_INLINE void LightTimer_TriggerStop(void);
__STATIC_INLINE void LightTimer_TriggerCapture(void);
__STATIC_INLINE uint32_t LightTimer_GetInterruptStatus(void);
__STATIC_INLINE void LightTimer_ClearInterrupt(uint32_t source);
__STATIC_INLINE void LightTimer_SetInterrupt(uint32_t source);
__STATIC_INLINE void LightTimer_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t LightTimer_GetInterruptMask(void);
__STATIC_INLINE uint32_t LightTimer_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define LightTimer_HW                 (LightTimer_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define LightTimer_CNT_HW             (LightTimer_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define LightTimer_CNT_NUM            (LightTimer_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define LightTimer_CNT_MASK           (1UL << LightTimer_CNT_NUM)
/** @} group_macros */

#define LightTimer_INPUT_MODE_MASK    (0x3U)
#define LightTimer_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: LightTimer_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t LightTimer_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(LightTimer_HW, LightTimer_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: LightTimer_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(LightTimer_HW, LightTimer_CNT_NUM, &LightTimer_config);
}

/*******************************************************************************
* Function Name: LightTimer_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(LightTimer_HW, LightTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightTimer_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(LightTimer_HW, LightTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightTimer_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightTimer_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(LightTimer_HW, LightTimer_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == LightTimer_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: LightTimer_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t LightTimer_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(LightTimer_HW, LightTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: LightTimer_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t LightTimer_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(LightTimer_HW, LightTimer_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: LightTimer_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void LightTimer_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(LightTimer_HW, LightTimer_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: LightTimer_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t LightTimer_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(LightTimer_HW, LightTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: LightTimer_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void LightTimer_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(LightTimer_HW, LightTimer_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: LightTimer_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t LightTimer_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(LightTimer_HW, LightTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: LightTimer_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void LightTimer_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(LightTimer_HW, LightTimer_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == LightTimer_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: LightTimer_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(LightTimer_HW, LightTimer_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: LightTimer_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightTimer_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(LightTimer_HW, LightTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightTimer_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(LightTimer_HW, LightTimer_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: LightTimer_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightTimer_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(LightTimer_HW, LightTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightTimer_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(LightTimer_HW, LightTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightTimer_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(LightTimer_HW, LightTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightTimer_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(LightTimer_HW, LightTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightTimer_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(LightTimer_HW, LightTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: LightTimer_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightTimer_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(LightTimer_HW, LightTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightTimer_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(LightTimer_HW, LightTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightTimer_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(LightTimer_HW, LightTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: LightTimer_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void LightTimer_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(LightTimer_HW, LightTimer_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: LightTimer_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightTimer_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(LightTimer_HW, LightTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: LightTimer_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t LightTimer_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(LightTimer_HW, LightTimer_CNT_NUM));
}

#endif /* LightTimer_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
