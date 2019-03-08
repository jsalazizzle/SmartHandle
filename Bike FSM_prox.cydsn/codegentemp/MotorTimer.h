/*******************************************************************************
* File Name: MotorTimer.h
* Version 1.0
*
* Description:
*  This file provides constants and parameter values for the MotorTimer
*  component.
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(MotorTimer_CY_TCPWM_COUNTER_PDL_H)
#define MotorTimer_CY_TCPWM_COUNTER_PDL_H

#include "cyfitter.h"
#include "tcpwm/cy_tcpwm_counter.h"

   
/*******************************************************************************
* Variables
*******************************************************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t  MotorTimer_initVar;
extern cy_stc_tcpwm_counter_config_t const MotorTimer_config;
/** @} group_globals */


/***************************************
*  Conditional Compilation Parameters
***************************************/

#define MotorTimer_INIT_COMPARE_OR_CAPTURE    (2UL)


/***************************************
*        Function Prototypes
****************************************/
/**
* \addtogroup group_general
* @{
*/
void MotorTimer_Start(void);
__STATIC_INLINE cy_en_tcpwm_status_t MotorTimer_Init(cy_stc_tcpwm_counter_config_t const *config);
__STATIC_INLINE void MotorTimer_DeInit(void);
__STATIC_INLINE void MotorTimer_Enable(void);
__STATIC_INLINE void MotorTimer_Disable(void);
__STATIC_INLINE uint32_t MotorTimer_GetStatus(void);

#if(CY_TCPWM_COUNTER_MODE_CAPTURE == MotorTimer_INIT_COMPARE_OR_CAPTURE)
    __STATIC_INLINE uint32_t MotorTimer_GetCapture(void);
    __STATIC_INLINE uint32_t MotorTimer_GetCaptureBuf(void);
#else
    __STATIC_INLINE void MotorTimer_SetCompare0(uint32_t compare0);
    __STATIC_INLINE uint32_t MotorTimer_GetCompare0(void);
    __STATIC_INLINE void MotorTimer_SetCompare1(uint32_t compare1);
    __STATIC_INLINE uint32_t MotorTimer_GetCompare1(void);
    __STATIC_INLINE void MotorTimer_EnableCompareSwap(bool enable);
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == MotorTimer_INIT_COMPARE_OR_CAPTURE) */

__STATIC_INLINE void MotorTimer_SetCounter(uint32_t count);
__STATIC_INLINE uint32_t MotorTimer_GetCounter(void);
__STATIC_INLINE void MotorTimer_SetPeriod(uint32_t period);
__STATIC_INLINE uint32_t MotorTimer_GetPeriod(void);
__STATIC_INLINE void MotorTimer_TriggerStart(void);
__STATIC_INLINE void MotorTimer_TriggerReload(void);
__STATIC_INLINE void MotorTimer_TriggerStop(void);
__STATIC_INLINE void MotorTimer_TriggerCapture(void);
__STATIC_INLINE uint32_t MotorTimer_GetInterruptStatus(void);
__STATIC_INLINE void MotorTimer_ClearInterrupt(uint32_t source);
__STATIC_INLINE void MotorTimer_SetInterrupt(uint32_t source);
__STATIC_INLINE void MotorTimer_SetInterruptMask(uint32_t mask);
__STATIC_INLINE uint32_t MotorTimer_GetInterruptMask(void);
__STATIC_INLINE uint32_t MotorTimer_GetInterruptStatusMasked(void);
/** @} general */


/***************************************
*           API Constants
***************************************/

/**
* \addtogroup group_macros
* @{
*/
/** This is a ptr to the base address of the TCPWM instance */
#define MotorTimer_HW                 (MotorTimer_TCPWM__HW)

/** This is a ptr to the base address of the TCPWM CNT instance */
#define MotorTimer_CNT_HW             (MotorTimer_TCPWM__CNT_HW)

/** This is the counter instance number in the selected TCPWM */
#define MotorTimer_CNT_NUM            (MotorTimer_TCPWM__CNT_IDX)

/** This is the bit field representing the counter instance in the selected TCPWM */
#define MotorTimer_CNT_MASK           (1UL << MotorTimer_CNT_NUM)
/** @} group_macros */

#define MotorTimer_INPUT_MODE_MASK    (0x3U)
#define MotorTimer_INPUT_DISABLED     (7U)


/*******************************************************************************
* Function Name: MotorTimer_Init
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_tcpwm_status_t MotorTimer_Init(cy_stc_tcpwm_counter_config_t const *config)
{
    return(Cy_TCPWM_Counter_Init(MotorTimer_HW, MotorTimer_CNT_NUM, config));
}


/*******************************************************************************
* Function Name: MotorTimer_DeInit
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_DeInit(void)                   
{
    Cy_TCPWM_Counter_DeInit(MotorTimer_HW, MotorTimer_CNT_NUM, &MotorTimer_config);
}

/*******************************************************************************
* Function Name: MotorTimer_Enable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Enable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_Enable(void)                   
{
    Cy_TCPWM_Enable_Multiple(MotorTimer_HW, MotorTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorTimer_Disable
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Disable_Multiple() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_Disable(void)                  
{
    Cy_TCPWM_Disable_Multiple(MotorTimer_HW, MotorTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorTimer_GetStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorTimer_GetStatus(void)                
{
    return(Cy_TCPWM_Counter_GetStatus(MotorTimer_HW, MotorTimer_CNT_NUM));
}


#if(CY_TCPWM_COUNTER_MODE_CAPTURE == MotorTimer_INIT_COMPARE_OR_CAPTURE)
    /*******************************************************************************
    * Function Name: MotorTimer_GetCapture
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCapture() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t MotorTimer_GetCapture(void)               
    {
        return(Cy_TCPWM_Counter_GetCapture(MotorTimer_HW, MotorTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: MotorTimer_GetCaptureBuf
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCaptureBuf() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t MotorTimer_GetCaptureBuf(void)            
    {
        return(Cy_TCPWM_Counter_GetCaptureBuf(MotorTimer_HW, MotorTimer_CNT_NUM));
    }
#else
    /*******************************************************************************
    * Function Name: MotorTimer_SetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void MotorTimer_SetCompare0(uint32_t compare0)      
    {
        Cy_TCPWM_Counter_SetCompare0(MotorTimer_HW, MotorTimer_CNT_NUM, compare0);
    }


    /*******************************************************************************
    * Function Name: MotorTimer_GetCompare0
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare0() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t MotorTimer_GetCompare0(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare0(MotorTimer_HW, MotorTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: MotorTimer_SetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_SetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void MotorTimer_SetCompare1(uint32_t compare1)      
    {
        Cy_TCPWM_Counter_SetCompare1(MotorTimer_HW, MotorTimer_CNT_NUM, compare1);
    }


    /*******************************************************************************
    * Function Name: MotorTimer_GetCompare1
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_GetCompare1() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE uint32_t MotorTimer_GetCompare1(void)              
    {
        return(Cy_TCPWM_Counter_GetCompare1(MotorTimer_HW, MotorTimer_CNT_NUM));
    }


    /*******************************************************************************
    * Function Name: MotorTimer_EnableCompareSwap
    ****************************************************************************//**
    *
    * Invokes the Cy_TCPWM_Counter_EnableCompareSwap() PDL driver function.
    *
    *******************************************************************************/
    __STATIC_INLINE void MotorTimer_EnableCompareSwap(bool enable)  
    {
        Cy_TCPWM_Counter_EnableCompareSwap(MotorTimer_HW, MotorTimer_CNT_NUM, enable);
    }
#endif /* (CY_TCPWM_COUNTER_MODE_CAPTURE == MotorTimer_INIT_COMPARE_OR_CAPTURE) */


/*******************************************************************************
* Function Name: MotorTimer_SetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_SetCounter(uint32_t count)          
{
    Cy_TCPWM_Counter_SetCounter(MotorTimer_HW, MotorTimer_CNT_NUM, count);
}


/*******************************************************************************
* Function Name: MotorTimer_GetCounter
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetCounter() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorTimer_GetCounter(void)               
{
    return(Cy_TCPWM_Counter_GetCounter(MotorTimer_HW, MotorTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorTimer_SetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_SetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_SetPeriod(uint32_t period)          
{
    Cy_TCPWM_Counter_SetPeriod(MotorTimer_HW, MotorTimer_CNT_NUM, period);
}


/*******************************************************************************
* Function Name: MotorTimer_GetPeriod
****************************************************************************//**
*
* Invokes the Cy_TCPWM_Counter_GetPeriod() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorTimer_GetPeriod(void)                
{
    return(Cy_TCPWM_Counter_GetPeriod(MotorTimer_HW, MotorTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorTimer_TriggerStart
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_TriggerStart(void)             
{
    Cy_TCPWM_TriggerStart(MotorTimer_HW, MotorTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorTimer_TriggerReload
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerReloadOrIndex() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_TriggerReload(void)     
{
    Cy_TCPWM_TriggerReloadOrIndex(MotorTimer_HW, MotorTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorTimer_TriggerStop
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerStopOrKill() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_TriggerStop(void)
{
    Cy_TCPWM_TriggerStopOrKill(MotorTimer_HW, MotorTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorTimer_TriggerCapture
****************************************************************************//**
*
* Invokes the Cy_TCPWM_TriggerCaptureOrSwap() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_TriggerCapture(void)     
{
    Cy_TCPWM_TriggerCaptureOrSwap(MotorTimer_HW, MotorTimer_CNT_MASK);
}


/*******************************************************************************
* Function Name: MotorTimer_GetInterruptStatus
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorTimer_GetInterruptStatus(void)       
{
    return(Cy_TCPWM_GetInterruptStatus(MotorTimer_HW, MotorTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorTimer_ClearInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_ClearInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_ClearInterrupt(uint32_t source)     
{
    Cy_TCPWM_ClearInterrupt(MotorTimer_HW, MotorTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: MotorTimer_SetInterrupt
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_SetInterrupt(uint32_t source)
{
    Cy_TCPWM_SetInterrupt(MotorTimer_HW, MotorTimer_CNT_NUM, source);
}


/*******************************************************************************
* Function Name: MotorTimer_SetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_SetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void MotorTimer_SetInterruptMask(uint32_t mask)     
{
    Cy_TCPWM_SetInterruptMask(MotorTimer_HW, MotorTimer_CNT_NUM, mask);
}


/*******************************************************************************
* Function Name: MotorTimer_GetInterruptMask
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorTimer_GetInterruptMask(void)         
{
    return(Cy_TCPWM_GetInterruptMask(MotorTimer_HW, MotorTimer_CNT_NUM));
}


/*******************************************************************************
* Function Name: MotorTimer_GetInterruptStatusMasked
****************************************************************************//**
*
* Invokes the Cy_TCPWM_GetInterruptStatusMasked() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t MotorTimer_GetInterruptStatusMasked(void)
{
    return(Cy_TCPWM_GetInterruptStatusMasked(MotorTimer_HW, MotorTimer_CNT_NUM));
}

#endif /* MotorTimer_CY_TCPWM_COUNTER_PDL_H */


/* [] END OF FILE */
