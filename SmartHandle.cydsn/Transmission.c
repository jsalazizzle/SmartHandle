
#include <Transmission.h>
#include <TxBuffer.h>
#include <RxBuffer.h>
#include <ErrorLogService.h>
#include <UseProfileService.h>
#include <SystemCore.h>

#include "project.h"

#include "debug.h"

//-------------------------------------------------------------//

bool is_advertising = false; // Global to KinOS.c
bool is_connected = false;  // Global to KinOS.cBL

#define NUM_BYTES_PER_PACKET 1

//-------------------------------------------------------------//
//-------------------BLUETOOTH-EVENT-HANDLING------------------//
//-------------------------------------------------------------//


void Transmission_EventHandler(uint32 eventCode, void *eventParam)
{
    bool was_advertising = is_advertising;
    bool was_connected = is_connected;
    
    static cy_stc_ble_gap_peer_addr_info_t bondedDeviceInfo[CY_BLE_MAX_BONDED_DEVICES];
    static cy_stc_ble_gap_bonded_device_list_info_t bondedDeviceList =
    {
        .bdHandleAddrList = bondedDeviceInfo
    };
    
    switch( eventCode )
    {
        case CY_BLE_EVT_STACK_ON:
        {
            cy_stc_ble_gap_bd_addr_info_t addr; addr.addrType = 0x00;
            Cy_BLE_GAP_GenerateBdAddress(&addr);
            
            cy_stc_ble_gap_bd_addr_t bdAddress = addr.gapBdAddr;
            uint64 val0 = bdAddress.bdAddr[0];
            uint64 val1 = bdAddress.bdAddr[1];
            uint64 val2 = bdAddress.bdAddr[2];
            uint64 val3 = bdAddress.bdAddr[3];
            uint64 val4 = bdAddress.bdAddr[4];
            uint64 val5 = bdAddress.bdAddr[5];
            
            uint64 code = ((uint64)bdAddress.bdAddr[0]<< 0)|((uint64)bdAddress.bdAddr[1]<<8 )|
                          ((uint64)bdAddress.bdAddr[2]<<16)|((uint64)bdAddress.bdAddr[3]<<24)|
                          ((uint64)bdAddress.bdAddr[4]<<32)|((uint64)bdAddress.bdAddr[5]<<40);
            
            uint16 id = (uint16)(code % 9973);
            
            char8 N1 = (((id & 0xF000) >> 12)%9) + '0';
            char8 N2 = (((id & 0x0F00) >> 8) %9) + '0';
            char8 N3 = (((id & 0x00F0) >> 4) %9) + '0';
            char8 N4 = (((id & 0x000F) >> 0) %9) + '0';
                        
            char8 name[11] = {'K','i','n','o','X','i','-',N1,N2,N3,N4};
            Cy_BLE_SetLocalName(name);
            break;
        }
        case CY_BLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
        {
            is_advertising = (Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_ADVERTISING);
            DEBUG_PRINTF("CY_BLE_EVT_GAPP_ADVERTISEMENT_START_STOP %u \r\n", (uint8)is_advertising);
            DEBUG_WAIT_UART_TX_COMPLETE();
			break;
        }
        case CY_BLE_EVT_GATT_CONNECT_IND:
        {
            is_advertising = false;
            is_connected = true;
            break;
        }
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
        {
            is_connected = false;
			break;
        }
        // Event occurs every bluetooth connection attempt by remote device
        case CY_BLE_EVT_GAP_ENHANCE_CONN_COMPLETE:
        {
            bool deviceStored = false;

            // See if remote device's information is already bonded (stored into flash)
            cy_en_ble_api_result_t apiResult = Cy_BLE_GAP_GetBondList(&bondedDeviceList);
            if(apiResult == CY_BLE_SUCCESS)
            {
                uint8 deviceCount = bondedDeviceList.noOfDevices;
                if(deviceCount > 0)
                {
                    for(uint8 i=0; i<deviceCount; i++)
                    {
                        if(cy_ble_connHandle[0].bdHandle == bondedDeviceList.bdHandleAddrList[i].bdHandle)
                        {
                            deviceStored = true;
                            break;
                        }
                    }
                }
            }
            
            // Initiate bonding/pairing process if remote device's information isn't already bonded
            if(!deviceStored)
            {
                if((cy_ble_configPtr->authInfo[CY_BLE_SECURITY_CONFIGURATION_0_INDEX].security & CY_BLE_GAP_SEC_LEVEL_MASK) > CY_BLE_GAP_SEC_LEVEL_1)
                {
                    cy_ble_configPtr->authInfo[CY_BLE_SECURITY_CONFIGURATION_0_INDEX].bdHandle = cy_ble_connHandle[0].bdHandle;
                    cy_en_ble_api_result_t apiResult = Cy_BLE_GAP_AuthReq(&cy_ble_configPtr->authInfo[CY_BLE_SECURITY_CONFIGURATION_0_INDEX]);
                }
            }
            break;
        }
        // Event occurs when remote device sends inbound data
        case CY_BLE_EVT_GATTS_WRITE_REQ:
        {
            cy_stc_ble_gatts_write_cmd_req_param_t *wrReqParam = (cy_stc_ble_gatts_write_cmd_req_param_t *) eventParam;
                        
            // Check which characteristic was updated by remote device
            if(wrReqParam->handleValPair.attrHandle == CY_BLE_DEVICE_INTERFACE_INBOUND_CHAR_HANDLE)
            {
                // Buffer received data
                uint32 len = wrReqParam->handleValPair.value.len;
                uint8 msg[len];
                for(uint32 i=0; i<len; i++)
                {
                    msg[i] = wrReqParam->handleValPair.value.val[CY_BLE_DEVICE_INTERFACE_INBOUND_CHAR_INDEX+i];
                }
                RxBuffer_MemoryToBuffer(len,msg);
                
                // Handle received data
                NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);
            }
            else if(wrReqParam->handleValPair.attrHandle == CY_BLE_DEVICE_ERROR_LOG_CLEAR_LOG_CHAR_HANDLE)
            {
                if(wrReqParam->handleValPair.value.val[0] == 0x01)
                {
//                    ErrorLogService_AppHandler();
                }
                else if(wrReqParam->handleValPair.value.val[0] == 0x02)
                {
//                    ErrorLogService_KinosHandler();
                }
            }
            else if(wrReqParam->handleValPair.attrHandle == CY_BLE_DEVICE_USE_PROFILE_CLEAR_LOG_CHAR_HANDLE)
            {
//                UseProfileService_Handler();
            }
            Cy_BLE_GATTS_WriteRsp(cy_ble_connHandle[0]);
            break;
        }
        // Event occurs in response to bonding request by remote device (initiated in CY_BLE_EVT_GAP_ENHANCE_CONN_COMPLETE)
        case CY_BLE_EVT_GAP_AUTH_REQ:
        {           
            cy_ble_configPtr->authInfo[CY_BLE_SECURITY_CONFIGURATION_0_INDEX].bdHandle = ((cy_stc_ble_gap_auth_info_t *)eventParam)->bdHandle;
            cy_en_ble_api_result_t apiResult = Cy_BLE_GAPP_AuthReqReply(&cy_ble_configPtr->authInfo[CY_BLE_SECURITY_CONFIGURATION_0_INDEX]);            
            
            // Remove oldest bonded device if bonded list full then re-reply 
            if(apiResult != CY_BLE_SUCCESS)
            {
                Cy_BLE_GAP_RemoveOldestDeviceFromBondedList();
                apiResult = Cy_BLE_GAPP_AuthReqReply(&cy_ble_configPtr->authInfo[CY_BLE_SECURITY_CONFIGURATION_0_INDEX]);
            }
            break;
        }
        // Miscallaneous events
        case CY_BLE_EVT_TIMEOUT:                        // 0x1001u
        {
            break;
        }
        case CY_BLE_EVT_PENDING_FLASH_WRITE:            // 0x1004u
        {
            break;
        }
        case CY_BLE_EVT_LE_SET_EVENT_MASK_COMPLETE:     // 0x2004u
        {
            break;
        }
        case  CY_BLE_EVT_SET_DEVICE_ADDR_COMPLETE:      // 0x3002u
        {
            break;
        }
        case CY_BLE_EVT_SET_TX_PWR_COMPLETE:            // 0x3006u
        {
            break;
        }
        case CY_BLE_EVT_GAP_AUTH_COMPLETE:              // 0x4004u
        {
            break;
        }
        case CY_BLE_EVT_GAP_ENCRYPT_CHANGE:             // 0x4009u
        {
            break;
        }
        case CY_BLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE: // 0x400au
        {
            break;
        }
        case CY_BLE_EVT_GAP_KEYINFO_EXCHNGE_CMPLT:      // 0x400cu
        {
            break;
        }
        case CY_BLE_EVT_GAP_SMP_NEGOTIATED_AUTH_INFO:   // 0x4012u
        {
            break;
        }
        case CY_BLE_EVT_GAP_DEVICE_ADDR_GEN_COMPLETE:   // 0x4013u
        {
            break;
        }
        case CY_BLE_EVT_GATT_DISCONNECT_IND:            // 0x5002u
        {
            break;
        }
        case CY_BLE_EVT_GATTS_XCNHG_MTU_REQ:            // 0x5003u
        {
            break;
        }
        case CY_BLE_EVT_GATTS_READ_CHAR_VAL_ACCESS_REQ: // 0x5017u
        {
            break;
        }
        default:
        {
            DEBUG_PRINTF("Ble Event: %lx \r\n", (unsigned long) eventCode);
            DEBUG_WAIT_UART_TX_COMPLETE();
            break;
        }
    }
    if((was_advertising != is_advertising) || (was_connected != is_connected))
    {
        NVIC_SetPendingIRQ(AppControl_IRQ_cfg.intrSrc);
    }
}
void Transmission_BleSsHandler()
{
    // Check for pending bluetooth events, triggers Transmission_EventHandler()
    Cy_BLE_ProcessEvents();
    
    // Send data to remote device if data available in buffer
    static uint8 data[NUM_BYTES_PER_PACKET];
    if(is_connected)
    {
        if(Cy_BLE_GATT_GetBusyStatus(cy_ble_connHandle[0].attId) == CY_BLE_STACK_STATE_FREE)
        {      
            if(TxBuffer_BufferToMemory(NUM_BYTES_PER_PACKET,(uint8*)&data))
            {
                cy_stc_ble_gatts_handle_value_ntf_t ntfHandle =
                {
                    .connHandle = cy_ble_connHandle[0],
                    .handleValPair.attrHandle = CY_BLE_DEVICE_INTERFACE_OUTBOUND_CHAR_HANDLE,
                    .handleValPair.value.val = (uint8*)data,
                    .handleValPair.value.len = (NUM_BYTES_PER_PACKET)*sizeof(uint8)
                };
                Cy_BLE_GATTS_Notification(&ntfHandle);
            }
        }
    }
    
    // Bond remote device's information into flash (initiated in CY_BLE_EVT_GAP_AUTH_REQ)
    if(cy_ble_pendingFlashWrite != 0u)
    {   
        cy_en_ble_api_result_t apiResult = Cy_BLE_StoreBondingData();
    }
}
//-------------------------------------------------------------//
//---------------------INBOUND-SERIAL-DATA---------------------//
//-------------------------------------------------------------//

bool Transmission_CheckInbox(uint32 num_bytes, uint8 *data)
{
    return RxBuffer_BufferToMemory(num_bytes, data);
}
//-------------------------------------------------------------//
//--------------------OUTBOUND-SERIAL-DATA---------------------//
//-------------------------------------------------------------//

bool Transmission_SendResult(uint32 num_bytes, uint8 *data)
{
    return TxBuffer_MemoryToBuffer(num_bytes, data);
}
//-------------------------------------------------------------//
//----------------------CUSTOM-ADVERTISING---------------------//
//-------------------------------------------------------------//

bool Transmission_Advertise(uint16 timeout_s, uint16 interval_ms)
{
    if(interval_ms < 20) return false; // Interval limit set by Cypress
    if(timeout_s < (interval_ms/1000)) return false;
    
    if(!is_connected && !is_advertising)
    {
        uint32 interval = ((uint32)interval_ms*1000)/625;
        
        cy_ble_config.discoveryModeInfo->advTo = timeout_s;
        cy_ble_config.discoveryModeInfo->advParam->advIntvMin = (uint16)interval;
        cy_ble_config.discoveryModeInfo->advParam->advIntvMax = (uint16)interval+1;
        
        cy_en_ble_api_result_t apiResult = Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_CUSTOM,CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
        if(apiResult == CY_BLE_SUCCESS)
        {
            Cy_BLE_ProcessEvents();
        }
        else
        {
            // Throw error
        }
    }
    return is_advertising;
}
bool Transmission_Disconnect()
{
    cy_stc_ble_gap_disconnect_info_t disconnectInfo =
    {
        .reason = 0x13,
        .bdHandle = cy_ble_connHandle[0].bdHandle
    };
    return (Cy_BLE_GAP_Disconnect(&disconnectInfo) == CY_BLE_SUCCESS);
}

void Transmission_SendAcc(acc_sample* acc_data)
{
    // Check for pending bluetooth events, triggers Transmission_EventHandler()
    //Cy_BLE_ProcessEvents();
    
    // Send data to remote device if data available in buffer
    //static uint8 data[NUM_BYTES_PER_PACKET];
    if(is_connected)
    {
        if(Cy_BLE_GATT_GetBusyStatus(cy_ble_connHandle[0].attId) == CY_BLE_STACK_STATE_FREE)
        {   
            uint8 x_val[2] = { (uint8) (acc_data->x_raw >> 8), (uint8) (acc_data->x_raw & 0xFF)};
            uint8 y_val[2] = { (uint8) (acc_data->y_raw >> 8), (uint8) (acc_data->y_raw & 0xFF)};
            uint8 z_val[2] = { (uint8) (acc_data->z_raw >> 8), (uint8) (acc_data->z_raw & 0xFF)};
            
            /*cy_stc_ble_gatt_value_t x_data = { .val = x_val, .len = 2};
            cy_stc_ble_gatt_value_t y_data = { .val = y_val, .len = 2};
            cy_stc_ble_gatt_value_t z_data = { .val = z_val, .len = 2};
            
            cy_stc_ble_gatt_handle_value_pair_t x_handleVal =
            {
                .value = x_data,
                .attrHandle = CY_BLE_DEVICE_INTERFACE_ACCEL_X_CHAR_HANDLE
            };
            
            cy_stc_ble_gatt_handle_value_pair_t y_handleVal =
            {
                .value = y_data,
                .attrHandle = CY_BLE_DEVICE_INTERFACE_ACCEL_Y_CHAR_HANDLE
            };
            
            cy_stc_ble_gatt_handle_value_pair_t z_handleVal =
            {
                .value = z_data,
                .attrHandle = CY_BLE_DEVICE_INTERFACE_ACCEL_Z_CHAR_HANDLE
            };
            
            Cy_BLE_GATTS_SendNotification(&cy_ble_connHandle[0],&x_handleVal);
            Cy_BLE_GATTS_SendNotification(&cy_ble_connHandle[0],&y_handleVal);
            Cy_BLE_GATTS_SendNotification(&cy_ble_connHandle[0],&z_handleVal);*/
            
            cy_stc_ble_gatts_handle_value_ntf_t ntfHandle =
            {
                .connHandle = cy_ble_connHandle[0],
                .handleValPair.attrHandle = CY_BLE_DEVICE_INTERFACE_ACCEL_X_CHAR_HANDLE,
                .handleValPair.value.val = x_val,
                .handleValPair.value.len = (2)*sizeof(uint8)
            };
            
            Cy_BLE_GATTS_Notification(&ntfHandle);
        }
    }
    
    // Bond remote device's information into flash (initiated in CY_BLE_EVT_GAP_AUTH_REQ)
    if(cy_ble_pendingFlashWrite != 0u)
    {   
        cy_en_ble_api_result_t apiResult = Cy_BLE_StoreBondingData();
    }
}





//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void Transmission_Init()
{
    TxBuffer_Init();
    RxBuffer_Init();
    
    cy_en_ble_api_result_t apiResult = Cy_BLE_Start(Transmission_EventHandler);
    if (apiResult == CY_BLE_SUCCESS)
    {
        Cy_BLE_BAS_Init(cy_ble_basConfigPtr);
        Cy_BLE_ProcessEvents();
        Cy_BLE_RegisterAppHostCallback(Transmission_BleSsHandler); // Callback function for bless interrupt
    }
    else
    {
        // Throw error
    }
    
    DEBUG_PRINTF("Transmission_Init 1 \r\n");
    DEBUG_WAIT_UART_TX_COMPLETE();    
}
//-------------------------------------------------------------//
