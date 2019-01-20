#ifndef ERRORREPORTING_H
#define ERRORREPORTING_H

#include <project.h>
#include <stdbool.h>

//-----------------------------------------//

#define EEPROM_LOG_SIZE         256u
#define LOGICAL_LOG_SIZE        2039u
    
//-----------------------------------------//
    
void ErrorLogging_Init(void);
void ErrorLogging_ReportAppError(uint16 fileID, uint16 functionID, uint16 errorID);
void ErrorLogging_ReportKinosError(uint16 fileID, uint16 functionID, uint16 errorID);
void ErrorLogging_ClearAppError(void);
void ErrorLogging_ClearKinosError(void);

//-----------------------------------------//

#endif /* ERRORREPORTING_H */