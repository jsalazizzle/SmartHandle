/***************************************************************************//**
* \file CY_BLE_cts_config.c
* \version 2.0
* 
* \brief
*  This file contains the source code of initialization of the config structure
*  for the Current Time Service of the BLE Component.
*
********************************************************************************
* \copyright
* Copyright 2017-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "ble/cy_ble_cts.h"

#if(CY_BLE_MODE_PROFILE && defined(CY_BLE_CTS))

#ifdef CY_BLE_CTS_SERVER

static const cy_stc_ble_ctss_t cy_ble_ctss =
{
    0x0024u,    /* Handle of the CTS service */
    0x0026u,    /* Handle of the Current Time characteristic */
    0x0027u,    /* Handle of the Client Characteristic Configuration descriptor */
    0x0029u,    /* Handle of the Local Time Information characteristic */
    0x002Bu,    /* Handle of the Reference Time Information characteristic */
};
#endif /* (CY_BLE_CTS_SERVER) */

/**
* \addtogroup group_globals
* @{
*/

/** The configuration structure for the Current Time Service. */
cy_stc_ble_cts_config_t cy_ble_ctsConfig =
{
    /* Service GATT DB handles structure */
    #ifdef CY_BLE_CTS_SERVER
    .ctss = &cy_ble_ctss,
    #else
    .ctss = NULL,
    #endif /* CY_BLE_CTS_SERVER */

    /* An application layer event callback function to receive service events from the BLE Component. */
    .callbackFunc = NULL,
};

/** @} group_globals */

#endif /* (CY_BLE_MODE_PROFILE && defined(CY_BLE_CTS)) */

/* [] END OF FILE */
