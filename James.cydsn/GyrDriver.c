
#include <GyrDriver.h>
#include <DataBuffer.h>
#include <KinOS.h>

#include "debug.h"

struct dGyr20Slot* wsample;
uint8* wsample_ptr;

void GyrDriver_Init()
{
    wsample = (struct dGyr20Slot*) malloc(sizeof(struct dGyr20Slot));
    return;
}
bool GyrDriver_OperationDone()
{
    static uint8 state = 0;
    if(state == 7)
    {
        DEBUG_PRINTF("GyrDriver_OperationDone, state 7 \r\n");
        DEBUG_WAIT_UART_TX_COMPLETE();
        state = 0;
        return true;
    }
    else
    {
        DEBUG_PRINTF("GyrDriver_OperationDone \r\n");
        DEBUG_WAIT_UART_TX_COMPLETE();
        state++;
        return false;
    }
//    //ACC slot
//    wsample->x_msb = 1; wsample->x_lsb = 1;
//    wsample->y_msb = 2; wsample->y_lsb = 3;
//    wsample->z_msb = 4; wsample->z_lsb = 5;
//    wsample_ptr = (uint8*) wsample;
//    if(DataBuffer_OpenWriteSlot((uint8**)&wsample_ptr,GYR20SLOT, sizeof(struct dGyr20Slot)))
//    {
//        //Debug2_Write(1);
//        DataBuffer_CloseWriteSlot((uint8**)&wsample_ptr,GYR20SLOT);
//        //Debug2_Write(0);
//    }
//    return true;
}
int32 GyrDriver_UpdateSetting(uint8 setting_type, int32 setting_value)
{
    return 5000;
}