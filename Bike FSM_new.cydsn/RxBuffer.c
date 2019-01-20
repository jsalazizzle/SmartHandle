
#include <RxBuffer.h>
#include <KinOS.h>

//-------------------------------------------------------------//

static uint8 *buffer; // Circular Buffer
static uint32 head = 0; // Buffer Head
static uint32 tail = 0; // Buffer Tail
static uint32 size = 0; // Buffer Size

//-------------------------------------------------------------//
//------------------------DATA-TRANSFER------------------------//
//-------------------------------------------------------------//

bool RxBuffer_MemoryToBuffer(uint32 num_bytes, uint8 *data)
{    
    if( num_bytes > (RX_BUFFER_SIZE-size) ) 
    {
        return false; // Cant fit
    }
    size = size + num_bytes;
    
    static uint8 *ptr;
    uint32 offset = head;
    
    for( uint32 i=0; i<num_bytes; i++ )
    {
        ptr = (uint8*)(buffer + offset);
        *ptr = data[i];
        
        if( ++offset == RX_BUFFER_SIZE ) offset = 0;
    }
    head = offset;
    
    return true;
}
bool RxBuffer_BufferToMemory(uint32 num_bytes, uint8 *data)
{
    if (num_bytes > size)
    {
        return false;
    }
    size = size - num_bytes;
    
    static uint8 *ptr;
    uint32 offset = tail;
    
    for( uint32 i=0; i<num_bytes; i++ )
    {
        ptr = (uint8*)(buffer + offset);
        data[i] = *ptr;
        
        if( ++offset == RX_BUFFER_SIZE ) offset = 0;
    }
    tail = offset;
    
    return true;
}
//-------------------------------------------------------------//
//------------------------INITIALIZATION-----------------------//
//-------------------------------------------------------------//

void RxBuffer_Init()
{
    buffer = (uint8*) malloc(RX_BUFFER_SIZE);
    head = 0;
    tail = 0;
    
    uint8 *ptr;
    for(uint32 offset = 0; offset < RX_BUFFER_SIZE; offset++)
    {
        ptr = (uint8*)(buffer + offset);
        *ptr = 0x00;
    }
}
//-------------------------------------------------------------//
