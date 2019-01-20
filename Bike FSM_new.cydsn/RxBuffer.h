#ifndef RXBUFFER_H
#define RXBUFFER_H
    
#include <project.h>
#include <stdbool.h>
#include <stdlib.h>

//-------------------------------------------------------------//
    
#define RX_BUFFER_SIZE 100 // Number of bytes in circular buffer

//-------------------------------------------------------------//
    
void RxBuffer_Init();

bool RxBuffer_MemoryToBuffer(uint32 num_bytes, uint8 *data);
bool RxBuffer_BufferToMemory(uint32 num_bytes, uint8 *data);

//-------------------------------------------------------------//

#endif /* RXBUFFER_H */