/***************************************************************************//**
* \file CY_BLE_lns_config.c
* \version 2.0
* 
* \brief
*  This file contains the source code of initialization of the config structure
*  for the Location And Navigation Service.
*
********************************************************************************
* \copyright
* Copyright 2017-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ble/cy_ble_lns.h"

#if(CY_BLE_MODE_PROFILE && defined(CY_BLE_LNS))

#ifdef CY_BLE_LNS_SERVER
static const cy_stc_ble_lnss_t cy_ble_lnss =
{
    0x0029u,    /* Handle of the LNS service */
    {
        
        /* LN Feature characteristic */
        {
            0x002Bu, /* Handle of the LN Feature characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Location and Speed characteristic */
        {
            0x002Du, /* Handle of the Location and Speed characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x002Eu, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* Position Quality characteristic */
        {
            0x0030u, /* Handle of the Position Quality characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* LN Control Point characteristic */
        {
            0x0032u, /* Handle of the LN Control Point characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0033u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* Navigation characteristic */
        {
            0x0035u, /* Handle of the Navigation characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0036u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
    },
};
#endif /* CY_BLE_LNS_SERVER */

/**
* \addtogroup group_globals
* @{
*/

/** The configuration structure for the Location and Navigation Service. */
cy_stc_ble_lns_config_t cy_ble_lnsConfig =
{
    /* Service GATT DB handles structure */
    #ifdef CY_BLE_LNS_SERVER
    .lnss = &cy_ble_lnss,
    #else
    .lnss = NULL,
    #endif /* CY_BLE_LNS_SERVER */

    /* An application layer event callback function to receive service events from the BLE Component. */
    .callbackFunc = NULL,
};

/** @} group_globals */

#endif /* (CY_BLE_MODE_PROFILE && defined(CY_BLE_LNS)) */

/* [] END OF FILE */
