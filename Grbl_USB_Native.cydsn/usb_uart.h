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

#ifndef usb_uart_h
#define usb_uart_h

#include "grbl.h"

#define USBFS_DEVICE    (0u)
#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH     (20u)
//#define LINE_DEBUG // output line state to UART

void usb_uart_init();
void usb_uart_check();
void usb_uart_show_status(uint8_t state);
void usb_uart_PutString(const char *s);
void usb_uart_write(uint8_t data);

#endif

/* [] END OF FILE */
