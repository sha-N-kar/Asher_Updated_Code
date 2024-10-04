/*
 * Pendrive.h
 *
 *  Created on: Aug 29, 2024
 *      Author: sHa
 */

#ifndef INC_PENDRIVE_H_
#define INC_PENDRIVE_H_

#include "main.h"
#include "usart.h"


#define		File_Update			0x01
#define		File_Not_Update		0x00

extern char Return[],cmd[],File_Name[];
void Command(void);
void Update_File_Name();
void Pendrive_Init(void);
uint8_t File_Exists(void);
uint8_t Checking_File(void);
void File_Read();
void File_Write(char [] );
void close(uint8_t);
void Response(uint8_t);
#endif /* INC_PENDRIVE_H_ */
