/* ========================================
 *
 * Copyright Buildlog.net 2018
 * Bart Dring
 * Open Source CC4.0 Attribution - Share Alike
 * 
 * USB UART Functions for Grbl
 *
 * ========================================
*/

#include "grbl.h"

/* ==========================================
*  Initialize the USB UART.
*
* ===========================================
*/


void usb_uart_init() {
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);
}

/* 
This checks the status of the USBUART
..Initializes the UART if the configuration has changed
..Gets data if there is data ready to get
*/ 
void usb_uart_check(){
    
    uint16 count; // number of bytes received   
    uint8 buffer[USBUART_BUFFER_SIZE]; // bytes received    
    
    
    if (0u != USBUART_IsConfigurationChanged())
    {
        /* Initialize IN endpoints when device is configured. */
        if (0u != USBUART_GetConfiguration())
        {
            /* Enumeration is done, enable OUT endpoint to receive data 
             * from host. */
            USBUART_CDC_Init();
        }
    }

        /* Service USB CDC when device is configured. */
        if (0u != USBUART_GetConfiguration())
        {
            /* Check for input data from host. */
            if (0u != USBUART_DataIsReady())
            {
                /* Read received data and re-enable OUT endpoint. */
                count = USBUART_GetAll(buffer);

                if (0u != count)
                {                    
                    /* Send the data to Grbl */
                    for (int i = 0; i < count; i++) {
                        rx_handler(buffer[i]);
                    }
                }
            }
            
           
            
            
            

        #ifdef LINE_DEBUG // used to debug the data via the TTL UART
            /* Check for Line settings change. */
            char lineStr[LINE_STR_LENGTH];
            char* parity[] = {"None", "Odd", "Even", "Mark", "Space"};
            char* stop[]   = {"1", "1.5", "2"};    
            
             uint8 state;
            state = USBUART_IsLineChanged();
            
            
            if (0u != state)
            {                
                sprintf(lineStr, "State: %d \r\n", state);                
                UART_PutString(lineStr);
                sprintf(lineStr, "Baud: %ld \r\n", USBUART_GetDTERate());                
                UART_PutString(lineStr);
                
                sprintf(lineStr, "Serial State: %d \r\n", USBUART_GetSerialState());                
                UART_PutString(lineStr);
                
                if (0u != (state & USBUART_LINE_CODING_CHANGED))
                {                  
                    /* Get string to output. */
                    sprintf(lineStr,"BR:%4ld %d%c%s", USBUART_GetDTERate(),\
                                   (uint16) USBUART_GetDataBits(),\
                                   parity[(uint16) USBUART_GetParityType()][0],\
                                   stop[(uint16) USBUART_GetCharFormat()]);

                    UART_PutString(lineStr);
                    UART_PutString("\r\n");
                }

                /* Output on LCD Line Control settings. */
                if (0u != (state & USBUART_LINE_CONTROL_CHANGED))
                {                   
                    /* Get string to output. */
                    state = USBUART_GetLineControl();
                    sprintf(lineStr,"DTR:%s,RTS:%s",  (0u != (state & USBUART_LINE_CONTROL_DTR)) ? "ON" : "OFF",
                                                      (0u != (state & USBUART_LINE_CONTROL_RTS)) ? "ON" : "OFF");

                    UART_PutString(lineStr);
                    UART_PutString("\r\n");
                    
                }
            }
        #endif 
        }   
    
}


/* These functions are called by Grbl to send to the PC */
void usb_uart_write(uint8_t data) {
    uint16 ctr = 0;
    if (USBUART_GetConfiguration() == 1) {    
        while (0u == USBUART_CDCIsReady())
        {
            ctr++;  if (ctr > 400) 
                return; // prevent getting stuck
        }
        USBUART_PutChar(data);
    }
}


void usb_uart_PutString(const char *s) {    
    uint16 ctr = 0;
    if (USBUART_GetConfiguration() == 1) {    
        while (0u == USBUART_CDCIsReady())
        {
            ctr++;  if (ctr > 400) 
                return; // prevent getting stuck
        }
        USBUART_PutString(s);
    }        
}

/* [] END OF FILE */
