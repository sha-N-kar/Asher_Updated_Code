#include "printer_Header.h"

void Heading(char Text)
{
    char Heading_Font[]={0x1D,0x21,Text};
    HAL_UART_Transmit(&huart3,(uint8_t*) Heading_Font,sizeof(Heading_Font), 100);
}

void string(char *Print_Data)
{
	if(out==1)
		HAL_UART_Transmit(&huart1,Print_Data, strlen(Print_Data), 100);

	else
		HAL_UART_Transmit(&huart3,Print_Data, strlen(Print_Data), 100);
}


