#ifndef USEPROFILING_H
#define USEPROFILING_H

//-----------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <stdlib.h>
    
//-----------------------------------------//

#define NUM_STATS               20u         
#define ALPHA                   0.99
    
enum StatTypes
{   
    STAT_POWER_EVENT_COUNT,
    STAT_POWER_TOTAL_TIME, 
    STAT_BATTERY_AVG,
    STAT_BATTERY_MIN,
    
    STAT_ADVERT_EVENT_COUNT, 
    STAT_ADVERT_DURATION, 
    STAT_CONN_EVENT_COUNT,
    STAT_CONN_DURATION,
    STAT_RX_BUFFER_AVG,
    STAT_RX_BUFFER_MAX,
    STAT_TX_BUFFER_AVG,
    STAT_TX_BUFFER_MAX,
    
    STAT_LOCAL_BUS_EVENT_COUNT, 
    STAT_LOCAL_BUS_DURATION,    
    STAT_DATA_BUFFER_AVG,
    STAT_DATA_BUFFER_MAX,
    
    STAT_SHAKE_DURATION,
    STAT_INTERFACE_EVENT_COUNT,
    STAT_INTERFACE_DURATION,
    
    STAT_ERROR_EVENT_COUNT
};

struct UsageTemplate
{
    uint32 PoweredCount;
    uint32 PoweredDuration;
    uint32 BatteryMin;
    uint32 BatteryAvg;
   
    uint32 AdvertisementCount;
    uint32 AdvertisementDuration; 
    uint32 ConnectionCount;
    uint32 ConnectionDuration;
    uint32 RxBufferAvg;
    uint32 RxBufferMax;
    uint32 TxBufferAvg;
    uint32 TxBufferMax;
    
    uint32 LocalBusCount;
    uint32 LocalBusDuration;    
    uint32 DataBufferAvg;
    uint32 DataBufferMax;
    
    uint32 ShakeCount;
    uint32 InterfaceCount;
    uint32 InterfaceDuration;
    
    uint32 ErrorCount;
};

//-----------------------------------------//

void UseProfiling_Tick(void);
void UseProfiling_PowerEvent(void);
void UseProfiling_ConnectionEvent(void);
void UseProfiling_AdvertisementEvent(void);
void UseProfiling_LocalBusEvent(void);
void UseProfiling_InterfaceEvent(void);
void UseProfiling_ErrorEvent(void);
void UseProfiling_Clear(void);
uint32 UseProfiling_GetRandomPeriod(void);
void UseProfiling_Init(void);

//-----------------------------------------//

#endif /* USEPROFILING_H */
