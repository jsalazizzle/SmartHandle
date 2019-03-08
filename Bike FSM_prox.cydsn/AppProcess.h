#ifndef APPPROCESS_H
#define APPPROCESS_H

//-----------------------------------------//

#include <project.h>
#include <stdbool.h>
#include <stdlib.h>

//-----------------------------------------//

typedef struct
{
    uint8 code;
    uint8 time; // 15 minute count
    uint16 num_steps;
}
step_sample;

typedef struct
{
    uint8 code;
    uint8 time; // 6 minute count
    uint8 sleep_type;
}
sleep_sample;

//-----------------------------------------//
    
void AppProcess_Start();

//-----------------------------------------//

#endif /* APPPROCESS_H */
