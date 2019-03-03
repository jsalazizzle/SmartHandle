/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    UART_Start(); 
    UART_DEBUG_Start();

    
    printf("*******************************************************\r\n");
    printf("*                                                     *\r\n");
    printf("*              Connect TX -> Pin 13.0                 *\r\n");
    printf("*                                                     *\r\n");
    printf("*                                                     *\r\n");
    printf("*     All incoming data will be displayed below       *\r\n");
    printf("*******************************************************\r\n\r\n\r\n");

    char c;
    for(;;)
    {
        c = UART_DEBUG_Get();
        if(c != 0xFF)
            printf("%c",c);
    }
}

/* [] END OF FILE */
