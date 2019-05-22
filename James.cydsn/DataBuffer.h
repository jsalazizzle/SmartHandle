#ifndef DATABUFFER_H
#define DATABUFFER_H

#include <project.h>
#include <stdbool.h>
#include <stdlib.h>

//-----------------Public------------------//

#define JOB_BUFFER_SIZE   255 // number of buffer slots
#define NUM_OF_SENSORS    10

uint32 numerators[NUM_OF_SENSORS];
uint32 denominators[NUM_OF_SENSORS];


enum DataType
{
    EMPTYSLOT,  // Empty slot
    GYR20SLOT,  // Gyroscope
    ACC1ESLOT,  // Accelerometer
    MAG0ESLOT,  // Magnetometer
    POX57SLOT,  // Pulse Oximeter
    TMP40SLOT,  // Thermopile
    BFG70SLOT,  // Fuel Gauge
    ALT9ASLOT,  // Altimeter
    CLR8ZSLOT,  // Color
    BIM30SLOT,  // Bio-Impedance
    MIC4USLOT,  // Microphone
    BTM17SLOT,  // Thermometer
};

struct dGyr20Slot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 x_msb;    // Raw data x MSB
    uint8 x_lsb;    // Raw data x LSB
    uint8 y_msb;    // Raw data y MSB
    uint8 y_lsb;    // Raw data y LSB
    uint8 z_msb;    // Raw data z MSB
    uint8 z_lsb;    // Raw data z LSB
};

struct dAcc1ESlot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint16 x_raw;    // Raw data x
    uint16 y_raw;    // Raw data y
    uint16 z_raw;    // Raw data z
//    uint8 x_msb;    // Raw data x MSB
//    uint8 x_lsb;    // Raw data x LSB
//    uint8 y_msb;    // Raw data y MSB
//    uint8 y_lsb;    // Raw data y LSB
//    uint8 z_msb;    // Raw data z MSB
//    uint8 z_lsb;    // Raw data z LSB
};
struct dMag0ESlot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 x_msb;    // Raw data x MSB
    uint8 x_lsb;    // Raw data x LSB
    uint8 y_msb;    // Raw data y MSB
    uint8 y_lsb;    // Raw data y LSB
    uint8 z_msb;    // Raw data z MSB
    uint8 z_lsb;    // Raw data z LSB
};
struct dPox57Slot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint32 red;     // Red channel data
    uint32 ir;      // Infared channel data
};
struct dTmp40Slot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 t_msb;    // Raw data MSB
    uint8 t_lsb;    // Raw data LSB
};
struct dBfg70Slot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 percent;
};
struct dAlt9ASlot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 p_msb;
    uint8 p_lsb;
    uint8 p_xlsb;
};
struct dClr8ZSlot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint16 red;
    uint16 green;
    uint16 blue;
    uint16 white;
};
struct dBim30Slot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 i_msb;
    uint8 i_lsb;
};
struct dMic4USlot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 m_msb;
    uint8 m_lsb;
    uint8 m_xlsb;
};
struct dBtm17Slot
{
    uint8 reserved; // Bit 8 - Locked | Bit 7 - Valid | Bit [6:1] - DataType
    
    uint8 t_msb;
    uint8 t_lsb;
};
struct dVariant //remove later
{
    uint8 reserved; // Byte 1

    uint8 blank1;   // Byte 2
    uint8 blank2;   // Byte 3
    uint8 blank3;   // Byte 4
    uint8 blank4;   // Byte 5
    uint8 blank5;   // Byte 6
    uint8 blank6;   // Byte 7
    uint8 blank7;   // Byte 8
};

//-----------------------------------------//

void DataBuffer_Init();
uint8 DataBuffer_QueryNextJob();

bool DataBuffer_OpenWriteSlot(uint8** sample, uint8 type, uint32 num_bytes);
bool DataBuffer_CloseWriteSlot(uint8** sample, uint8 type);

bool DataBuffer_OpenReadSlot(uint8** sample, uint8 type, uint32 num_bytes);
bool DataBuffer_CloseReadSlot(uint8** sample, uint8 type);

uint8 DataBuffer_GetNumerator(uint8 type);
void DataBuffer_SetNumerator(uint8 num, uint8 type);

uint8 DataBuffer_GetDenominator(uint8 type);
void DataBuffer_SetDenominator(uint8 den, uint8 type);

//-----------------------------------------//

#endif /* DATABUFFER1_H */