#include <DataBuffer.h>

#include "debug.h"

static uint8 *job_queue; // Circular buffer pointer
static uint8 jobs = 0; // Active Jobs
static uint32 head = 0; // Buffer Head
static uint32 tail = 0; // Buffer Tail
static uint32 size = 0; // Buffer Size

void DataBuffer_Init()
{
    job_queue = (uint8*) malloc(JOB_BUFFER_SIZE);

    uint8 *body;
    
    for(uint8 byte = 0; byte < JOB_BUFFER_SIZE; byte++)
    {             
        body = (uint8*)(job_queue + (byte) );
        *body = 0x00; // Set body to 0x00 for all slots
    }
    jobs = 0; // Reset jobs
    head = 0; // Reset head
    tail = 0; // Reset tail
    size = 0; // Reset size
    
    for(uint8 type = 1; type<NUM_OF_SENSORS+1; type++)
    {
        DataBuffer_SetNumerator(1,type); // Set numerator of all sensors to 1
        DataBuffer_SetDenominator(1,type); // Set denominator of all sensors to 1
    }
}
uint8 DataBuffer_QueryNextJob()
{
    uint8 *status = (uint8*)(job_queue + tail);
    
    bool locked = (*status >> 7) & 0x01; // Status Bit 8
    bool valid  = (*status >> 6) & 0x01; // Status Bit 7
    uint8 type  = (*status >> 0) & 0x3F; // Data Type
    
    if(!locked && valid)
    {
        return type;
    }
    return EMPTYSLOT;
}
bool DataBuffer_OpenWriteSlot(uint8** sample, uint8 type, uint32 num_bytes)
{
    if( num_bytes > (JOB_BUFFER_SIZE - size) )
    {
        return false; // Cant fit
    }
    size = size + num_bytes;
    
    uint8* tmp  = (uint8*)(job_queue + head); // Points to reserved byte
    bool locked = (*tmp >> 7) & 0x01;         // Status Bit 8
    bool valid  = (*tmp >> 6) & 0x01;         // Status Bit 7
    bool result = (!locked && !valid);
    
    if(result)
    {           
        *tmp = 0x80 | type; // Locked and Invalid        
        
        uint8* buffer_ptr;
        uint8* sample_ptr = (uint8*) *sample; 
		if(++head == JOB_BUFFER_SIZE) head = 0;
        
		for(uint32 index=0; index<(num_bytes-1); index++)
		{
			buffer_ptr = (uint8*)(job_queue + head);
			*buffer_ptr = *(sample_ptr + index + 1);
            
			if(++head == JOB_BUFFER_SIZE) head = 0;
		}        
        *sample = tmp;
        // Sample pointer points to location of tmp in the buffer
    }
    else
    {
        *sample = NULL;
        // Log Error
    }
    return(result);
}
bool DataBuffer_CloseWriteSlot(uint8** sample, uint8 type)
{    
    uint8* tmp = *sample;
    if((*tmp & 0x3F) != type) // Type mismatch
    {
        return false;
        // Log Error
    }
    *tmp = 0x40 | type; // Unlocked and Valid
    jobs = jobs + 1;
    
    return true;
}
bool DataBuffer_OpenReadSlot(uint8** sample, uint8 type, uint32 num_bytes)
{   
    uint8* tracker_ptr = *sample;
    uint8* tmp = (uint8*)(job_queue + tail);
    
    if((*tmp & 0x3F) != type)
    {
        return false;
        // Log Error
    }
    if (num_bytes > size)
    {
        return false;
    }
    size = size - num_bytes;
    
    bool locked = (*tmp >> 7) & 0x01;    // Status Bit 8
    bool valid  = (*tmp >> 6) & 0x01;    // Status Bit 7
    bool result = (!locked && valid);
    
    if(result)
    {
        *tmp = 0xC0 | type; // Locked and Valid       
        
        uint8* buffer_ptr = (uint8*) job_queue;
        uint8* sample_ptr;
        uint8* sample_init = (uint8*) *sample;
        if(++tail == JOB_BUFFER_SIZE) tail = 0;
        
        for(uint32 index=0; index<(num_bytes-1); index++)
		{
            sample_ptr = (uint8*) (sample_init + index + 1);
            *sample_ptr = *(buffer_ptr + tail);
            *(buffer_ptr + tail) = 0;
            
			if(++tail == JOB_BUFFER_SIZE) tail = 0;
		}
        *sample = tmp;
    }
    else
    {
        *sample = NULL;
    }
    return(result);
}
bool DataBuffer_CloseReadSlot(uint8** sample, uint8 type)
{   
    uint8* tmp = *sample;
    if((*tmp & 0x3F) != type) // Type mismatch
    {
        return false;
        // Log Error
    }
    *tmp = 0x00 | EMPTYSLOT; // Unlocked and Invalid
    jobs = jobs - 1; 
    return true;
}

uint8 DataBuffer_GetNumerator(uint8 type)
{
    return numerators[type-1];
}
void DataBuffer_SetNumerator(uint8 num, uint8 type)
{
    numerators[type-1] = num;
}

uint8 DataBuffer_GetDenominator(uint8 type)
{
    return denominators[type-1];
}
void DataBuffer_SetDenominator(uint8 den, uint8 type)
{
    denominators[type-1] = den;
}