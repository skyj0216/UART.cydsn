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
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    mUART_Start();
    for(;;)
    {
        /* Place your application code here. */
        /*
        char str[30];
        for(int i = 1; i < 10; i++) {
            sprintf(str, "2 x %d = %d\n\r", i, i*2);
            mUART_PutString(str);
            CyDelay(500);
        }
        CyDelay(1000); */
        
        static float angle;
        angle++;
        if(angle >= 360) angle -= 360;
        int value = sin(angle * 3.14 / 180) * 100;
        int value2 = cos(angle * 3.14 / 180) * 100;
        printf("%d\n\r", value);
        
    }
    CyDelay(1000);
}

/* [] END OF FILE */
