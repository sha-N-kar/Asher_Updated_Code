#ifndef INC_LCD_HEADER_H_
#define INC_LCD_HEADER_H_

#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "Pendrive.h"
#include "Printer_Header.h"
#include <string.h>


#define Button_Menu_Esc 	   !(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14))
#define Button_UP_Delete 	   !(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15))
#define Button_Down_Result 	   !(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8))
#define Button_Move            !(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11))
#define Button_Test_Enter      !(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12))

void Clear(void);
void LCD_Init(void);
void Glcd(char ,char );
void Number(float ,char );
void Conversition(short int );
void Mic_conversition(float ,int ,int ,float);
void File(void);

extern char name[],File_name[],Lot[];
extern float mic_value[];
extern short int test,out;


#endif /* INC_LCD_HEADER_H_ */
