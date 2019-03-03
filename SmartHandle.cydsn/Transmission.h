#ifndef TRANSMISSION_H
#define TRANSMISSION_H

//-------------------------------------------------------------//

#include <project.h>
#include <stdbool.h>
    
//-------------------------------------------------------------//
    
void Transmission_Init();
void Transmission_EventHandler(uint32 eventCode, void *eventParam);
void Transmission_BleSsHandler();
bool Transmission_CheckInbox(uint32 num_bytes, uint8 *data);
bool Transmission_SendResult(uint32 num_bytes, uint8 *data);
void Transmission_SendNotification();
bool Transmission_Advertise(uint16 timeout_s, uint16 interval_ms);
bool Transmission_Disconnect();

//-------------------------------------------------------------//

#endif /* TRANSMISSION_H */
