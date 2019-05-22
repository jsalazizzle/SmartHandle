/***************************************************************************//**
* \file CY_BLE_cscs_config.c
* \version 2.0
* 
* \brief
*  This file contains the source code of initialization of the config structure
*  for the Cycling Speed and Cadence Service.
*
********************************************************************************
* \copyright
* Copyright 2017-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "ble/cy_ble_cscs.h"

#if(CY_BLE_MODE_PROFILE && defined(CY_BLE_CSCS))

#ifdef CY_BLE_CSCS_SERVER

static const cy_stc_ble_cscss_t cy_ble_cscss =
{
    0x0029u,    /* Handle of the CSCS service */
    {
        
        /* CSC Measurement characteristic */
        {
            0x002Bu, /* Handle of the CSC Measurement characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x002Cu, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* CSC Feature characteristic */
        {
            0x002Eu, /* Handle of the CSC Feature characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Sensor Location characteristic */
        {
            0x0030u, /* Handle of the Sensor Location characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* SC Control Point characteristic */
        {
            0x0032u, /* Handle of the SC Control Point characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0033u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
    },
};
#endif /* CY_BLE_CSCS_SERVER */

/**
* \addtogroup group_globals
* @{
*/

/** The configuration structure for the Cycling Speed and Cadence Service. */
cy_stc_ble_cscs_config_t cy_ble_cscsConfig =
{
    /* Service GATT DB handles structure */
    #ifdef CY_BLE_CSCS_SERVER
    .cscss = &cy_ble_cscss,
    #else
    .cscss = NULL,
    #endif /* CY_BLE_CSCS_SERVER */

    /* An application layer event callback function to receive service events from the BLE Component. */
    .callbackFunc = NULL,
};

/** @} group_globals */

#endif /* (CY_BLE_MODE_PROFILE && defined(CY_BLE_CSCS)) */

/* [] END OF FILE */
