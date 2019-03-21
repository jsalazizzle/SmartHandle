
#include <AccDriver.h>
#include <DataBuffer.h>

#include "debug.h"

static bool   device_rate_changed   = true;
static uint8  device_rate_setting   = ACC_1E_RATE_12_5_HZ;
static uint32 interpolated_period   = 0;
static uint32 sample_period         = 0;
static uint32 interrupt_period      = 0;
static cy_stc_scb_i2c_master_xfer_config_t register_setting;

static bool is_first_sample = true;
static uint8 rbuff[256]; // Read buffer: 32 sample fifo x 3 axis x 2 bytes
static uint8 wbuff[2];   // Write buffer
static struct dAcc1ESlot* wsample;
static uint8* wsample_ptr;
static acc_struct sample_old, sample_new, interpolated;
static uint8 x_msb, x_lsb, y_msb, y_lsb, z_msb, z_lsb;

static void WriteRegister(uint8 reg_addr, uint8 data)
{
    wbuff[0] = reg_addr; wbuff[1] = data;
    register_setting.buffer = wbuff; register_setting.bufferSize = 2; register_setting.xferPending = false;        
    
    cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterWrite(&register_setting);
    if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
    {
        // ** Throw error
    }
    
    uint16 counter = 0;
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY)){}
    {
        if(++counter > 1000)
        {
            // ** Throw error
            return;
        }
        else
        {
            CyDelayUs(1);  // Keep Waiting
        }
    }
    return;
}
static uint8 ReadRegister(uint8 reg_addr)
{
    cy_en_scb_i2c_status_t i2cReturnValue;
    
    wbuff[0] = reg_addr;    
    register_setting.buffer = wbuff; register_setting.bufferSize = 1; register_setting.xferPending = true;
    
    i2cReturnValue = SensorBus_MasterWrite(&register_setting);
    if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
    {
        // ** Throw error
    }
    
    uint16 counter = 0;
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY))
    {
        if(++counter > 1000) 
        {
            // ** Throw error
            return 0;         
        }
        else
        {
            CyDelayUs(1);  // Keep Waiting
        }
    }
    
    register_setting.buffer = rbuff; register_setting.bufferSize = 1; register_setting.xferPending = false;
    
    i2cReturnValue = SensorBus_MasterRead(&register_setting);
    if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
    {
        // ** Throw error
    }
    
    while(0 != (SensorBus_MasterGetStatus() & CY_SCB_I2C_MASTER_BUSY)){}
    {
        if(++counter > 1000) 
        {
            // ** Throw error
            return 0;
        }
        else
        {
            CyDelayUs(1);  // Keep Waiting
        }
    }
    return rbuff[0];
}
static void Interpolate(void)
{
    static int16 a0, a1, t, t1;
    
    sample_old.x_raw = sample_new.x_raw;
    sample_old.y_raw = sample_new.y_raw;
    sample_old.z_raw = sample_new.z_raw;

    sample_new.x_raw = ((uint16) x_msb << 8) | x_lsb;
    sample_new.y_raw = ((uint16) y_msb << 8) | y_lsb;
    sample_new.z_raw = ((uint16) z_msb << 8) | z_lsb;     
    
    if(is_first_sample == true)
    {  
        is_first_sample = false; return;
    }
    
    if(interpolated.timestamp <= sample_new.timestamp)
    {        
        a0 = sample_old.x_raw; a1 = sample_new.x_raw; t = interpolated.timestamp; t1 = sample_new.timestamp;
        interpolated.x_raw = a0 + (t * (a1 - a0)/t1);
        
        a0 = sample_old.y_raw; a1 = sample_new.y_raw;
        interpolated.y_raw = a0 + (t * (a1 - a0)/t1);
          
        a0 = sample_old.z_raw; a1 = sample_new.z_raw;
        interpolated.z_raw = a0 + (t * (a1 - a0)/t1);

        wsample->x_raw = (uint16)interpolated.x_raw;
        wsample->y_raw = (uint16)interpolated.y_raw;
        wsample->z_raw = (uint16)interpolated.z_raw;
            
        wsample_ptr = (uint8*) wsample;    
        if(DataBuffer_OpenWriteSlot((uint8**)&wsample_ptr, ACC1ESLOT, sizeof(struct dAcc1ESlot)))
        {
            DataBuffer_CloseWriteSlot((uint8**)&wsample_ptr, ACC1ESLOT);
        }
        
        interpolated.timestamp = interpolated.timestamp + interpolated_period;
        if(interpolated.timestamp < sample_new.timestamp)
        {
            Interpolate();
        }
        else
        {
            interpolated.timestamp = interpolated.timestamp - sample_period;
        }
    }
    else
    {
        interpolated.timestamp = interpolated.timestamp - sample_period;
    }
}
void AccDriver_Init()
{
    register_setting.slaveAddress = 0x1E;
    WriteRegister(0x21,0b01000000); CyDelay(10);  // Reset          W[0x3C 0x21 0x40]
    if(ReadRegister(0x0F) != 0b01000011) // Verify Chip ID          W[0x3C 0x0F] R[0x3D 0x43]
    {
        CyDelay(10);
        // ** Throw error
    }
    wsample = (struct dAcc1ESlot*) malloc(sizeof(struct dAcc1ESlot));
    // Orignal Code
    //WriteRegister(0x20,0b10010001);    // Low Power + 12.5 Hz               W[0x3C 0x20 0x91]
    //WriteRegister(0x25,0b11000000);    // FIFO Circular Buffer Mode         W[0x3C 0x25 0xC0]
    
    // New code to initialize Wakeup Interrupt
    WriteRegister(ACC_CTRL1,0x60); // Turn on accelerometer at 400 Hz
    //WriteRegister(ACC_CTRL3,0x04); // Turn on latched mode
    WriteRegister(ACC_WAKE_UP_DUR,0b01100000); // Set WU_DUR to 3
    WriteRegister(ACC_WAKE_UP_THS,0x02); // Set wake-up threshold
    WriteRegister(ACC_CTRL4,0x20); // Wake-up interrupt driven to INT1 pin
    return;
}
bool AccDriver_OperationDone()
{
    enum TransferStages{ UPDATE_SETTING_RATE, ASK_DIFF8, GET_DIFF8, ASK_FIFO_SIZE , GET_FIFO_SIZE , ASK_FIFO_DATA , GET_FIFO_DATA , SAVE_TO_BUFFER };
    static uint8 pkt[2] = {0x00,0x00};
    static uint16 state = UPDATE_SETTING_RATE;
    static uint16 datums = 0;
    
    static uint8 val1[1] = {0x2f};  // Asks diff8
    static uint8 val2[1] = {0x30};  // Asks fifo size
    static uint8 val3[1] = {0x28};  // Asks fifo data
    switch(state)
    {
        case UPDATE_SETTING_RATE:
        {
            state = ASK_DIFF8;
            if(device_rate_changed)
            {
                device_rate_changed = false;
                switch(device_rate_setting)
                {
                    case ACC_1E_RATE_800_HZ:  {pkt[0] = 0x20; pkt[1] = 0b11110000; break;}  // W[0x3C 0x20 0xF0]
                    case ACC_1E_RATE_400_HZ:  {pkt[0] = 0x20; pkt[1] = 0b11100000; break;}  // W[0x3C 0x20 0xE0]
                    case ACC_1E_RATE_200_HZ:  {pkt[0] = 0x20; pkt[1] = 0b11010000; break;}  // W[0x3C 0x20 0xD0]
                    case ACC_1E_RATE_100_HZ:  {pkt[0] = 0x20; pkt[1] = 0b11000000; break;}  // W[0x3C 0x20 0xC0]
                    case ACC_1E_RATE_50_HZ:   {pkt[0] = 0x20; pkt[1] = 0b10110000; break;}  // W[0x3C 0x20 0xB0]
                    case ACC_1E_RATE_25_HZ:   {pkt[0] = 0x20; pkt[1] = 0b10100000; break;}  // W[0x3C 0x20 0xA0]
                    case ACC_1E_RATE_12_5_HZ: {pkt[0] = 0x20; pkt[1] = 0b10010000; break;}  // W[0x3C 0x20 0x90]
                    case ACC_1E_RATE_1_HZ:    {pkt[0] = 0x20; pkt[1] = 0b10000000; break;}  // W[0x3C 0x20 0x80]
                    case ACC_1E_OFF:          {pkt[0] = 0x20; pkt[1] = 0b00000000; break;}  // W[0x3C 0x20 0x00]
                }				
                register_setting.buffer = pkt; register_setting.bufferSize = 2; register_setting.xferPending = false;
                cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterWrite(&register_setting);
                if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
                {
                    // ** Throw error
                }    
                break;
            }
        }
        case ASK_DIFF8:  // 9th-bit for FIFO buffer, asks if FIFO is full (256 samples). On page 50 in datasheet. W[0x3C 0x2F]
        {
            datums = 0;
            register_setting.buffer = val1; register_setting.bufferSize = 1; register_setting.xferPending = true;
            cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterWrite(&register_setting);
            if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
            {
                // ** Throw error
            }
            state = GET_DIFF8;
            break;
        }
        case GET_DIFF8:  // Read if DIFF8 is filled      R[0x3D 0x##]
        {
            register_setting.buffer = rbuff; register_setting.bufferSize = 1; register_setting.xferPending = false;
            cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterRead(&register_setting);
            if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
            {
                // ** Throw error
            }
            state = ASK_FIFO_SIZE; 
            break;
        }
        case ASK_FIFO_SIZE:  // Request Number of Buffered datums  
        {
            if(rbuff[0] & 0x20)
            {
                datums = 256;
                state = ASK_FIFO_DATA;
            }
            else //  W[0x3C 0x30]
            {
                register_setting.buffer = val2; register_setting.bufferSize = 1; register_setting.xferPending = true;
                cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterWrite(&register_setting);
                if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
                {
                    // ** Throw error
                }
                state = GET_FIFO_SIZE;
            }
            break;
        }
        case GET_FIFO_SIZE:  // Read Number of Buffered datums      R[0x3D 0x##]
        {
            register_setting.buffer = rbuff; register_setting.bufferSize = 1; register_setting.xferPending = false;
            cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterRead(&register_setting);
            if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
            {
                // ** Throw error
            }
            state = ASK_FIFO_DATA;
            break;
        }
        case ASK_FIFO_DATA:  // Request All Buffered datums         W[0x3C 0x028]
        {
            if(datums != 256)
            {
                uint8 remainder = (rbuff[0] & 0xFF) % 6;
                datums = (rbuff[0] & 0xFF) - remainder; // 16-bit for x,y,z
            }
            register_setting.buffer = val3; register_setting.bufferSize = 1; register_setting.xferPending = true;
            cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterWrite(&register_setting);
            if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
            {
                // ** Throw error
            }
            state = GET_FIFO_DATA; 
            break;
        }        
        case GET_FIFO_DATA:  // Read Buffered datums                R[0x3D 0x## ... 0x##]
        {
            register_setting.buffer = rbuff; register_setting.bufferSize = datums; register_setting.xferPending = false;
            cy_en_scb_i2c_status_t i2cReturnValue = SensorBus_MasterRead(&register_setting);
            if(i2cReturnValue != CY_SCB_I2C_SUCCESS)
            {
                // ** Throw error
            }
            state = SAVE_TO_BUFFER;
            break;
        }
        case SAVE_TO_BUFFER: // Save to Buffer
        {
            for(uint16 index = 0; index < datums; index += 6)
            {
                x_lsb = rbuff[index+0]; x_msb = rbuff[index+1];
                y_lsb = rbuff[index+2]; y_msb = rbuff[index+3];
                z_lsb = rbuff[index+4]; z_msb = rbuff[index+5];
                Interpolate();
            }
            state = UPDATE_SETTING_RATE;
            return true;
        }
    }    
    return false;
}
int32 AccDriver_UpdateSetting(uint8 setting_type, int32 setting_value)
{
    static int32 old_setting_value = 0;
    if(old_setting_value == setting_value) return sample_period;
    
    old_setting_value = setting_value;
    device_rate_changed = true;
    
    if(setting_value < 0)
    {
        interpolated_period = 1000/abs(setting_value);
    }
    else
    {   
        interpolated_period = setting_value;
    }
    
    if(setting_value == 0)
    {
        device_rate_setting = ACC_1E_OFF;
        sample_period = 0;
        interrupt_period = 0;
    }
    else if(setting_value == -1 || setting_value > 0)
    {
        device_rate_setting = ACC_1E_RATE_1_HZ;
        sample_period = 1000;
        interrupt_period = 16000;
    }
    else if(setting_value < -1 && setting_value >= -12)
    {
        device_rate_setting = ACC_1E_RATE_12_5_HZ;
        sample_period = 80;
        interrupt_period = 1280;
    }
    else if(setting_value < -12 && setting_value >= -25)
    {
        device_rate_setting = ACC_1E_RATE_25_HZ;
        sample_period = 40;
        interrupt_period = 640;
    }
    else if(setting_value < -25 && setting_value >= -50)
    {
        device_rate_setting = ACC_1E_RATE_50_HZ;
        sample_period = 20;
        interrupt_period = 320;
    }
    else if(setting_value < -50 && setting_value >= -100)
    {
        device_rate_setting = ACC_1E_RATE_100_HZ;
        sample_period = 10;
        interrupt_period = 160;
    }
    else if(setting_value < -100 && setting_value >= -200)
    {
        device_rate_setting = ACC_1E_RATE_200_HZ;
        sample_period = 5;
        interrupt_period = 80;
    }
    else if(setting_value < -200 && setting_value >= -400)
    {
        device_rate_setting = ACC_1E_RATE_400_HZ;
        sample_period = 2;
        interrupt_period = 32;
    }
    else if(setting_value < -400)
    {
        device_rate_setting = ACC_1E_RATE_800_HZ;
        sample_period = 1;
        interrupt_period = 16;
    }
    else
    {
        return -1;
    }
      
    denominators[ACC1ESLOT] = 163840;
    numerators[ACC1ESLOT] = 98;
    interpolated.timestamp = interpolated_period;
    sample_old.timestamp = 0;    
    sample_new.timestamp = sample_period;
    
    return interrupt_period;
}
