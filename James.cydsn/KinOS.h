#ifndef KINOS_H
#define KINOS_H
    
#include <project.h>
#include <stdbool.h>
    
/*                                                              +
      __  __                         _____       ____       
     /\ \/\ \     __                /\  __`\    /\  _`\     
     \ \ \/'/'   /\_\       ___     \ \ \/\ \   \ \,\+\_\   
      \ \ , <    \/\ \    /' _ `\    \ \ \ \ \   \/_\__ \   
       \ \ \\`\   \ \ \   /\ \/\ \    \ \ \_\ \    /\ \+\ \ 
        \ \_\ \_\  \ \_\  \ \_\ \_\    \ \_____\   \ `\____\
         \/_/\/_/   \/_/   \/_/\/_/     \/_____/    \/_____/

*/
    
//                  +-----------------------+                  //
//-----------------<| SYSTEM-CORE-FUNCTIONS |>-----------------//
//                  +-----------------------+                  //

//--------------------------------------------------------------+
// KinOS_Boot initializes core modules: flash management, fault |
// handling, watch dog timers, error logging, usage profiling,  |
// and battery voltage ADC. Called from main.c and only once.   |
//                                                              |
    void KinOS_Boot();                                      //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_BatteryVoltage returns current battery voltage in mV.  |
//                                                              |
    uint16 KinOS_BatteryVoltage();                          //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_SetDateAndTime sets the current clock time. The date   |
// and time can then be accessed via KinOS_DateAndTime.         |
//                                                              |
    typedef struct                                          //  |
    {                                                       //  |
        uint16 year; uint16 month;  uint16 day;             //  |
        uint16 hour; uint16 minute; uint16 second;          //  |
    }                                                       //  |
    epoch;                                                  //  |
                                                            //  |
    void KinOS_SetDateAndTime(uint8 year,                   //  |
                              uint8 month,                  //  |
                              uint8 day,                    //  |
                              uint8 hour,                   //  |
                              uint8 minute,                 //  |
                              uint8 second);                //  |
    epoch KinOS_GetDateAndTime();                           //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_SetupTimerA configures a one shot timer with time in   |
// milliseconds. When expired will return true when             |
// KinOS_CheckTimerA is called, false otherwise.                |
//                                                              |
    void KinOS_SetupTimerA(uint32 timeout_ms);              //  |
    bool KinOS_CheckTimerA();                               //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_SetupTimerB configures a one shot timer with time in   |
// milliseconds. When expired will return true when             |
// KinOS_CheckTimerB is called, false otherwise.                |
//                                                              |
    void KinOS_SetupTimerB(uint32 timeout_ms);              //  |
    bool KinOS_CheckTimerB();                               //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_SetupTimerC configures a one shot timer with time in   |
// milliseconds. When expired will return true when             |
// KinOS_CheckTimerC is called, false otherwise.                |
//                                                              |
    void KinOS_SetupTimerC(uint32 timeout_ms);              //  |
    bool KinOS_CheckTimerC();                               //  |
//                                                              |
//--------------------------------------------------------------+

//                  +-----------------------+                  //
//-----------------<| BUS-MANAGER-FUNCTIONS |>-----------------//
//                  +-----------------------+                  //

//--------------------------------------------------------------+
// KinOS_ReadSample removes the next data buffer sample and     |
// populates memory at pointer *data with the associated sample |
// structure. Data is provided as a fraction with no rounding   |
// and timestamp in micro-seconds after synchronizing to LFCLK. |
//                                                              |
    bool KinOS_ReadSample(uint8 *data);                     //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to ACC            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        int16 x_raw;            // Raw x-axis               //  |
        int16 y_raw;            // Raw y-axis               //  |
        int16 z_raw;            // Raw z-axis               //  |
        uint32 denominator;     // Denominator all          //  |
        uint32 numerator;       // Numerator all            //  |
    }                                                       //  |
    acc_sample; // Acceleration in meters/second^2          //  |
                                                            //  |
    void KinOS_ReadAcc(acc_sample* data);                   //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to ALT            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 numerator;       // Numerator                //  |
        uint32 denominator;     // Denominator              //  |
    }                                                       //  |
    alt_sample; // Altitude in meters above sea level       //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to CLR            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 red_numerator;   // Numerator red            //  |
        uint32 green_numerator; // Numerator green          //  |
        uint32 blue_numerator;  // Numerator blue           //  |
        uint32 white_numerator; // Numerator white          //  |
        uint32 denominator;     // Denominator all          //  |
    }                                                       //  |
    clr_sample; // Color in red green blue white lux        //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to BIM            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 real_numerator;  // Numerator real           //  |
        uint32 imag_numerator;  // Numerator imaginary      //  |
        uint32 denominator;     // Denominator all          //  |
    }                                                       //  |
    bim_sample; // Impedance is complex in units of ohms    //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to BFG            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint8  level;           // Battery percentage       //  |
    }                                                       //  |
    bfg_sample; // Battery life given as a percentage.      //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to GYR            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 x_numerator;     // Numerator x-axis         //  |
        uint32 y_numerator;     // Numerator y-axis         //  |
        uint32 z_numerator;     // Numerator z-axis         //  |
        uint32 denominator;     // Denominator all          //  |
    }                                                       //  |
    gyr_sample; // Angular velocity in radians/second.      //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to MAG            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 x_numerator;     // Numerator x-axis         //  |
        uint32 y_numerator;     // Numerator y-axis         //  |
        uint32 z_numerator;     // Numerator z-axis         //  |
        uint32 denominator;     // Denominator all          //  |
    }                                                       //  |
    mag_sample; // Magnetic field in micro-gauss            //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to MIC            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 audio_sample;    // Raw audio reading        //  |
    }                                                       //  |
    mic_sample; // Raw audio sample with no units.          //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8 sensor_type;      // Is set to POX            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 red_numerator;   // Numerator red led        //  |
        uint32 ir_numerator;    // Numerator ir led         //  |
        uint32 denominator;     // Denominator all          //  |
    }                                                       //  |
    pox_sample; // Photodiode current in micro-Amps.        //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to BTM            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 numerator;       // Numerator                //  |
        uint32 denominator;     // Denominator              //  |
    }                                                       //  |
    btm_sample; // Temperature in degrees fahrenheit.       //  |
                                                            //  |
    typedef struct                                          //  |
    {                                                       //  |
        uint8  sensor_type;     // Is set to TMP            //  |
        uint64 timestamp;       // Timestamp in us          //  |
        uint32 numerator;       // Numerator                //  |
        uint32 denominator;     // Denominator              //  |
    }                                                       //  |
    tmp_sample; // Temperature in degrees fahrenheit.       //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_ConfigureSensor modifies sensor settings. See table 1  |
// for valid sampling rates. Invalid combinations return false. |
//                                                              |
    bool KinOS_ConfigureSensor(uint8  sensor_type,          //  |
                               uint8  setting_type,         //  |
                               int32 setting_value);        //  |
                                                            //  |
    enum SensorType                                         //  |
    {                                                       //  |
        NONE,   // No Sensor                                //  |
        ACC,    // Accelerometer                            //  |
        ALT,    // Altimeter                                //  |
        CLR,    // Ambient Color                            //  |
        BIM,    // Bio Impedance                            //  |
        BFG,    // Battery Fuel Gauge                       //  |
        GYR,    // Gyroscope                                //  |
        MAG,    // Magnetometer                             //  |
        MIC,    // Microphone                               //  |
        POX,    // Pulse Oximeter                           //  |
        BTM,    // Thermometer                              //  |
        TMP     // Thermopile                               //  |
    };                                                      //  |
                                                            //  |
    enum SettingType                                        //  |
    {                                                       //  |
        SAMPLE_RATE_PERIOD, // Refer to Table 1             //  |
    };                                                      //  |
//                                                              |
//+-------------------------------------------------------------<
//|            Table 1: (Sensor Sample Rate/Period)             |
//+-------------------------------------------------------------+
//| Negative setting values are interpereted as '1/|value|' Hz. |
//| Positive setting values as 'value' seconds between samples. |
//| Zero setting value will turn off the sensor.                |
//+-------------+-----------------------+-----------------------+
//|   Sensor    |  Minimum Rate/Period  |  Maximum Rate/Period  |
//|    Type     |   (Value) ~ Meaning   |   (Value) ~ Meaning   |
//+-------------+-----------------------+-----------------------+
//|     ACC     | (-1 or 1) ~ 1 Hz      |    (-800) ~ 800 Hz    |
//|     ALT     |   (86400) ~ 86400 Sec |    (-157) ~ 157 Hz    |
//|     CLR     |   (86400) ~ 86400 Sec |     (-10) ~ 10 Hz     |
//|     BIM     |   (86400) ~ 86400 Sec |  (-10000) ~ 10000 Hz  |
//|     BFG     |   (86400) ~ 86400 Sec |     (-10) ~ 10 Hz     |
//|     GYR     | (-1 or 1) ~ 1 Hz      |   (-6400) ~ 6400 Hz   |
//|     MAG     |   (86400) ~ 86400 Sec |     (-80) ~ 80 Hz     |
//|     MIC     |    (8000) ~ 8000 Hz   |  (-64000) ~ 64000 Hz  |
//|     POX     | (-1 or 1) ~ 1 Hz      |   (-3200) ~ 3200 Hz   |
//|     BTM     |   (86400) ~ 86400 Sec |     (-10) ~ 10 Hz     |
//|     TMP     |   (86400) ~ 86400 Sec |     (-10) ~ 10 Hz     |
//+-------------+-----------------------+-----------------------+

//                 +------------------------+                  //
//----------------<| TRANSMISSION-FUNCTIONS |>-----------------//
//                 +------------------------+                  //

//--------------------------------------------------------------+
// KinOS_IsAdvertising returns true if the bluetooth low energy |
// module is currently in advertising mode.                     |
//                                                              |
    bool KinOS_IsAdvertising();                             //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_IsConnected returns true when bluetooth low energy     |
// module is actively connected to a client device.             |
//                                                              |
    bool KinOS_IsConnected();                               //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_Advertise enables advertisement for a fixed period     |
// after which advertisement is halted. Time is in seconds with |
// a maximum time of 18 hours. Advertisement interval in ms     |
// with a maximum interval of 1 min.                            |
//                                                              |
    bool KinOS_Advertise(uint16 timeout_s,                  //  |
                         uint16 interval_ms);               //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_Disconnect forces a disconnection from the client.     |
//                                                              |
    bool KinOS_Disconnect();                                //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_CheckInbox checks if the client has sent a message to  |
// be processed. If inbox is empty returns false. Only the      |
// newest message is saved to the inbox.                        |
//                                                              |
    bool KinOS_CheckInbox(uint32 num_bytes,                 //  |
                          uint8 *data);                     //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_SendResult stores a message to the transmission send   |
// buffer. If the send buffer is full returns false.            |
//                                                              |
    bool KinOS_SendResult(uint32 num_bytes,                 //  |
                          uint8 *data);                     //  |
//                                                              |
    
    void KinOS_SendAcc(acc_sample* data);
//--------------------------------------------------------------+
    
//             +--------------------------------+              //
//------------<| USER-INTERFACE-INPUT-FUNCTIONS |>-------------//
//             +--------------------------------+              //

//--------------------------------------------------------------+
// KinOS_PressDetected returns which button was pressed. If no  |
// button was pressed returns a zero. State cleared on call.    |
//                                                              |
    uint8 KinOS_PressDetected();                            //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_Tap2xDetected returns true if accelerometer sensor     |
// double tap interrupt is triggered. State cleared on call.    |
//                                                              |
    bool KinOS_Tap2xDetected();                             //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_HoverDetected returns true if CapSense proximity sense |
// was triggered. State cleared on call.                        |
//                                                              |
    bool KinOS_HoverDetected();                             //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_ShakeDetected returns true if accelerometer sensor     |
// shake interrupt is triggered. State cleared on call.         |
//                                                              |
    bool KinOS_ShakeDetected();                             //  |
//                                                              |
//--------------------------------------------------------------+

//             +---------------------------------+             //
//------------<| USER-INTERFACE-OUTPUT-FUNCTIONS |>------------//
//             +---------------------------------+             //

//--------------------------------------------------------------+
// KinOS_ConfigureLight sets the color, flash pattern, number   |
// of pattern repeats, and brightness of the RGB LEDs. Cycles   |
// defined as 0-255 repeats. Each cycle takes two seconds to    |
// complete. Brightness defined as an integer value 0->lowest   |
// 255->brightest.                                              |
//                                                              |
    void KinOS_ConfigureLight(uint8 color,                  //  |
                              uint8 pattern,                //  |
                              uint8 cycles,                 //  |
                              uint8 brightness);            //  |
                                                            //  |
    void KinOS_BypassSettings(uint8 color,                  //  |
                              uint8 brightness);            //  |
                                                            //  |
    enum LightColor                                         //  |
    {                                                       //  |
        RED,    YELLOW,                                     //  |
        GREEN,  CYAN,                                       //  |
        BLUE,   MAGENTA,                                    //  |
        WHITE                                               //  |
    };                                                      //  |
                                                            //  |
    enum LightPattern                                       //  |
    {                                                       //  |
        SMOOTH, // min to max to min, parabola              //  |
        BOUNCE, // min to max to mid to max to min          //  |
        ZIGZAG, // four sine waves in sequence              //  |
        BYPASS  // manually set color and brightness        //  |
    };                                                      //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_ConfigureChime sets the audio chime pattern and number |
// of loop cycles. Cycles defined as 0-255 repeats. Each cycle  |
// takes 2 seconds to complete.                                 |
//                                                              |
    void KinOS_ConfigureChime(uint8 pattern,                //  |
                              uint8 cycles);                //  |
                                                            //  |
    enum ChimePattern                                       //  |
    {                                                       //  |
        TWEETS, // absolutely no idea, fill in later        //  |
        CYBORG, // who even came up with these names        //  |
        BOOBOO  // im guessing this one sounds scary        //  |
    };                                                      //  |
//                                                              |
//--------------------------------------------------------------<
// KinOS_ConfigureMotor sets the vibration motor pattern and    |
// number of repeat cycles. Cycles defined as 0-255 repeats.    |
// Each cycle takes 2 seconds to complete.                      |
//                                                              |
    void KinOS_ConfigureMotor(uint8 pattern,                //  |
                              uint8 cycles);                //  |
                                                            //  |
    enum MotorPattern                                       //  |
    {                                                       //  |
        WAKEUP, // two strong pulses, one per second        //  |
        RECOIL, // one short pulse then one long pulse      //  |
        HUMMER  // ramp up slowly then sudden dropoff       //  |
    };                                                      //  |
//                                                              |
//--------------------------------------------------------------+
    
#endif /* KINOS_H */
