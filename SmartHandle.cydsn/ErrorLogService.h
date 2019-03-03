#ifndef ERRORREPORTSERVICE_H
#define ERRORREPORTSERVICE_H

#include <project.h>
#include <stdbool.h>
   
//-----------------------------------------//

void ErrorLogService_SendAppError(void);
void ErrorLogService_SendKinosError(void);
void ErrorLogService_AppHandler(void);
void ErrorLogService_KinosHandler(void);

//-----------------------------------------//

#endif /* ERRORREPORTSERVICE_H */
