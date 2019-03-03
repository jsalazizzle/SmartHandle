/*******************************************************************************
* File Name: ChimeTimer.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the ChimeTimer
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(ChimeTimer_CY_TCPWM_COUNTER_PDL_H)
#define ChimeTimer_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  ChimeTimer_initVar;
extern cy_stc_tcpwm_counter_config_t const ChimeTimer_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define ChimeTimer_INIT_COMPARE_OR_CAPTURE    (2UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void ChimeTimer_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t ChimeTimer_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void ChimeTimer_DeInit(void);
__STATIC_INLINE void ChimeTimer_Enable(void);
__STATIC_INLINE void ChimeTimer_Disable(void);
__STATIC_INLINE uint32_t ChimeTimer_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == ChimeTimer_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t ChimeTimer_GetCapture(void);
    __STATIC_INLINE uint32_t ChimeTimer_GetCaptureBuf(void);
#else
    __STATIC_INLINE void ChimeTimer_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t ChimeTimer_GetCompare0(void);
    __STATIC_INLINE void ChimeTimer_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t ChimeTimer_GetCompare1(void);
    __STATIC_INLINE void ChimeTimer_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == ChimeTimer_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void ChimeTimer_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t ChimeTimer_GetCounter(void);
__STATIC_INLINE void ChimeTimer_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t ChimeTimer_GetPeriod(void);
__STATIC_INLINE void ChimeTimer_TriggerStart(void);
__STATIC_INLINE void ChimeTimer_TriggerReload(void);
__STATIC_INLINE void ChimeTimer_TriggerStop(void);
__STATIC_INLINE void ChimeTimer_TriggerCapture(void);
__STATIC_INLINE uint32_t ChimeTimer_GetInterruptStatus(void);
__STATIC_INLINE void ChimeTimer_ClearInterrupt(uint32_t source);
__STATIC_INLINE void ChimeTimer_SetInterrupt(uint32_t source);
__STATIC_INLINE void ChimeTimer_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t ChimeTimer_GetInterruptMask(void);
__STATIC_INLINE uint32_t ChimeTimer_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define ChimeTimer_HW                 (ChimeTimer_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define ChimeTimer_CNT_HW             (ChimeTimer_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define ChimeTimer_CNT_NUM            (ChimeTimer_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define ChimeTimer_CNT_MASK           (1UL << ChimeTimer_CNT_NUM)
/** @} group_macros */

#define ChimeTimer_INPUT_MODE_MASK    (0x3U)
#define ChimeTimer_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: ChimeTimer_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t ChimeTimer_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(ChimeTimer_HW, ChimeTimer_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: ChimeTimer_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(ChimeTimer_HW, ChimeTimer_CNT_NUM, &ChimeTimer_config);
}

/*******************************************************************************
* Function Name: ChimeTimer_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(ChimeTimer_HW, ChimeTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeTimer_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(ChimeTimer_HW, ChimeTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeTimer_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeTimer_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(ChimeTimer_HW, ChimeTimer_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == ChimeTimer_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: ChimeTimer_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ChimeTimer_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(ChimeTimer_HW, ChimeTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: ChimeTimer_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ChimeTimer_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(ChimeTimer_HW, ChimeTimer_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: ChimeTimer_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void ChimeTimer_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(ChimeTimer_HW, ChimeTimer_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: ChimeTimer_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ChimeTimer_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(ChimeTimer_HW, ChimeTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: ChimeTimer_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void ChimeTimer_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(ChimeTimer_HW, ChimeTimer_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: ChimeTimer_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t ChimeTimer_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(ChimeTimer_HW, ChimeTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: ChimeTimer_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void ChimeTimer_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(ChimeTimer_HW, ChimeTimer_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == ChimeTimer_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: ChimeTimer_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(ChimeTimer_HW, ChimeTimer_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: ChimeTimer_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeTimer_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(ChimeTimer_HW, ChimeTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeTimer_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(ChimeTimer_HW, ChimeTimer_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: ChimeTimer_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeTimer_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(ChimeTimer_HW, ChimeTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeTimer_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(ChimeTimer_HW, ChimeTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeTimer_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(ChimeTimer_HW, ChimeTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeTimer_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(ChimeTimer_HW, ChimeTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeTimer_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(ChimeTimer_HW, ChimeTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: ChimeTimer_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeTimer_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(ChimeTimer_HW, ChimeTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeTimer_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(ChimeTimer_HW, ChimeTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ChimeTimer_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(ChimeTimer_HW, ChimeTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: ChimeTimer_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void ChimeTimer_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(ChimeTimer_HW, ChimeTimer_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: ChimeTimer_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeTimer_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(ChimeTimer_HW, ChimeTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: ChimeTimer_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t ChimeTimer_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(ChimeTimer_HW, ChimeTimer_CNT_NUM));
}

#endif /* ChimeTimer_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
