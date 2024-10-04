#include "Pendrive.h"
#include "LCD_Header.h"
char Return[2],cmd[5],File_name[13]="/";
uint16_t File_count=0;

void Command()
{
	char Base[]={0x57,0xAB};
	HAL_UART_Transmit(&huart1, (uint8_t*)Base, strlen(Base), 100);
}

void Response(uint8_t value)
{
	while(Return[0]!=value)
	{
		HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 100);
		if(Button_Menu_Esc)
			File();
	}
}
void Pendrive_Init()
{
	Command();
	cmd[0]=0x05;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	HAL_Delay(500);

	Command();
	cmd[0]=0x06;cmd[1]=0x01;
	HAL_UART_Transmit(&huart1, cmd , 2, 100);
	Response(0xFE);

	Command();
	cmd[0]=0x15;cmd[1]=0x05;
	HAL_UART_Transmit(&huart1, cmd , 2, 100);
	HAL_Delay(500);

	Command();
	cmd[0]=0x15;cmd[1]=0x07;
	HAL_UART_Transmit(&huart1, cmd , 2, 100);
	HAL_Delay(500);

	Command();
	cmd[0]=0x15;cmd[1]=0x06;
	HAL_UART_Transmit(&huart1, cmd , 2, 100);
	while(Return[0]!=0x51 && Return[1]!=0x15)
		HAL_UART_Receive(&huart1, (uint8_t*)Return, 2, 100);

	HAL_Delay(1000);
	Command();
	cmd[0]=0x31;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	Response(0x14);

	SetCursor(0, 2, 22);
	Print("USB Initilized");

}
void File_Send()
{
	HAL_Delay(1000);
	Return[0]=0;
	Command();
	cmd[0]=0x00;
	HAL_UART_Transmit(&huart1, "/" , 1, 100);
	HAL_UART_Transmit(&huart1, (uint8_t*)File_name, strlen(File_name), 100);
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
}

void dummy_file()
{
	HAL_Delay(500);
	Command();
	cmd[0]=0x00;
	HAL_UART_Transmit(&huart1, (uint8_t*)"//0", strlen(3), 100);
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	HAL_Delay(500);
	Command();
	cmd[0]=0x32;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	HAL_Delay(500);
//	while(Return[0]!=0x42)
//		HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 100);
}

uint8_t File_Exists()
{
	HAL_Delay(500);
	Return[0]=0;
	Command();
	cmd[0]=0x32;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 1500);

	if(Return[0]==0x14)
	{
		SetCursor(0, 2, 22);
		Print("File is exists");
		uint8_t option=1;
		Move(option,"RENAME","NEW","APPEND");
		while(!(Button_Menu_Esc) && option!=0 )
		{
			if(Button_Move)
			{
				option++;
				if(option==4)
					option=1;
				Move(option,"RENAME","NEW","APPEND");
			}
			while(Button_Move);
			if(Button_Test_Enter)
			{
				while(Button_Test_Enter);
				if(option==1)
					File();
				else if(option ==2)
				{
					close(File_Update);
					dummy_file();
					file();
				}
				else if(option ==3)
				{
					close(File_Update);
					dummy_file();
					File_Data();
				}
				option=0;
			}
		}
	}
	else
	{
		dummy_file();
		file();
	}
}
void file()
{
	File_Send();
	HAL_Delay(1000);
	Command();
	cmd[0]=0x34;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	Response(0x14);
	File_Write(",,AIS Digi mic smart - 12 ,,\r\n");
	close(File_Update);
	dummy_file();
	SetCursor(0, 5, 30);
	Print("File Created");
	HAL_Delay(500);
	File_Data();
}
uint8_t Checking_File()
{

	HAL_Delay(500);
	File_Send();
	File_Exists();
}

void File_Write(char data[])
{
	HAL_Delay(500);
	Command();
	cmd[0]=0x3C;cmd[1]=strlen(data);cmd[2]=0x00;
	HAL_UART_Transmit(&huart1, cmd , 3, 100);
	Response(0x1E);
//	while(Return[0]!=0X1E)
//		HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 100);

	Command();
	cmd[0]=0x2D;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	Response(strlen(data));
//	while(Return[0]!=(char)strlen(data))
//		HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 100);

	HAL_UART_Transmit(&huart1, (uint8_t*)data , strlen(data), 100);

	Command();
	cmd[0]=0x3D;
	HAL_UART_Transmit(&huart1, cmd, 1, 100);
	Response(0x14);
//	while(Return[0]!=0X14)
//		HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 100);

}

void File_Read()
{
	HAL_Delay(500);
	Command();
	cmd[0]=0x3A;cmd[1]=0x01;cmd[2]=0x00;
	HAL_UART_Transmit(&huart1, cmd , 3, 100);
	Response(0x1D);

	Command();
	cmd[0]=0x27;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	HAL_Delay(1000);

	Command();
	cmd[0]=0x3B;
	HAL_UART_Transmit(&huart1, cmd, 1, 100);
	Response(0x14);

}
void File_Append()
{
	HAL_Delay(500);
	Return[0]=0;
	Command();
	cmd[0]=0x39;cmd[1]=0xFF;cmd[2]=0xFF;cmd[3]=0xFF;cmd[4]=0xFF;
	HAL_UART_Transmit(&huart1, cmd, 5, 100);
	Response(0x14);
}

void File_Data()
{
	SetCursor(0, 5, 30);
	Print("Writing File");
	File_Send();

	HAL_Delay(500);
	Return[0]=0;
	Command();
	cmd[0]=0x32;
	HAL_UART_Transmit(&huart1, cmd , 1, 100);
	HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 1500);
	Response(0x14);

	File_Append();
	File_Write("\r");
	File_Write(name);
	File_Write("\r\n");
	File_Write("LOT NO : ,");
	File_Write(Lot);
	File_Write("\r\n");
	File_Write("TEST-#,,,mic(ug/inch)\r\n");

	float add=0;
	for(char print=1;print<=test;print++)
	{

		SetCursor(0, 6, 52);
		Print("....");
		if(print<10)
			Number(print,0x20);
		else
			File_Write("10");
		File_Write(",,,");
		Number(mic_value[print-1], 0x23);
		add+=mic_value[print-1];
		File_Write("\r");
		SetCursor(0, 6, 52);
		Print("    ");
	}
	add=add/(float)test;
	File_Write("\r");
	File_Write(" AVERAGE,,,");
	Number(add,0x23);
	File_Write("\r");
	File_Write("\r\n\n\n");
	close(File_Update);
	dummy_file();
	SetCursor(0, 5, 30);
	Print(" File Close ");
}

void close(uint8_t File_status)
{
	HAL_Delay(500);
	Return[0]=0;
	Command();
	cmd[0]=0x36;cmd[1]=File_status;
	HAL_UART_Transmit(&huart1, cmd, 2, 100);
	Response(0x14);
//	while(Return[0]!=0X14)
//		HAL_UART_Receive(&huart1, (uint8_t*)Return, 1, 100);
}
