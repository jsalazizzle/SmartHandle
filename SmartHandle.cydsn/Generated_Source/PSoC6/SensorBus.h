/***************************************************************************//**
* \file SensorBus.c
* \version 2.0
*
*  This file provides constants and parameter values for the I2C component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(SensorBus_CY_SCB_I2C_PDL_H)
#define SensorBus_CY_SCB_I2C_PDL_H

#include "cyfitter.h"
#include "scb/cy_scb_i2c.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*   Initial Parameter Constants
****************************************/

#define SensorBus_MODE               (0x2U)
#define SensorBus_MODE_SLAVE_MASK    (0x1U)
#define SensorBus_MODE_MASTER_MASK   (0x2U)

#define SensorBus_ENABLE_SLAVE       (0UL != (SensorBus_MODE & SensorBus_MODE_SLAVE_MASK))
#define SensorBus_ENABLE_MASTER      (0UL != (SensorBus_MODE & SensorBus_MODE_MASTER_MASK))
#define SensorBus_MANUAL_SCL_CONTROL (0U)


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
/* Component only APIs. */
void SensorBus_Start(void);

/* Basic functions. */
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_Init(cy_stc_scb_i2c_config_t const *config);
__STATIC_INLINE void SensorBus_DeInit (void);
__STATIC_INLINE void SensorBus_Enable (void);
__STATIC_INLINE void SensorBus_Disable(void);

/* Data rate configuration functions. */
__STATIC_INLINE uint32_t SensorBus_SetDataRate(uint32_t dataRateHz, uint32_t scbClockHz);
__STATIC_INLINE uint32_t SensorBus_GetDataRate(uint32_t scbClockHz);

/* Register callbacks. */
__STATIC_INLINE void SensorBus_RegisterEventCallback(cy_cb_scb_i2c_handle_events_t callback);
#if (SensorBus_ENABLE_SLAVE)
__STATIC_INLINE void SensorBus_RegisterAddrCallback (cy_cb_scb_i2c_handle_addr_t callback);
#endif /* (SensorBus_ENABLE_SLAVE) */

/* Configuration functions. */
#if (SensorBus_ENABLE_SLAVE)
__STATIC_INLINE void     SensorBus_SlaveSetAddress(uint8_t addr);
__STATIC_INLINE uint32_t SensorBus_SlaveGetAddress(void);
__STATIC_INLINE void     SensorBus_SlaveSetAddressMask(uint8_t addrMask);
__STATIC_INLINE uint32_t SensorBus_SlaveGetAddressMask(void);
#endif /* (SensorBus_ENABLE_SLAVE) */

#if (SensorBus_ENABLE_MASTER)
__STATIC_INLINE void SensorBus_MasterSetLowPhaseDutyCycle (uint32_t clockCycles);
__STATIC_INLINE void SensorBus_MasterSetHighPhaseDutyCycle(uint32_t clockCycles);
#endif /* (SensorBus_ENABLE_MASTER) */

/* Bus status. */
__STATIC_INLINE bool     SensorBus_IsBusBusy(void);

/* Slave functions. */
#if (SensorBus_ENABLE_SLAVE)
__STATIC_INLINE uint32_t SensorBus_SlaveGetStatus(void);

__STATIC_INLINE void     SensorBus_SlaveConfigReadBuf(uint8_t *buffer, uint32_t size);
__STATIC_INLINE void     SensorBus_SlaveAbortRead(void);
__STATIC_INLINE uint32_t SensorBus_SlaveGetReadTransferCount(void);
__STATIC_INLINE uint32_t SensorBus_SlaveClearReadStatus(void);

__STATIC_INLINE void     SensorBus_SlaveConfigWriteBuf(uint8_t *buffer, uint32_t size);
__STATIC_INLINE void     SensorBus_SlaveAbortWrite(void);
__STATIC_INLINE uint32_t SensorBus_SlaveGetWriteTransferCount(void);
__STATIC_INLINE uint32_t SensorBus_SlaveClearWriteStatus(void);
#endif /* (SensorBus_ENABLE_SLAVE) */

/* Master interrupt processing functions. */
#if (SensorBus_ENABLE_MASTER)
__STATIC_INLINE uint32_t SensorBus_MasterGetStatus(void);

__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterRead(cy_stc_scb_i2c_master_xfer_config_t *xferConfig);
__STATIC_INLINE void SensorBus_MasterAbortRead(void);
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterWrite(cy_stc_scb_i2c_master_xfer_config_t *xferConfig);
__STATIC_INLINE void SensorBus_MasterAbortWrite(void);
__STATIC_INLINE uint32_t SensorBus_MasterGetTransferCount(void);

/* Master manual processing functions. */
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterSendStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterSendReStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterSendStop(uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterReadByte(cy_en_scb_i2c_command_t ackNack, uint8_t *byte, uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterWriteByte(uint8_t byte, uint32_t timeoutMs);
#endif /* (SensorBus_ENABLE_MASTER) */

/* Interrupt handler. */
__STATIC_INLINE void SensorBus_Interrupt(void);
/** @} group_general */


/***************************************
*    Variables with External Linkage
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t SensorBus_initVar;
extern cy_stc_scb_i2c_config_t const SensorBus_config;
extern cy_stc_scb_i2c_context_t SensorBus_context;
/** @} group_globals */


/***************************************
*         Preprocessor Macros
***************************************/
/**
* \addtogroup group_macros
* @{
*/
/** The pointer to the base address of the SCB instance */
#define SensorBus_HW     ((CySCB_Type *) SensorBus_SCB__HW)

/** The desired data rate in Hz */
#define SensorBus_DATA_RATE_HZ      (100000U)

/** The frequency of the clock used by the Component in Hz */
#define SensorBus_CLK_FREQ_HZ       (1562500U)

/** The number of Component clocks used by the master to generate the SCL
* low phase. This number is calculated by GUI based on the selected data rate.
*/
#define SensorBus_LOW_PHASE_DUTY_CYCLE   (8U)

/** The number of Component clocks used by the master to generate the SCL
* high phase. This number is calculated by GUI based on the selected data rate.
*/
#define SensorBus_HIGH_PHASE_DUTY_CYCLE  (8U)
/** @} group_macros */


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: SensorBus_Init
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_Init(cy_stc_scb_i2c_config_t const *config)
{
    return Cy_SCB_I2C_Init(SensorBus_HW, config, &SensorBus_context);
}


/*******************************************************************************
*  Function Name: SensorBus_DeInit
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_DeInit(void)
{
    Cy_SCB_I2C_DeInit(SensorBus_HW);
}


/*******************************************************************************
* Function Name: SensorBus_Enable
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_Enable(void)
{
    Cy_SCB_I2C_Enable(SensorBus_HW);
}


/*******************************************************************************
* Function Name: SensorBus_Disable
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Disable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_Disable(void)
{
    Cy_SCB_I2C_Disable(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SetDataRate
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SetDataRate() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SetDataRate(uint32_t dataRateHz, uint32_t scbClockHz)
{
    return Cy_SCB_I2C_SetDataRate(SensorBus_HW, dataRateHz, scbClockHz);
}


/*******************************************************************************
* Function Name: SensorBus_GetDataRate
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_GetDataRate() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_GetDataRate(uint32_t scbClockHz)
{
    return Cy_SCB_I2C_GetDataRate(SensorBus_HW, scbClockHz);
}


/*******************************************************************************
* Function Name: SensorBus_RegisterEventCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_RegisterEventCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_RegisterEventCallback(cy_cb_scb_i2c_handle_events_t callback)
{
    Cy_SCB_I2C_RegisterEventCallback(SensorBus_HW, callback, &SensorBus_context);
}


#if (SensorBus_ENABLE_SLAVE)
/*******************************************************************************
* Function Name: SensorBus_RegisterAddrCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_RegisterAddrCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_RegisterAddrCallback(cy_cb_scb_i2c_handle_addr_t callback)
{
    Cy_SCB_I2C_RegisterAddrCallback(SensorBus_HW, callback, &SensorBus_context);
}
#endif /* (SensorBus_ENABLE_SLAVE) */


/*******************************************************************************
* Function Name: SensorBus_IsBusBusy
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_IsBusBusy() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE bool SensorBus_IsBusBusy(void)
{
    return Cy_SCB_I2C_IsBusBusy(SensorBus_HW);
}


#if (SensorBus_ENABLE_SLAVE)
/*******************************************************************************
* Function Name: SensorBus_SlaveSetAddress
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetAddress() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_SlaveSetAddress(uint8_t addr)
{
    Cy_SCB_I2C_SlaveSetAddress(SensorBus_HW, addr);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveGetAddress
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetAddress() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveGetAddress(void)
{
    return Cy_SCB_I2C_SlaveGetAddress(SensorBus_HW);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveSetAddressMask
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveSetAddressMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_SlaveSetAddressMask(uint8_t addrMask)
{
    Cy_SCB_I2C_SlaveSetAddressMask(SensorBus_HW, addrMask);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveGetAddressMask
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetAddressMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveGetAddressMask(void)
{
    return Cy_SCB_I2C_SlaveGetAddressMask(SensorBus_HW);
}
#endif /* (SensorBus_ENABLE_SLAVE) */

#if (SensorBus_ENABLE_MASTER)
/*******************************************************************************
* Function Name: SensorBus_MasterSetLowPhaseDutyCycle
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSetLowPhaseDutyCycle() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_MasterSetLowPhaseDutyCycle(uint32_t clockCycles)
{
    Cy_SCB_I2C_MasterSetLowPhaseDutyCycle(SensorBus_HW, clockCycles);
}


/*******************************************************************************
* Function Name: SensorBus_MasterSetHighPhaseDutyCycle
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSetHighPhaseDutyCycle() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_MasterSetHighPhaseDutyCycle(uint32_t clockCycles)
{
    Cy_SCB_I2C_MasterSetHighPhaseDutyCycle(SensorBus_HW, clockCycles);
}
#endif /* (SensorBus_ENABLE_MASTER) */


#if (SensorBus_ENABLE_SLAVE)
/*******************************************************************************
* Function Name: SensorBus_SlaveGetStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveGetStatus(void)
{
    return Cy_SCB_I2C_SlaveGetStatus(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveConfigReadBuf
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveConfigReadBuf() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_SlaveConfigReadBuf(uint8_t *buffer, uint32_t size)
{
    Cy_SCB_I2C_SlaveConfigReadBuf(SensorBus_HW, buffer, size, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveAbortRead
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveAbortRead() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_SlaveAbortRead(void)
{
    Cy_SCB_I2C_SlaveAbortRead(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveGetReadTransferCount
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetReadTransferCount() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveGetReadTransferCount(void)
{
    return Cy_SCB_I2C_SlaveGetReadTransferCount(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveClearReadStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveClearReadStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveClearReadStatus(void)
{
    return Cy_SCB_I2C_SlaveClearReadStatus(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveConfigWriteBuf
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveConfigWriteBuf() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_SlaveConfigWriteBuf(uint8_t *buffer, uint32_t size)
{
    Cy_SCB_I2C_SlaveConfigWriteBuf(SensorBus_HW, buffer, size, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveAbortWrite
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveAbortWrite() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_SlaveAbortWrite(void)
{
    Cy_SCB_I2C_SlaveAbortWrite(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveGetWriteTransferCount
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetWriteTransferCount() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveGetWriteTransferCount(void)
{
    return Cy_SCB_I2C_SlaveGetWriteTransferCount(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_SlaveClearWriteStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveClearWriteStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_SlaveClearWriteStatus(void)
{
    return Cy_SCB_I2C_SlaveClearWriteStatus(SensorBus_HW, &SensorBus_context);
}
#endif /* (SensorBus_ENABLE_SLAVE) */


#if (SensorBus_ENABLE_MASTER)
/*******************************************************************************
* Function Name: SensorBus_MasterGetStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterGetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_MasterGetStatus(void)
{
    return Cy_SCB_I2C_MasterGetStatus(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterRead
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterRead() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterRead(cy_stc_scb_i2c_master_xfer_config_t *xferConfig)
{
    return Cy_SCB_I2C_MasterRead(SensorBus_HW, xferConfig, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterAbortRead
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterAbortRead() PDL driver function.
*
******************************************************************************/
__STATIC_INLINE void SensorBus_MasterAbortRead(void)
{
    Cy_SCB_I2C_MasterAbortRead(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterWrite
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterWrite() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterWrite(cy_stc_scb_i2c_master_xfer_config_t *xferConfig)
{
    return Cy_SCB_I2C_MasterWrite(SensorBus_HW, xferConfig, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterAbortWrite
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterAbortWrite() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_MasterAbortWrite(void)
{
    Cy_SCB_I2C_MasterAbortWrite(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterGetTransferCount
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterGetTransferCount() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t SensorBus_MasterGetTransferCount(void)
{
    return Cy_SCB_I2C_MasterGetTransferCount(SensorBus_HW, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterSendStart
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSendStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterSendStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterSendStart(SensorBus_HW, address, bitRnW, timeoutMs, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterSendReStart
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSendReStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterSendReStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterSendReStart(SensorBus_HW, address, bitRnW, timeoutMs, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterSendStop
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSendStop() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterSendStop(uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterSendStop(SensorBus_HW, timeoutMs, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterReadByte
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterReadByte() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterReadByte(cy_en_scb_i2c_command_t ackNack, uint8_t *byte, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterReadByte(SensorBus_HW, ackNack, byte, timeoutMs, &SensorBus_context);
}


/*******************************************************************************
* Function Name: SensorBus_MasterWriteByte
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterWriteByte() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t SensorBus_MasterWriteByte(uint8_t byte, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterWriteByte(SensorBus_HW, byte, timeoutMs, &SensorBus_context);
}
#endif /* (SensorBus_ENABLE_MASTER) */


/*******************************************************************************
* Function Name: SensorBus_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SensorBus_Interrupt(void)
{
    Cy_SCB_I2C_Interrupt(SensorBus_HW, &SensorBus_context);
}

#if defined(__cplusplus)
}
#endif

#endif /* SensorBus_CY_SCB_I2C_PDL_H */


/* [] END OF FILE */
