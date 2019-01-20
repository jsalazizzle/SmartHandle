#ifndef TXBUFFER_H
#define TXBUFFER_H
    
#include <project.h>
#include <stdbool.h>
#include <stdlib.h>

//-------------------------------------------------------------//
    
#define TX_BUFFER_SIZE 1000 // Number of bytes in circular buffer

//-------------------------------------------------------------//
    
void TxBuffer_Init();

bool TxBuffer_MemoryToBuffer(uint32 num_bytes, uint8 *data);
bool TxBuffer_BufferToMemory(uint32 num_bytes, uint8 *data);

//-------------------------------------------------------------//

#endif /* TXBUFFER_H */