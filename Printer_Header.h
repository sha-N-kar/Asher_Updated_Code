/*
 * printer_header.h
 *
 *  Created on: Jul 14, 2024
 *      Author: sHa
 */

#ifndef INC_PRINTER_HEADER_H_
#define INC_PRINTER_HEADER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "LCD_Header.h"

void Heading(char);
void string(char*);


#ifdef __cplusplus
}
#endif

#endif /* INC_PRINTER_HEADER_H_ */


