#include "LCD_Header.h"
#include "Printer_Header.h"
char lcd_count=0,axis,Lot[9]="        ",name[21],temp[20],invert=0,pos=0,Menu=0;
uint16_t Battry_volt=0;
short int test=0,calibrate=100,count=0,out=0;
float mic_value[10];
uint16_t limit=350,max=0,a_max=0;
int value=0;
float volt_a=390,a_volt=0;
const char s_letter[] =
{
    0x00, 0x20, 0x54, 0x54, 0x78, 0x40,      // Code for char a
	0x00, 0x7F, 0x28, 0x44, 0x44, 0x38,      // Code for char b
	0x00, 0x38, 0x44, 0x44, 0x44, 0x28,      // Code for char c
	0x00, 0x38, 0x44, 0x44, 0x28, 0x7F,      // Code for char d
	0x00, 0x38, 0x54, 0x54, 0x54, 0x18,      // Code for char e
	0x00, 0x00, 0x08, 0x7E, 0x09, 0x02,      // Code for char f
	0x00, 0x18, 0xA4, 0xA4, 0x9C, 0x78,      // Code for char g
	0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,      // Code for char h
	0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,      // Code for char i
	0x00, 0x20, 0x40, 0x40, 0x3D, 0x00,      // Code for char j
	0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,      // Code for char k
	0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,      // Code for char l
	0x00, 0x7C, 0x04, 0x78, 0x04, 0x78,      // Code for char m
	0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,      // Code for char n
	0x00, 0x38, 0x44, 0x44, 0x44, 0x38,      // Code for char o
	0x00, 0xFC, 0x18, 0x24, 0x24, 0x18,      // Code for char p
	0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,      // Code for char q
	0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,      // Code for char r
	0x00, 0x48, 0x54, 0x54, 0x54, 0x24,      // Code for char s
	0x00, 0x04, 0x04, 0x3F, 0x44, 0x24,      // Code for char t
	0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,      // Code for char u
	0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,      // Code for char v
	0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,      // Code for char w
	0x00, 0x44, 0x28, 0x10, 0x28, 0x44,      // Code for char x
	0x00, 0x4C, 0x90, 0x90, 0x90, 0x7C,      // Code for char y
	0x00, 0x44, 0x64, 0x54, 0x4C, 0x44       // Code for char z
};

const char c_letter[] =
{
   	0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E,      // Code for char A
	0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,      // Code for char B
	0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,      // Code for char C
	0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E,      // Code for char D
	0x00, 0x7F, 0x49, 0x49, 0x49, 0x49,      // Code for char E
	0x00, 0x7F, 0x09, 0x09, 0x09, 0x09,      // Code for char F
	0x00, 0x3E, 0x41, 0x41, 0x51, 0x73,      // Code for char G
	0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,      // Code for char H
	0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,      // Code for char I
	0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,      // Code for char J
	0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,      // Code for char K
	0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,      // Code for char L
	0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,      // Code for char M
	0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,      // Code for char N
	0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,      // Code for char O
	0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,      // Code for char P
	0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,      // Code for char Q
	0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,      // Code for char R
	0x00, 0x26, 0x49, 0x49, 0x49, 0x32,      // Code for char S
	0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,      // Code for char T
	0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,      // Code for char U
	0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,      // Code for char V
	0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,      // Code for char W
	0x00, 0x63, 0x14, 0x08, 0x14, 0x63,      // Code for char X
	0x00, 0x03, 0x04, 0x78, 0x04, 0x03,      // Code for char Y
	0x00, 0x61, 0x51, 0x49, 0x45, 0x43       // Code for char Z
};

const char number[] =
{
	0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,      // Code for char 0
	0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,      // Code for char 1
	0x00, 0x72, 0x49, 0x49, 0x49, 0x46,      // Code for char 2
	0x00, 0x21, 0x41, 0x49, 0x4D, 0x33,      // Code for char 3
	0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,      // Code for char 4
	0x00, 0x27, 0x45, 0x45, 0x45, 0x39,      // Code for char 5
	0x00, 0x3C, 0x4A, 0x49, 0x49, 0x31,      // Code for char 6
	0x00, 0x41, 0x21, 0x11, 0x09, 0x07,      // Code for char 7
	0x00, 0x36, 0x49, 0x49, 0x49, 0x36,      // Code for char 8
	0x00, 0x06, 0x49, 0x49, 0x49, 0x3E       // Code for char 9
};

const char Symbol[] =
{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
		0x00, 0x80, 0x40, 0x20, 0x10, 0x08,
		0x00, 0x10, 0x10, 0x10, 0x10, 0x00,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x00, 0x88, 0x48, 0x20, 0x50, 0x48,
		0x00, 0x3C, 0x42, 0x81, 0x81, 0x00,
		0x00, 0x81, 0x81, 0x42, 0x3C, 0x00
};

void Glcd(char rs,char data)
{
	if(rs==1)
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
	if(rs==0)
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (data & 0x01));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (data & 0x02));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (data & 0x04));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (data & 0x08));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (data & 0x10));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (data & 0x20));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (data & 0x40));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (data & 0x80));


	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
	HAL_Delay(1);
}

void LCD_Init(void)
{
	Glcd(0, 0x3F);
}

void Clear(void)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
	for(char row=0;row<8;row++)
	{
		Glcd(0,0xB8+row);
		Glcd(0, 0x40);
		char s1=64;
		while(s1--)
			Glcd(1, 0x00);
	}
}

void SetCursor(char sector,char x_axis,char y_axis)
{
	if(sector==0)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);
	}
	else if(sector==1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
	}
	Glcd(0, x_axis+0xB8);
	Glcd(0, y_axis+0x40);
	lcd_count=y_axis;
	axis=x_axis;
}

void loop(const char *data)
{
	for(short int loop = 0; loop < 6; loop++)
	{
		if(lcd_count==64)
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
			Glcd(0,0xB8+axis);
			Glcd(0,0x40);
		}
		if(lcd_count==128)
			lcd_count=0;
		if(invert==0)
			Glcd(1, (*(data+loop)));
		else if(invert==1)
			Glcd(1, ~(*(data+loop)));
		lcd_count++;
		if(test==0 && Button_Down_Result && Button_Move)
				Menu=6;
		else if(Button_Menu_Esc)
			Menu=1;
		else if(Button_Test_Enter)
			Menu=2;
		else if(Button_Down_Result)
			Menu=3;
		else if(Button_UP_Delete)
			Menu=4;
		else if(Button_Move)
			Menu=5;
	}

}

void Print(const char *data)
{
	while(*data)
		{
			if(*data >= 'A' && *data <= 'Z')
				loop( &c_letter[(*data - 'A')*6]);

			else if(*data >= 'a' && *data <= 'z')
				loop( &s_letter[(*data - 'a')*6]);

			else if(*data >= '0' && *data <= '9')
				loop( &number[(*data - '0')*6]);

			else if(*data == ' ')
				loop( &Symbol[0]);

			else if(*data == '.')
				loop( &Symbol[1*6]);

			else if(*data == ':')
				loop( &Symbol[2*6]);

			else if(*data == '/')
				loop( &Symbol[3*6]);

			else if(*data == '-')
				loop( &Symbol[4*6]);

			else if(*data == '%')
				loop( &Symbol[6*6]);

			else if(*data == '(')
				loop( &Symbol[7*6]);

			else if(*data == ')')
				loop( &Symbol[8*6]);
			data++;
		}
}

int Power(char times)
{
	int value=1;
	while(times--)
		value*=10;
	return value;
}

void Number(float value,char point)
{
	int data=0,tens=1;
	char digit=0,index=0,temp=point,c_value[10];

	data = (int)value;
	while(data >= tens)
		{
			digit++;
			tens*=10;
		}
	tens=1;

	for(;digit>=2;digit--)
	{
		tens=Power(digit-1);
		c_value[index++] = ((data/tens) + 48);
		data%=tens;
	}
	c_value[index++] = ((data%10) + 48);

	if(point & 15)
	{
		c_value[index++]='.';
		point=(point&0x0f);
		while(point--)
			{
				data=(int)value;
				value=value-(float)data;
				value=(value*(float)10.0);
				c_value[index++]=(48+(int)value);
			}
	}
	c_value[index] = '\0';
	if((temp & 0xf0)==32)
		File_Write(c_value);
	else if((temp & 0xf0)==16)
		string(c_value);
	else
		Print(c_value);
}

void Move(uint8_t move,char str1[],char str2[],char str3[])
{
	if(move==1)
	{
		invert=1;
		SetCursor(0, 7, 0);
		Print(str1);
		invert=0;
		SetCursor(0, 7, 54);
		Print(str2);
		SetCursor(1, 7, 64-(strlen(str3)*6));
		Print(str3);
	}
	else if(move==2)
	{
		SetCursor(0, 7, 0);
		Print(str1);
		invert=1;
		SetCursor(0, 7, 54);
		Print(str2);
		invert=0;
		SetCursor(1, 7, 64-(strlen(str3)*6));
		Print(str3);
	}
	else if(move==3)
	{
		SetCursor(0, 7, 0);
		Print(str1);
		SetCursor(0, 7, 54);
		Print(str2);
		invert=1;
		SetCursor(1, 7, 64-(strlen(str3)*6));
		Print(str3);
		invert=0;
	}
	Menu=invert=0;
}
void Cursor(char sector,char x_axis,char y_axis)
{
	if(!Menu)
	{
		SetCursor(sector, x_axis, y_axis);
		loop( &Symbol[5*6]);
		HAL_Delay(5);
	}
	SetCursor(sector, x_axis, y_axis);
	loop( &Symbol[0]);
	if(!Menu)
		HAL_Delay(5);
}
void display_value(char *data)
{
	if(count<10)
	{
		loop(&number[count*6]);
		data[pos]=48+count;
	}
	else if(count>=10 && count<=35)
	{
		loop(&c_letter[(count-10)*6]);
		data[pos]=65+(count-10);
	}
	else if(count==36)
	{
		loop( &Symbol[0]);
		data[pos]=' ';
	}
}
void Alpha_numeric(uint8_t limit,uint8_t move,uint8_t x_axis,uint8_t y_pos,uint8_t min,uint8_t max,char *data)
{
	static uint8_t y_axis=0,sector=0;
	if(pos==0)
	{
		sector=0;
		y_axis=y_pos;
	}
	if(Button_Move || Menu==5)
	{
		pos++;
		while(Button_Move);
		if(pos==limit)
			sector=pos=0;

		if(pos>=move)
		{
			sector=1;
			y_axis=((pos-move)*6);
		}
		else
			y_axis=y_pos+(pos*6);
		count=max-1;
		SetCursor(sector, x_axis, y_axis);
		Print(" ");
	}
	Cursor(sector,x_axis+1,y_axis);
	SetCursor(sector, x_axis, y_axis);
	if(Button_UP_Delete || Menu==4)
	{
		while(Button_UP_Delete);
		count++;
		if(count==max)
			count=min;
		display_value(data);
	}

	if(Button_Down_Result || Menu==3)
	{
		while(Button_Down_Result);
		if(count==min)
			count=max;
		count--;
		display_value(data);
	}
}
void lot(void)
{
	SetCursor(0, 6, 5);
	Print("    ENTER  LOT    ");
	SetCursor(0, 2, 52);
	Print(Lot);
	SetCursor(0, 2, 52);
	Print(" ");
	count=36;
	pos=0;
	strcpy(temp,Lot);
	while(1)
	{
		Menu=0;
		Alpha_numeric(8,2,2,52,0,37,Lot);
		if(Button_Test_Enter || Menu==2)
		{
			Lot[pos+1]='\0';
			Menu=pos=0;
			break;
		}
		if(Button_Menu_Esc || Menu==1)
		{
			strcpy(Lot,temp);
			Menu=0;
			break;
		}
	}
}
void Name()
{
	SetCursor(0, 0, 0);
	Print("                     ");
	Menu=pos=invert=0;
	SetCursor(0, 6, 5);
	Print("    ENTER  NAME   ");
	strcpy(temp,name);
	count=36;
	while(1)
	{
		Menu=0;
		Alpha_numeric(20, 10, 0, 4, 10, 37, name);
		if(Button_Test_Enter || Menu==2)
		{
			name[pos+1]='\0';
			HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0x00, 1, name, strlen(name), 1000);
			Menu=pos=0;
			break;
		}
		if(Button_Menu_Esc || Menu==1)
		{
			Menu=0;
			strcpy(name,temp);
			break;
		}
	}
}
void File()
{
	Clear();
	Menu=pos=0;
	SetCursor(0, 0, 4);
	Print("File :");
	count=36;
	while(1)
	{

		Menu=0;
		Alpha_numeric(8, 4, 0,39, 0, 37, File_name);
		if(Button_Test_Enter || Menu==2)
		{
			File_name[pos+1]='.',File_name[pos+2]='C',File_name[pos+3]='S',File_name[pos+4]='V',File_name[pos+5]='\0';
			Menu=pos=0;
			Pendrive_Init();
			Checking_File();
			break;
		}
		if(Button_Menu_Esc || Menu==1)
		{
			File_name[0]='/',File_name[1]='\0';
			Menu=0;
			break;
		}
	}
}

void Blink(char *char_set)
{
	SetCursor(0, 6, 5);
	if(!(Button_Menu_Esc ||Button_Test_Enter || Menu))
	{
		Print(char_set);
		HAL_Delay(5);
		if(Menu==0)
		{
		SetCursor(0, 6, 5);
		Print("                  ");
		HAL_Delay(5);
		}
	}
	if(Button_Menu_Esc)
		Menu=1;
}

void Result()
{
	float add=0;
	char row=1;
	SetCursor(0, 0, 0);
	Print("ug/in");
	SetCursor(1, 0, 0);
	Print("ug/in");
	for(short int i=0;i<test;i++)
	{
		if((i%2)==0)
			SetCursor(0, row, 0);
		else
			SetCursor(1, row++, 0);

		if(i<9)
		{
			Print(" ");
			Number(i+1, 0);
		}
		else
			Print("10");
		Print("-");
		Number(mic_value[i],2);
		add+=mic_value[i];
	}
	SetCursor(0, 6, 0);
	Print("AVERAGE : ");
	Number((add/(float)test),2);
	Print("ug/inch");
}
void printer()
{
	Heading(1);
	string(" AIS Digi mic smart - 12 \r\n");
	Heading(0);
	string(" ");
	string(name);
		string("\r");
		string(" LOT NO : ");
		string(Lot);
		string("\r\n");
		string(" TEST-#    mic(ug/inch)\r\n");
		float add=0;
		for(char print=1;print<=test;print++)
		{
			string("  ");
			if(print<10)
			{
				string(" ");
				Number(print,16);
			}
			else
				string("10");
			string("          ");
			Number(mic_value[print-1], 18);
			add+=mic_value[print-1];
			string("\r");
		}
		add=add/(float)test;
		Heading(1);
		string(" ---------------------- \r");
		string(" AVERAGE   ");
		Number(add,18);
		string("\r");
		string(" ----------------------- \r\n\n\n");
}
void Password()
{
	char pas[4];
	Menu=pos=0;
	count=9;
	while(1)
	{
		Menu=0;
		for(uint8_t i=0;i<4;i++)
		{
			if(i!=pos)
			{
				if(i>=2)
					SetCursor(1, 2, (i-2)*6);
				else
					SetCursor(0, 2, 52+(i*6));
				Print("-");
			}
		}
		Alpha_numeric(4, 2, 2, 52, 0, 10, pas);

		if(Button_Test_Enter || Menu==2)
		{
			Menu=0;
			if(pas[0]=='8'&&pas[1]=='4'&&pas[2]=='2'&&pas[3]=='1')
			{
				Clear();
				HAL_I2C_Mem_Read(&hi2c1, 0xA1, 0xF0, 1, &calibrate, 1, 1000);
				SetCursor(0, 0, 20);
				Print("   ENTER CF   ");
				SetCursor(0, 2, 52);
				Number(calibrate,0);
				Print("%(90-110)");
				while(1)
				{
					Menu=0;
					if(Button_UP_Delete || Menu==4)
					{
						if(calibrate<110)
							calibrate++;
						while(Button_UP_Delete);
						SetCursor(0, 2, 52);
						if(calibrate<100)
							Number(0, 0);
						Number(calibrate,0);
					}
					if(Button_Down_Result || Menu==3)
					{
						if(calibrate>90)
							calibrate--;
						while(Button_Down_Result);
						SetCursor(0, 2, 52);
						if(calibrate<100)
							Number(0, 0);
						Number(calibrate,0);
					}
					if(Button_Test_Enter)
					{
						HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0xF0, 1, &calibrate, 1, 1000);
						break;
					}
					if(Button_Menu_Esc)
					{
						HAL_I2C_Mem_Read(&hi2c1, 0xA1, 0xF0, 1, &calibrate, 1, 1000);
						break;
					}
				}
			}
			else
			{
				Clear();
				SetCursor(0, 2, 20);
				Print("WRONG PASSWORD");
				break;
			}
			Menu=pos=0;
			break;
		}
		if(Button_Menu_Esc || Menu==1)
		{
			Menu=0;
			break;
		}
	}
	Clear();
	Test_Mode();
	Blank(0);
}
void System()
{
	uint8_t option=1;
	SetCursor(0, 7, 0);
	Print("      ");
	Move(option,"USB","NEW","SYSTEM");
	while(!(Button_Menu_Esc) && option!=0)
	{
		if(Button_Move)
		{
			option++;
			if(option==4)
				option=1;
			Move(option,"USB","NEW","SYSTEM");
		}
		while(Button_Move);
		if(Button_Test_Enter)
		{
			while(Button_Test_Enter);
			if(option==1)
				File();
			else if(option ==2)
				test=option=0;
			else if(option ==3)
			{
				out=1;
				printer();
			}
			option=out=0;
		}
	}
}
void start_up()
{
	Menu=0;
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 1);
	Battry_volt=HAL_ADC_GetValue(&hadc2);
	HAL_ADC_Stop(&hadc2);

//	if(Battry_volt)	// if the voltage is equal to 1.5V the work will go ahead
	{
		if(test<10)
			Blink("READY FOR THE TEST");
		else
			Blink("  TEST COMPLETED  ");
		if(Menu==6)
		{
			Menu=0;
			Clear();
			SetCursor(0, 0, 20);
			Print("ENTER PASSWORD");
			Password();
		}
		else if(Button_Menu_Esc || Menu==1)
		{
			uint8_t option=1;
			SetCursor(0, 6, 5);
			Print("  CHOOSE  OPTION  ");
			Move(option,"NAME","NEW","LOT");
			while(Button_Menu_Esc);
			while(!(Button_Menu_Esc) && option!=0 )
			{
				if(Button_Move)
				{
					option++;
					if(option==4)
						option=1;
					Move(option,"NAME","NEW","LOT");
				}
				while(Button_Move);
				if(Button_Test_Enter)
				{
					while(Button_Test_Enter);
					if(option==1)
						Name();
					else if(option ==2)
						test=option=0;
					else if(option ==3)
						lot();
					option=0;
				}
			}
			Clear();
			Test_Mode();
			Blank(1);
			Menu=0;
		}

		else if(Button_Test_Enter || Menu==2)
   		{
   			Menu=0;
   			while((Button_Test_Enter));
   			if(test<10)
   			{
   				test++;
   				SetCursor(0, 6, 5);
   				Print("   PROCESSING...  ");
   				Blank(0);
   				value=1,limit=350,max=0,a_max=0;
   				volt_a=390;
   				while((((int)volt_a)>limit) )//&& Menu!=1)
   				{
   					SetCursor(1, 6, 21);
   					Print("   ");
   					HAL_Delay(1);

   					HAL_ADC_Start(&hadc1);
   					for(int i=0;i<1000;i++)
   					{
   					  HAL_ADC_PollForConversion(&hadc1, 1);
   					  value+=HAL_ADC_GetValue(&hadc1);
   					  if(Button_Menu_Esc)
   						  Menu=1;
   					}
   					max=value/1000;
//	   					if(max<value)
//	   						max=value;

   					volt_a=(((float)max*(float)0.0008058608058)*(float)1000.0);

   					if(a_max<(int)volt_a)
   					{
   						a_volt=volt_a*2.0;
   						a_max=(int)volt_a;
   					}
   					value=0;
   					if((int)volt_a>300)
   					  limit=400;

   					SetCursor(1, 6, 21);
   					Print("...");
   					HAL_Delay(1);
   				  }

   				if(Menu==1)
   				{
   					if(test!=0)
   						test--;
   					Blank(1);
   					SetCursor(0, 6, 5);
   					Print("      CANCLED     ");
   					HAL_Delay(1000);
   				}
   				else
   					Conversition(a_max);
   				Menu=0;
   			}
   		}
		else if(Button_Down_Result || Menu==3)
		{
			while(Button_Down_Result);
			if(test!=0)
			{
				Clear();
				uint8_t option=1;
				Result();
				Move(option,"OUTPUT","NEW","PRINT");
				while(!(Button_Menu_Esc) && option!=0)
				{
					if(Button_Move)
					{
						option++;
						if(option==4)
							option=1;
						Move(option,"OUTPUT","NEW","PRINT");
					}
					while(Button_Move);
					if(Button_Test_Enter)
					{
						while(Button_Test_Enter);
						if(option==1)
							System();
						else if(option ==2)
							test=option=0;
						else if(option ==3)
							printer();
						option=0;
					}
				}
				Clear();
				Test_Mode();
				Blank(1);
				Menu=0;
			}
		}
		else if(Button_UP_Delete || Menu==4)
			Delete();
		while(Button_UP_Delete);
	}
//	else
//		Blink("    LOW BATTRY    ");

}
void Delete()
{
	Menu=0;
	if(test!=0)
		test--;
	SetCursor(0, 6, 5);
	Print("    Deleting...   ");
	HAL_Delay(5);
	SetCursor(0, 6, 30);
	Print("           ");
	HAL_Delay(5);
	Blank(1);

}
void Blank(char init)
{
	SetCursor(0, 4, 30);
	if(test<10)
	{
		Print("0");
		Number(test, 0);
	}
	else
		Print("10");
	Print(":");

	SetCursor(0, 4, 52);

	if(init==0||test==0)
		Print("    ");
	else
		Number(mic_value[test-1],2);
	Print(" ug/inch");
}
void Test_Mode()
{
	SetCursor(0, 0, 0);
	Print(name);
	SetCursor(0, 2, 0);
	Print("LOT NO :");
	SetCursor(0, 2, 52);
	Print(Lot);
	SetCursor(0, 4, 0);
	Print("TEST-");
}

void Mic_conversition(float mic,int Volt,int min,float multiplier)
{
	float find =(((float)(Volt - min)) * multiplier);
	mic_value[test-1]=mic-=((int)find/(float)10.0);
	Blank(1);
	SetCursor(0, 6, 5);
	Print("        OK        ");
	HAL_Delay(1000);
}

void Conversition(short int Volt)
{

	if(Volt <= 810 && Volt >=766)
		Mic_conversition(2.6, Volt, 766, 0.159);

	else if(Volt <= 765 && Volt >=708)
		Mic_conversition(3.5, Volt, 708, 0.158);

	else if(Volt <=707  && Volt >=618)
		Mic_conversition(5.0, Volt, 618, 0.169);

	else if(Volt <= 617 && Volt >=588)
		Mic_conversition(5.6, Volt, 588, 0.207);

	else if(Volt <= 587 && Volt >=547)
		Mic_conversition(6.5, Volt, 547, 0.225);

	else
	{
		SetCursor(0, 6, 5);
		Print("     REJECTED     ");
		test--;
		Blank(1);
		HAL_Delay(1000);
	}
}


//#include "LCD_Header.h"
//#include "Printer_Header.h"
//char lcd_count=0,axis,Lot[9]="        ",name[21],invert=0,pos=0,Menu=0;
//uint16_t Battry_volt=0;
//short int test=0,calibrate=100;
//float mic_value[10];
//uint16_t limit=350,max=0,a_max=0;
//int value=0;
//float volt_a=390,a_volt=0;
//const char s_letter[] =
//{
//    0x00, 0x20, 0x54, 0x54, 0x78, 0x40,      // Code for char a
//	0x00, 0x7F, 0x28, 0x44, 0x44, 0x38,      // Code for char b
//	0x00, 0x38, 0x44, 0x44, 0x44, 0x28,      // Code for char c
//	0x00, 0x38, 0x44, 0x44, 0x28, 0x7F,      // Code for char d
//	0x00, 0x38, 0x54, 0x54, 0x54, 0x18,      // Code for char e
//	0x00, 0x00, 0x08, 0x7E, 0x09, 0x02,      // Code for char f
//	0x00, 0x18, 0xA4, 0xA4, 0x9C, 0x78,      // Code for char g
//	0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,      // Code for char h
//	0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,      // Code for char i
//	0x00, 0x20, 0x40, 0x40, 0x3D, 0x00,      // Code for char j
//	0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,      // Code for char k
//	0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,      // Code for char l
//	0x00, 0x7C, 0x04, 0x78, 0x04, 0x78,      // Code for char m
//	0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,      // Code for char n
//	0x00, 0x38, 0x44, 0x44, 0x44, 0x38,      // Code for char o
//	0x00, 0xFC, 0x18, 0x24, 0x24, 0x18,      // Code for char p
//	0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,      // Code for char q
//	0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,      // Code for char r
//	0x00, 0x48, 0x54, 0x54, 0x54, 0x24,      // Code for char s
//	0x00, 0x04, 0x04, 0x3F, 0x44, 0x24,      // Code for char t
//	0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,      // Code for char u
//	0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,      // Code for char v
//	0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,      // Code for char w
//	0x00, 0x44, 0x28, 0x10, 0x28, 0x44,      // Code for char x
//	0x00, 0x4C, 0x90, 0x90, 0x90, 0x7C,      // Code for char y
//	0x00, 0x44, 0x64, 0x54, 0x4C, 0x44       // Code for char z
//};
//
//const char c_letter[] =
//{
//   	0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E,      // Code for char A
//	0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,      // Code for char B
//	0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,      // Code for char C
//	0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E,      // Code for char D
//	0x00, 0x7F, 0x49, 0x49, 0x49, 0x49,      // Code for char E
//	0x00, 0x7F, 0x09, 0x09, 0x09, 0x09,      // Code for char F
//	0x00, 0x3E, 0x41, 0x41, 0x51, 0x73,      // Code for char G
//	0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,      // Code for char H
//	0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,      // Code for char I
//	0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,      // Code for char J
//	0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,      // Code for char K
//	0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,      // Code for char L
//	0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,      // Code for char M
//	0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,      // Code for char N
//	0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,      // Code for char O
//	0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,      // Code for char P
//	0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,      // Code for char Q
//	0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,      // Code for char R
//	0x00, 0x26, 0x49, 0x49, 0x49, 0x32,      // Code for char S
//	0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,      // Code for char T
//	0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,      // Code for char U
//	0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,      // Code for char V
//	0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,      // Code for char W
//	0x00, 0x63, 0x14, 0x08, 0x14, 0x63,      // Code for char X
//	0x00, 0x03, 0x04, 0x78, 0x04, 0x03,      // Code for char Y
//	0x00, 0x61, 0x51, 0x49, 0x45, 0x43       // Code for char Z
//};
//
//const char number[] =
//{
//	0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,      // Code for char 0
//	0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,      // Code for char 1
//	0x00, 0x72, 0x49, 0x49, 0x49, 0x46,      // Code for char 2
//	0x00, 0x21, 0x41, 0x49, 0x4D, 0x33,      // Code for char 3
//	0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,      // Code for char 4
//	0x00, 0x27, 0x45, 0x45, 0x45, 0x39,      // Code for char 5
//	0x00, 0x3C, 0x4A, 0x49, 0x49, 0x31,      // Code for char 6
//	0x00, 0x41, 0x21, 0x11, 0x09, 0x07,      // Code for char 7
//	0x00, 0x36, 0x49, 0x49, 0x49, 0x36,      // Code for char 8
//	0x00, 0x06, 0x49, 0x49, 0x49, 0x3E       // Code for char 9
//};
//
//const char Symbol[] =
//{
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
//		0x00, 0x80, 0x40, 0x20, 0x10, 0x08,
//		0x00, 0x10, 0x10, 0x10, 0x10, 0x00,
//		0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
//		0x00, 0x88, 0x48, 0x20, 0x50, 0x48,
//		0x00, 0x3C, 0x42, 0x81, 0x81, 0x00,
//		0x00, 0x81, 0x81, 0x42, 0x3C, 0x00
//};
//
//void Glcd(char rs,char data)
//{
//	if(rs==1)
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
//	if(rs==0)
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
//
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);
//
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (data & 0x01));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (data & 0x02));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (data & 0x04));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (data & 0x08));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (data & 0x10));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (data & 0x20));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (data & 0x40));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (data & 0x80));
//
//
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1);
//	HAL_Delay(1);
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0);
//	HAL_Delay(1);
//}
//
//void LCD_Init(void)
//{
//	Glcd(0, 0x3F);
//}
//
//void Clear(void)
//{
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
//	for(char row=0;row<8;row++)
//	{
//		Glcd(0,0xB8+row);
//		Glcd(0, 0x40);
//		char s1=64;
//		while(s1--)
//			Glcd(1, 0x00);
//	}
//}
//
//void SetCursor(char sector,char x_axis,char y_axis)
//{
//	if(sector==0)
//	{
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 1);
//	}
//	else if(sector==1)
//	{
//		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
//	}
//	Glcd(0, x_axis+0xB8);
//	Glcd(0, y_axis+0x40);
//	lcd_count=y_axis;
//	axis=x_axis;
//}
//
//void loop(const char *data)
//{
//	for(short int loop = 0; loop < 6; loop++)
//	{
//		if(lcd_count==64)
//		{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, 0);
//			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
//			Glcd(0,0xB8+axis);
//			Glcd(0,0x40);
//		}
//		if(lcd_count==128)
//			lcd_count=0;
//		if(invert==0)
//			Glcd(1, (*(data+loop)));
//		else
//			Glcd(1, ~(*(data+loop)));
//		lcd_count++;
//		if(test==0 && Button_Down_Result && Button_Move)
//				Menu=6;
//		else if(Button_Menu_Esc)
//			Menu=1;
//		else if(Button_Test_Enter)
//			Menu=2;
//		else if(Button_Down_Result)
//			Menu=3;
//		else if(Button_UP_Delete)
//			Menu=4;
//		else if(Button_Move)
//			Menu=5;
//	}
//
//}
//
//void Print(const char *data)
//{
//	while(*data)
//		{
//			if(*data >= 'A' && *data <= 'Z')
//				loop( &c_letter[(*data - 'A')*6]);
//
//			else if(*data >= 'a' && *data <= 'z')
//				loop( &s_letter[(*data - 'a')*6]);
//
//			else if(*data >= '0' && *data <= '9')
//				loop( &number[(*data - '0')*6]);
//
//			else if(*data == ' ')
//				loop( &Symbol[0]);
//
//			else if(*data == '.')
//				loop( &Symbol[1*6]);
//
//			else if(*data == ':')
//				loop( &Symbol[2*6]);
//
//			else if(*data == '/')
//				loop( &Symbol[3*6]);
//
//			else if(*data == '-')
//				loop( &Symbol[4*6]);
//
//			else if(*data == '%')
//				loop( &Symbol[6*6]);
//
//			else if(*data == '(')
//				loop( &Symbol[7*6]);
//
//			else if(*data == ')')
//				loop( &Symbol[8*6]);
//			data++;
//		}
//}
//
//int Power(char times)
//{
//	int value=1;
//	while(times--)
//		value*=10;
//	return value;
//}
//
//void Number(float value,char point)
//{
//	int data=0,tens=1;
//	char digit=0,index=0,temp=point,c_value[10];
//
//	data = (int)value;
//	while(data >= tens)
//		{
//			digit++;
//			tens*=10;
//		}
//	tens=1;
//
//	for(;digit>=2;digit--)
//	{
//		tens=Power(digit-1);
//		c_value[index++] = ((data/tens) + 48);
//		data%=tens;
//	}
//	c_value[index++] = ((data%10) + 48);
//
//	if(point & 15)
//	{
//		c_value[index++]='.';
//		point=(point&0x0f);
//		while(point--)
//			{
//				data=(int)value;
//				value=value-(float)data;
//				value=(value*(float)10.0);
//				c_value[index++]=(48+(int)value);
//			}
//	}
//	c_value[index] = '\0';
//	if((temp & 0xf0)==32)
//		File_Write(c_value);
//	else if((temp & 0xf0)==16)
//		string(c_value);
//	else
//		Print(c_value);
//}
//
//void Move(uint8_t move,char str1[],char str2[],char str3[])
//{
//	if(move==1)
//	{
//		invert=1;
//		SetCursor(0, 7, 0);
//		Print(str1);
//		invert=0;
//		SetCursor(0, 7, 54);
//		Print(str2);
//		SetCursor(1, 7, 64-(strlen(str3)*6));
//		Print(str3);
//	}
//	else if(move==2)
//	{
//		SetCursor(0, 7, 0);
//		Print(str1);
//		invert=1;
//		SetCursor(0, 7, 54);
//		Print(str2);
//		invert=0;
//		SetCursor(1, 7, 64-(strlen(str3)*6));
//		Print(str3);
//	}
//	else if(move==3)
//	{
//		SetCursor(0, 7, 0);
//		Print(str1);
//		SetCursor(0, 7, 54);
//		Print(str2);
//		invert=1;
//		SetCursor(1, 7, 64-(strlen(str3)*6));
//		Print(str3);
//		invert=0;
//	}
//	Menu=0;
//}
//void Cursor(char sector,char x_axis,char y_axis)
//{
//	if(!Menu)
//	{
//		SetCursor(sector, x_axis, y_axis);
//		loop( &Symbol[5*6]);
//		HAL_Delay(5);
//	}
//	SetCursor(sector, x_axis, y_axis);
//	loop( &Symbol[0]);
//	if(!Menu)
//		HAL_Delay(5);
//}
//void lot(void)
//{
//	char count=0,value=48,sector=0,y_axis=52;
//	SetCursor(0, 2, 52);
//	Print("        ");
//	SetCursor(0, 6, 5);
//	Print("    ENTER  LOT    ");
//	SetCursor(0, 2, 52);
//	Print("0");
//	Menu=0;
//	while(1)
//	{
//		if(Button_Move || Menu==5)
//		{
//			pos++;
//			while(Button_Move);
//
//			if(pos==8)
//				pos=0;
//			if(pos<2)
//			{
//				sector=0;
//				y_axis=52+(pos*6);
//			}
//			else
//			{
//				sector=1;
//				y_axis=(pos-2)*6;
//			}
//			SetCursor(sector, 2, y_axis);
//			Print("0");
//			Menu=Lot[pos]=count=0;
//			value=48;
//		}
//		Cursor(sector,3,y_axis);
//		if(Button_UP_Delete || Menu==4)
//		{
//			Menu=0;
//			while(Button_UP_Delete);
//			SetCursor(sector, 2, y_axis);
//
//			if(count==37)
//				count=0;
//
//			count++;
//			if(count<10)
//				loop(&number[count*6]);
//			else if(count>9 && count < 37)
//				loop(&c_letter[(count-10)*6]);
//
//			if(value==57)
//				value=64;
//			else if(value==90)
//				value=47;
//			value++;
//		}
//
//		if(Button_Down_Result || Menu==3)
//		{
//			while(Button_Down_Result);
//			SetCursor(sector, 2, y_axis);
//			if(count==0)
//				count=36;
//
//			count--;
//			if(count>9 && count < 37)
//				loop(&c_letter[(count-10)*6]);
//			else if(count<10)
//				loop(&number[count*6]);
//			if(value==48)
//				value=91;
//			else if(value==65)
//				value=58;
//			value--;
//			Menu=0;
//		}
//		Lot[pos]=value;
//		if(Button_Test_Enter || Menu==2)
//		{
//			Lot[pos+1]='\0';
//			Menu=pos=0;
//			break;
//		}
//		if(Button_Menu_Esc || Menu==1)
//		{
//			Lot[0]='\0';
//			Menu=0;
//			break;
//		}
//	}
//}
//void Name()
//{
//	char count=0,value=32,len=strlen(name),sector=0,y_axis=0;
//	SetCursor(0, 0, 0);
//	Print("                     ");
//	Menu=pos=0;
//	SetCursor(0, 6, 5);
//	Print("    ENTER  NAME   ");
//	while(1)
//	{
//		if(Button_Move || Menu==5)
//		{
//			while(Button_Move);
//			pos++;
//			if(pos==20)
//				pos=0;
//			if(pos<11)
//			{
//				sector=0;
//				y_axis=pos*6;
//			}
//			else
//			{
//				sector=1;
//				y_axis=((pos-11)*6)+2;
//			}
//
//			Lot[pos]=32;
//			Menu=count=0;
//			value=32;
//
//		}
//		Cursor(sector,1,y_axis);
//		if(Button_UP_Delete || Menu==4)
//		{
//			while(Button_UP_Delete);
//			SetCursor(sector, 0, y_axis);
//
//			if(count==26)
//				count=-1;
//
//			count++;
//			if(count==0)
//				loop(&Symbol[0]);
//			else if(count>0 && count <= 26)
//				loop(&c_letter[(count-1)*6]);
//
//			value++;
//			if(value==33)
//				value=65;
//			else if(value==91)
//				value=32;
//			Menu=0;
//		}
//
//		if(Button_Down_Result || Menu==3)
//		{
//			while(Button_Down_Result);
//			SetCursor(sector, 0, y_axis);
//
//			if(count==0)
//				count=27;
//
//			count--;
//			if(count>0 && count < 27)
//				loop(&c_letter[(count-1)*6]);
//			else if(count==0)
//				loop(&Symbol[0]);
//
//			value--;
//			if(value==31)
//				value=90;
//			else if(value==64)
//				value=32;
//			Menu=0;
//		}
//		name[pos]=value;
//		if(Button_Test_Enter || Menu==2)
//		{
//			// EEPROM write
//			name[pos+1]='\0';
//			HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0x00, 1, name, strlen(name), 1000);
//			Menu=pos=0;
//			break;
//		}
//		if(Button_Menu_Esc || Menu==1)
//		{
//			if(pos>len)
//				name[pos+1]='\0';
//			Menu=0;
//			HAL_I2C_Mem_Read(&hi2c1, 0xA1, 0x00, 1, &name, strlen(name), 1000);
//			break;
//		}
//	}
//}
//void File()
//{
//	Clear();
//	char count=0,value=48,len=strlen(name),sector=1,y_axis=2;
//	Menu=pos=0;
//	SetCursor(0, 1, 0);
//	Print("File Name :");
//	while(1)
//	{
//		if(Button_Move || Menu==5)
//		{
//			while(Button_Move);
//			pos++;
//			if(pos==8)
//				pos=0;
//
//			y_axis=((pos*6)+2);
//
//			File_name[pos+1]=value=32;
//			Menu=count=0;
//
//			Cursor(sector,2,y_axis);
//			Menu=File_name[pos+1]=count=0;
//			value=48;
//		}
//		Cursor(sector,2,y_axis);
//		if(Button_UP_Delete || Menu==4)
//		{
//			Menu=0;
//			while(Button_UP_Delete);
//			SetCursor(sector, 1, y_axis);
//
//			if(count==37)
//				count=0;
//
//			count++;
//			if(count<10)
//				loop(&number[count*6]);
//			else if(count>9 && count < 37)
//				loop(&c_letter[(count-10)*6]);
//
//			if(value==57)
//				value=64;
//			else if(value==90)
//				value=47;
//			value++;
//		}
//
//		if(Button_Down_Result || Menu==3)
//		{
//			while(Button_Down_Result);
//			SetCursor(sector, 1, y_axis);
//			if(count==0)
//				count=36;
//
//			count--;
//			if(count>9 && count < 37)
//				loop(&c_letter[(count-10)*6]);
//			else if(count<10)
//				loop(&number[count*6]);
//			if(value==48)
//				value=91;
//			else if(value==65)
//				value=58;
//			value--;
//			Menu=0;
//		}
//		File_name[pos+1]=value;
//		if(Button_Test_Enter || Menu==2)
//		{
//			File_name[pos+2]='.',File_name[pos+3]='C',File_name[pos+4]='S',File_name[pos+5]='V',File_name[pos+6]='\0';
//			Menu=pos=0;
//			Checking_File();
//			break;
//		}
//		if(Button_Menu_Esc || Menu==1)
//		{
//			File_name[0]='/',File_name[1]='\0';
//			Menu=0;
//			break;
//		}
//	}
//}
//
//void Blink(char *char_set)
//{
//	SetCursor(0, 6, 5);
//	if(!(Button_Menu_Esc ||Button_Test_Enter || Menu))
//	{
//		Print(char_set);
//		HAL_Delay(5);
//		if(Menu==0)
//		{
//		SetCursor(0, 6, 5);
//		Print("                  ");
//		HAL_Delay(5);
//		}
//	}
//	if(Button_Menu_Esc)
//		Menu=1;
//}
//
//void Result()
//{
//	float add=0;
//	char row=1;
//	SetCursor(0, 0, 0);
//	Print("ug/in");
//	SetCursor(1, 0, 0);
//	Print("ug/in");
//	for(short int i=0;i<test;i++)
//	{
//		if((i%2)==0)
//			SetCursor(0, row, 0);
//		else
//			SetCursor(1, row++, 0);
//
//		if(i<9)
//		{
//			Print(" ");
//			Number(i+1, 0);
//		}
//		else
//			Print("10");
//		Print("-");
//		Number(mic_value[i],2);
//		add+=mic_value[i];
//	}
//	SetCursor(0, 6, 0);
//	Print("AVERAGE : ");
//	Number((add/(float)test),2);
//	Print("ug/inch");
//}
//void printer()
//{
//	Heading(1);
//	string(" AIS Digi mic smart - 12 \r\n");
//	Heading(0);
//	string(" ");
//	string(name);
//		string("\r");
//		string(" LOT NO : ");
//		string(Lot);
//		string("\r\n");
//		string(" TEST-#    mic(ug/inch)\r\n");
//		float add=0;
//		for(char print=1;print<=test;print++)
//		{
//			string("  ");
//			if(print<10)
//			{
//				string(" ");
//				Number(print,16);
//			}
//			else
//				string("10");
//			string("          ");
//			Number(mic_value[print-1], 18);
//			add+=mic_value[print-1];
//			string("\r");
//		}
//		add=add/(float)test;
//		Heading(1);
//		string(" ---------------------- \r");
//		string(" AVERAGE   ");
//		Number(add,18);
//		string("\r");
//		string(" ----------------------- \r\n\n\n");
//}
//void Password()
//{
//	char count=0,sector=0,y_axis=52,pas[4];
//	Menu=pos=0;
//	SetCursor(sector, 2, y_axis);
//	Print("0---");
//	while(1)
//	{
//		if(Button_Move || Menu==5)
//		{
//			pos++;
//			while(Button_Move);
//
//			if(pos==4)
//				pos=0;
//			if(pos<2)
//			{
//				sector=0;
//				y_axis=52+(pos*6);
//			}
//			else
//			{
//				sector=1;
//				y_axis=(pos-2)*6;
//			}
//			SetCursor(0, 2, 52);
//			Print("----");
//			SetCursor(sector, 2, y_axis);
//			Print("0");
//			Menu=count=0;
//		}
//		if(Button_UP_Delete || Menu==4)
//		{
//			Menu=0;
//			while(Button_UP_Delete);
//			SetCursor(sector, 2, y_axis);
//
//			if(count==9)
//				count=-1;
//
//			count++;
//			loop(&number[count*6]);
//		}
//		if(Button_Down_Result || Menu==3)
//		{
//			Menu=0;
//			while(Button_Down_Result);
//			SetCursor(sector, 2, y_axis);
//
//			if(count==0)
//				count=10;
//
//			count--;
//			loop(&number[count*6]);
//
//		}
//		pas[pos]=count+48;
//		if(Button_Test_Enter || Menu==2)
//		{
//			Menu=0;
//			if(pas[0]=='8'&&pas[1]=='4'&&pas[2]=='2'&&pas[3]=='1')
//			{
//				Clear();
//				HAL_I2C_Mem_Read(&hi2c1, 0xA1, 0xF0, 1, &calibrate, 1, 1000);
//				SetCursor(0, 0, 20);
//				Print("   ENTER CF   ");
//				SetCursor(0, 2, 52);
//				Number(calibrate,0);
//				Print("%(90-110)");
//				while(1)
//				{
//					Menu=0;
//					if(Button_UP_Delete || Menu==4)
//					{
//						if(calibrate<110)
//							calibrate++;
//						while(Button_UP_Delete);
//						SetCursor(0, 2, 52);
//						if(calibrate<100)
//							Number(0, 0);
//						Number(calibrate,0);
//					}
//					if(Button_Down_Result || Menu==3)
//					{
//						if(calibrate>90)
//							calibrate--;
//						while(Button_Down_Result);
//						SetCursor(0, 2, 52);
//						if(calibrate<100)
//							Number(0, 0);
//						Number(calibrate,0);
//					}
//					if(Button_Test_Enter)
//					{
//						HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0xF0, 1, &calibrate, 1, 1000);
//						break;
//					}
//					if(Button_Menu_Esc)
//					{
//						HAL_I2C_Mem_Read(&hi2c1, 0xA1, 0xF0, 1, &calibrate, 1, 1000);
//						break;
//					}
//				}
//			}
//			else
//			{
//				Clear();
//				SetCursor(0, 2, 20);
//				Print("WRONG PASSWORD");
//				break;
//			}
//			Menu=pos=0;
//			break;
//		}
//		if(Button_Menu_Esc || Menu==1)
//		{
//			Menu=0;
//			break;
//		}
//	}
//	Clear();
//	Test_Mode();
//	Blank(0);
//}
//void start_up()
//{
//	Menu=0;
//	HAL_ADC_Start(&hadc2);
//	HAL_ADC_PollForConversion(&hadc2, 1);
//	Battry_volt=HAL_ADC_GetValue(&hadc2);
//	HAL_ADC_Stop(&hadc2);
//
////	if(Battry_volt)	// if the voltage is equal to 1.5V the work will go ahead
//	{
//		if(test<10)
//			Blink("READY FOR THE TEST");
//		else
//			Blink("  TEST COMPLETED  ");
//		if(Menu==6)
//		{
//			Menu=0;
//			Clear();
//			SetCursor(0, 0, 20);
//			Print("ENTER PASSWORD");
//			SetCursor(0, 2, 52);
//			Print("0---");
//			Password();
//		}
//		else if(Button_Menu_Esc || Menu==1)
//		{
//			Menu=0;
//			uint8_t option=1;
//			SetCursor(0, 6, 5);
//			Print("  CHOOSE  OPTION  ");
//			Move(option,"NAME","NEW","LOT");
//			while(Button_Menu_Esc);
//			while(!(Button_Menu_Esc) && option!=0 )
//			{
//				if(Button_Move)
//				{
//					option++;
//					if(option==4)
//						option=1;
//					Move(option,"NAME","NEW","LOT");
//				}
//				while(Button_Move);
//				if(Button_Test_Enter)
//				{
//					while(Button_Test_Enter);
//					if(option==1)
//						Name();
//					else if(option ==2)
//						test=option=0;
//					else if(option ==3)
//						lot();
//					option=0;
//				}
//			}
//			Clear();
//			Test_Mode();
//			Blank(1);
//		}
//
//		else if(Button_Test_Enter || Menu==2)
//   		{
//   			Menu=0;
//   			while((Button_Test_Enter));
//   			if(test<10)
//   			{
//   				test++;
//   				SetCursor(0, 6, 5);
//   				Print("   PROCESSING...  ");
//   				Blank(0);
//   				value=1,limit=350,max=0,a_max=0;
//   				volt_a=390;
//   				while((((int)volt_a)>limit) )//&& Menu!=1)
//   				{
//   					SetCursor(1, 6, 21);
//   					Print("   ");
//   					HAL_Delay(1);
//
//   					HAL_ADC_Start(&hadc1);
//   					for(int i=0;i<1000;i++)
//   					{
//   					  HAL_ADC_PollForConversion(&hadc1, 1);
//   					  value+=HAL_ADC_GetValue(&hadc1);
//   					  if(Button_Menu_Esc)
//   						  Menu=1;
//   					}
//   					max=value/1000;
////	   					if(max<value)
////	   						max=value;
//
//   					volt_a=(((float)max*(float)0.0008058608058)*(float)1000.0);
//
//   					if(a_max<(int)volt_a)
//   					{
//   						a_volt=volt_a*2.0;
//   						a_max=(int)volt_a;
//   					}
//   					value=0;
//   					if((int)volt_a>300)
//   					  limit=400;
//
//   					SetCursor(1, 6, 21);
//   					Print("...");
//   					HAL_Delay(1);
//   				  }
//
//   				if(Menu==1)
//   				{
//   					if(test!=0)
//   						test--;
//   					Blank(1);
//   					SetCursor(0, 6, 5);
//   					Print("      CANCLED     ");
//   					HAL_Delay(1000);
//   				}
//   				else
//   					Conversition(a_max);
//   				Menu=0;
//   			}
//   		}
//		else if(Button_Down_Result || Menu==3)
//		{
//			while(Button_Down_Result);
//			if(test!=0)
//			{
//				Clear();
//				uint8_t option=1;
//				Result();
//				Move(option,"USB","NEW","PRINT");
//				while(!(Button_Menu_Esc) && option!=0)
//				{
//					if(Button_Move)
//					{
//						option++;
//						if(option==4)
//							option=1;
//						Move(option,"USB","NEW","PRINT");
//					}
//					while(Button_Move);
//					if(Button_Test_Enter)
//					{
//						while(Button_Test_Enter);
//						if(option==1)
//						{
//							Clear();
//							Pendrive_Init();
//							File();
//							SetCursor(0, 5, 30);
//							Print("File Writing");
////							File_Open("/DATA_000.CSV", 0x14);
//							File_Write("\r");
//							File_Write(name);
//							File_Write("\r\n");
//							File_Write("LOT NO : ,");
//							File_Write(Lot);
//							File_Write("\r\n");
//							File_Write("TEST-#,,,mic(ug/inch)\r\n");
//
//							float add=0;
//							for(char print=1;print<=test;print++)
//							{
//
//									if(print<10)
//										Number(print,0x20);
//									else
//										File_Write("10");
//									File_Write(",,,");
//									Number(mic_value[print-1], 0x23);
//									add+=mic_value[print-1];
//									File_Write("\r");
//								}
//								add=add/(float)test;
//								File_Write("\r");
//								File_Write(" AVERAGE,,,");
//								Number(add,0x23);
//								File_Write("\r");
//								File_Write("\r\n\n\n");
//
//							close(File_Update);
//							dummy_file();
//							SetCursor(0, 5, 30);
//							Print(" File Close ");
//						}
//						else if(option ==2)
//							test=option=0;
//						else if(option ==3)
//							printer();
//						option=0;
//					}
//				}
//				Clear();
//				Test_Mode();
//				Blank(1);
//				Menu=0;
//			}
//		}
//		else if(Button_UP_Delete || Menu==4)
//			Delete();
//		while(Button_UP_Delete);
//	}
////	else
////		Blink("    LOW BATTRY    ");
//
//}
//void Delete()
//{
//	Menu=0;
//	if(test!=0)
//		test--;
//	SetCursor(0, 6, 5);
//	Print("    Deleting...   ");
//	HAL_Delay(5);
//	SetCursor(0, 6, 30);
//	Print("           ");
//	HAL_Delay(5);
//	Blank(1);
//
//}
//void Blank(char init)
//{
//	SetCursor(0, 4, 30);
//	if(test<10)
//	{
//		Print("0");
//		Number(test, 0);
//	}
//	else
//		Print("10");
//	Print(":");
//
//	SetCursor(0, 4, 52);
//
//	if(init==0||test==0)
//		Print("    ");
//	else
//		Number(mic_value[test-1],2);
//	Print(" ug/inch");
//}
//void Test_Mode()
//{
//	SetCursor(0, 0, 0);
//	Print(name);
//	SetCursor(0, 2, 0);
//	Print("LOT NO :");
//	SetCursor(0, 2, 52);
//	Print(Lot);
//	SetCursor(0, 4, 0);
//	Print("TEST-");
//}
//
//void Mic_conversition(float mic,int Volt,int min,float multiplier)
//{
//	float find =(((float)(Volt - min)) * multiplier);
//	mic_value[test-1]=mic-=((int)find/(float)10.0);
//	Blank(1);
//	SetCursor(0, 6, 5);
//	Print("        OK        ");
//	HAL_Delay(1000);
//}
//
//void Conversition(short int Volt)
//{
//
//	if(Volt <= 810 && Volt >=766)
//		Mic_conversition(2.6, Volt, 766, 0.159);
//
//	else if(Volt <= 765 && Volt >=708)
//		Mic_conversition(3.5, Volt, 708, 0.158);
//
//	else if(Volt <=707  && Volt >=618)
//		Mic_conversition(5.0, Volt, 618, 0.169);
//
//	else if(Volt <= 617 && Volt >=588)
//		Mic_conversition(5.6, Volt, 588, 0.207);
//
//	else if(Volt <= 587 && Volt >=547)
//		Mic_conversition(6.5, Volt, 547, 0.225);
//
//	else
//	{
//		SetCursor(0, 6, 5);
//		Print("     REJECTED     ");
//		test--;
//		Blank(1);
//		HAL_Delay(1000);
//	}
//}



//#include "LCD_Header.h"
//#include "Printer_Header.h"
//char lcd_count=0,axis,Lot[9]="        ",name[21],invert=0,pos=0,Menu=0;
//short int test=10;
//float volt_a=0;//,v_max=0;
//int max_a=0;
//float mic_value[10]={1.22,1.23,1.21,1.26,1.29,1.20,1.2,1.23,1,1.23};
//const char s_letter[] =
//{
//    0x00, 0x20, 0x54, 0x54, 0x78, 0x40,      // Code for char a
//	0x00, 0x7F, 0x28, 0x44, 0x44, 0x38,      // Code for char b
//	0x00, 0x38, 0x44, 0x44, 0x44, 0x28,      // Code for char c
//	0x00, 0x38, 0x44, 0x44, 0x28, 0x7F,      // Code for char d
//	0x00, 0x38, 0x54, 0x54, 0x54, 0x18,      // Code for char e
//	0x00, 0x00, 0x08, 0x7E, 0x09, 0x02,      // Code for char f
//	0x00, 0x18, 0xA4, 0xA4, 0x9C, 0x78,      // Code for char g
//	0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,      // Code for char h
//	0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,      // Code for char i
//	0x00, 0x20, 0x40, 0x40, 0x3D, 0x00,      // Code for char j
//	0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,      // Code for char k
//	0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,      // Code for char l
//	0x00, 0x7C, 0x04, 0x78, 0x04, 0x78,      // Code for char m
//	0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,      // Code for char n
//	0x00, 0x38, 0x44, 0x44, 0x44, 0x38,      // Code for char o
//	0x00, 0xFC, 0x18, 0x24, 0x24, 0x18,      // Code for char p
//	0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,      // Code for char q
//	0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,      // Code for char r
//	0x00, 0x48, 0x54, 0x54, 0x54, 0x24,      // Code for char s
//	0x00, 0x04, 0x04, 0x3F, 0x44, 0x24,      // Code for char t
//	0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,      // Code for char u
//	0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,      // Code for char v
//	0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,      // Code for char w
//	0x00, 0x44, 0x28, 0x10, 0x28, 0x44,      // Code for char x
//	0x00, 0x4C, 0x90, 0x90, 0x90, 0x7C,      // Code for char y
//	0x00, 0x44, 0x64, 0x54, 0x4C, 0x44       // Code for char z
//};
//
//const char c_letter[] =
//{
//   	0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E,      // Code for char A
//	0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,      // Code for char B
//	0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,      // Code for char C
//	0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E,      // Code for char D
//	0x00, 0x7F, 0x49, 0x49, 0x49, 0x49,      // Code for char E
//	0x00, 0x7F, 0x09, 0x09, 0x09, 0x09,      // Code for char F
//	0x00, 0x3E, 0x41, 0x41, 0x51, 0x73,      // Code for char G
//	0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,      // Code for char H
//	0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,      // Code for char I
//	0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,      // Code for char J
//	0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,      // Code for char K
//	0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,      // Code for char L
//	0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,      // Code for char M
//	0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,      // Code for char N
//	0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,      // Code for char O
//	0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,      // Code for char P
//	0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,      // Code for char Q
//	0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,      // Code for char R
//	0x00, 0x26, 0x49, 0x49, 0x49, 0x32,      // Code for char S
//	0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,      // Code for char T
//	0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,      // Code for char U
//	0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,      // Code for char V
//	0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,      // Code for char W
//	0x00, 0x63, 0x14, 0x08, 0x14, 0x63,      // Code for char X
//	0x00, 0x03, 0x04, 0x78, 0x04, 0x03,      // Code for char Y
//	0x00, 0x61, 0x51, 0x49, 0x45, 0x43       // Code for char Z
//};
//
//const char number[] =
//{
//	0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,      // Code for char 0
//	0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,      // Code for char 1
//	0x00, 0x72, 0x49, 0x49, 0x49, 0x46,      // Code for char 2
//	0x00, 0x21, 0x41, 0x49, 0x4D, 0x33,      // Code for char 3
//	0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,      // Code for char 4
//	0x00, 0x27, 0x45, 0x45, 0x45, 0x39,      // Code for char 5
//	0x00, 0x3C, 0x4A, 0x49, 0x49, 0x31,      // Code for char 6
//	0x00, 0x41, 0x21, 0x11, 0x09, 0x07,      // Code for char 7
//	0x00, 0x36, 0x49, 0x49, 0x49, 0x36,      // Code for char 8
//	0x00, 0x06, 0x49, 0x49, 0x49, 0x3E       // Code for char 9
//};
//
//const char Symbol[] =
//{
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
//		0x00, 0x80, 0x40, 0x20, 0x10, 0x08,
//		0x00, 0x10, 0x10, 0x10, 0x10, 0x00
//};
//
//void Glcd(char rs,char data)
//{
//	if(rs==1)
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15,GPIO_PIN_SET);
//	if(rs==0)
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15,GPIO_PIN_RESET);
//
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (data & 0x01));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (data & 0x02));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (data & 0x04));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (data & 0x08));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (data & 0x10));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (data & 0x20));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (data & 0x40));
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (data & 0x80));
//
//
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);
//	HAL_Delay(1);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);
//	HAL_Delay(1);
//}
//
//void LCD_Init(void)
//{
//	Glcd(0, 0x3F);
//}
//
//void Clear(void)
//{
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1);
//	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1);
//	for(char row=0;row<8;row++)
//	{
//		Glcd(0,0xB8+row);
//		Glcd(0, 0x40);
//		char s1=64;
//		while(s1--)
//			Glcd(1, 0x00);
//	}
//}
//
//void SetCursor(char sector,char x_axis,char y_axis)
//{
//	if(sector==0)
//	{
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
//	}
//	if(sector==1)
//	{
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
//	}
//	Glcd(0, x_axis+0xB8);
//	Glcd(0, y_axis+0x40);
//	lcd_count=y_axis;
//	axis=x_axis;
//}
//
//void loop(const char *data)
//{
//	for(short int loop = 0; loop < 6; loop++)
//	{
//		if(lcd_count==64)
//		{
//			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
//			Glcd(0,0xB8+axis);
//			Glcd(0,0x40);
//		}
//		if(lcd_count==128)
//			lcd_count=0;
//		if(invert==0)
//			Glcd(1, (*(data+loop)));
//		else
//			Glcd(1, ~(*(data+loop)));
//		lcd_count++;
//		if(Button_Menu_Esc)
//			Menu=1;
//		else if(Button_Test_Enter)
//			Menu=2;
//		else if(Button_Down_Result)
//			Menu=3;
//		else if(Button_Down_Result)
//			Menu=4;
//	}
//
//}
//
//void Print(const char *data)
//{
//	while(*data)
//		{
//
//			if(*data >= 'A' && *data <= 'Z')
//				loop( &c_letter[(*data - 'A')*6]);
//
//			else if(*data >= 'a' && *data <= 'z')
//				loop( &s_letter[(*data - 'a')*6]);
//
//			else if(*data >= '0' && *data <= '9')
//				loop( &number[(*data - '0')*6]);
//
//			else if(*data == ' ')
//				loop( &Symbol[0]);
//
//			else if(*data == '.')
//				loop( &Symbol[1*6]);
//
//			else if(*data == ':')
//				loop( &Symbol[2*6]);
//
//			else if(*data == '/')
//				loop( &Symbol[3*6]);
//
//			else if(*data == '-')
//				loop( &Symbol[4*6]);
//
//			data++;
//		}
//}
//
//int Power(char times)
//{
//	int value=1;
//	while(times--)
//		value*=10;
//	return value;
//}
//
//void Number(float value,char point)
//{
//	int data=0,tens=1;
//	char digit=0,index=0,temp=point,c_value[10];
//
//	data = (int)value;
//	while(data >= tens)
//		{
//			digit++;
//			tens*=10;
//		}
//	tens=1;
//
//	for(;digit>=2;digit--)
//	{
//		tens=Power(digit-1);
//		c_value[index++] = ((data/tens) + 48);
//		data%=tens;
//	}
//	c_value[index++] = ((data%10) + 48);
//
//	if(point & 15)
//	{
//		c_value[index++]='.';
//		point&=~(16);
//		while(point--)
//			{
//				data=(int)value;
//				value=value-(float)data;
//				value=(value*(float)10.0);
//				c_value[index++]=(48+(int)value);
//			}
//	}
//	c_value[index] = '\0';
//	if((temp & 0xf0)==16)
//		string(c_value);
//	else
//		Print(c_value);
//}
//
//void Move(char move,char str1[],char str2[])
//{
//	if((move&1)==0)
//	{
//		invert=1;
//		SetCursor(0, 7, 0);
//		Print(str1);
//		invert=0;
//		SetCursor(1, 7, 64-(strlen(str2)*6));
//		Print(str2);
//	}
//	else if((move&1)==1)
//	{
//		SetCursor(0, 7, 0);
//		Print(str1);
//		invert=1;
//		SetCursor(1, 7, 64-(strlen(str2)*6));
//		Print(str2);
//		invert=0;
//	}
//}
//
//void lot(void)
//{
//	char count=0,value=48;
//	SetCursor(0, 2, 52);
//	Print("        ");
//	SetCursor(0, 2, 52+(pos*6));
//	Print("0");
//	SetCursor(0, 6, 5);
//	Print("    ENTER  LOT    ");
//	while(1)
//	{
//		if(Button_Move)
//		{
//			while(Button_Move);
//			pos++;
//
//			if(pos==8)
//				pos=0;
//			if(pos<2)
//				SetCursor(0, 2, 52+(pos*6));
//			else
//				SetCursor(1, 2, 0+((pos-2)*6));
//			Print("0");
//			Lot[pos]=0;
//			count=0;
//			value=48;
//		}
//		if(Button_UP_Delete)
//		{
//			while(Button_UP_Delete);
//
//			if(pos<2)
//				SetCursor(0, 2, 52+(pos*6));
//			else
//				SetCursor(1, 2, 0+((pos-2)*6));
//
//			if(count==37)
//				count=0;
//
//			count++;
//			if(count<10)
//				loop(&number[count*6]);
//			else if(count>9 && count < 37)
//				loop(&c_letter[(count-10)*6]);
//
//			if(value==57)
//				value=64;
//			else if(value==90)
//				value=47;
//			value++;
//		}
//
//		if(Button_Down_Result)
//		{
//			while(Button_Down_Result);
//
//			if(pos<2)
//				SetCursor(0, 2, 52+(pos*6));
//			else
//				SetCursor(1, 2, 0+((pos-2)*6));
//
//			if(count==0)
//				count=36;
//
//			count--;
//			if(count>9 && count < 37)
//				loop(&c_letter[(count-10)*6]);
//			else if(count<10)
//				loop(&number[count*6]);
//			if(value==48)
//				value=91;
//			else if(value==65)
//				value=58;
//			value--;
//		}
//		Lot[pos]=value;
//		if(Button_Test_Enter)
//		{
//			Lot[pos+1]='\0';
//			pos=0;
//			break;
//		}
//		if(Button_Menu_Esc)
//		{
//			Lot[0]='\0';
//			break;
//		}
//
//	}
//}
//void Name()
//{
//	char count=0,value=32,len=strlen(name);
//	SetCursor(0, 0, 0);
//	Print("                     ");
//	pos=0;
//	SetCursor(0, 6, 5);
//	Print("    ENTER  NAME   ");
//	while(1)
//	{
//		if(Button_Move)
//		{
//			while(Button_Move);
//
//			if(pos==20)
//				pos=0;
//			if(pos<11)
//				SetCursor(0, 0, (pos*6));
//			else
//				SetCursor(1, 0, ((pos-11)*6)+2);
//
//			Lot[pos++]=32;
//			count=0;
//			value=32;
//		}
//		if(Button_UP_Delete)
//		{
//			while(Button_UP_Delete);
//
//			if(pos<11)
//				SetCursor(0, 0, (pos*6));
//			else
//				SetCursor(1, 0, ((pos-11)*6)+2);
//
//			if(count==26)
//				count=-1;
//
//			count++;
//			if(count==0)
//				loop(&Symbol[0]);
//			else if(count>0 && count <= 26)
//				loop(&c_letter[(count-1)*6]);
//
//			value++;
//			if(value==33)
//				value=65;
//			else if(value==91)
//				value=32;
//		}
//
//		if(Button_Down_Result)
//		{
//			while(Button_Down_Result);
//
//			if(pos<11)
//				SetCursor(0, 0, (pos*6));
//			else
//				SetCursor(1, 0, ((pos-11)*6)+2);
//
//			if(count==0)
//				count=27;
//
//			count--;
//			if(count>0 && count < 27)
//				loop(&c_letter[(count-1)*6]);
//			else if(count==0)
//				loop(&Symbol[0]);
//
//			value--;
//			if(value==31)
//				value=90;
//			else if(value==64)
//				value=32;
//		}
//		name[pos]=value;
//		if(Button_Test_Enter)
//		{
//			// EEPROM write
//			name[pos+1]='\0';
//			HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0x00, 1, name, strlen(name), 1000);
//			pos=0;
//			break;
//		}
//		if(Button_Menu_Esc)
//		{
//			if(pos>len)
//				name[pos+1]='\0';
//			HAL_I2C_Mem_Read(&hi2c1, 0xA1, 0x00, 1, &name, strlen(name), 1000);
//			break;
//		}
//
//	}
//}
//
//
//void Blink(char *char_set)
//{
//	SetCursor(0, 6, 5);
//	if(!(Button_Menu_Esc ||Button_Test_Enter || Menu))
//	{
//		Print(char_set);
//		HAL_Delay(5);
//		if(Menu==0)
//		{
//		SetCursor(0, 6, 5);
//		Print("                  ");
//		HAL_Delay(5);
//		}
//	}
//	if(Button_Menu_Esc)
//		Menu=1;
//}
//
//void Result()
//{
//	float add=0;
//	SetCursor(0, 0, 0);
//	Print("ug/in");
//	SetCursor(1, 0, 0);
//	Print("ug/in");
//	for(short int i=0;i<test;i++)
//	{
//		if(test<5)
//			SetCursor(0, i+1, 0);
//		else
//			SetCursor(1, i+1, 0);
//
//		if(test<9)
//		{
//			Print(" ");
//			Number(i+1, 0);
//		}
//		else
//			Print("10");
//		Print("-");
//		Number(mic_value[i],2);
//		add+=mic_value[i];
//	}
//	SetCursor(0, 6, 0);
//	Print("AVERAGE : ");
//	Number((add/(float)test),2);
//	Print("ug/inch");
//}
//void printer()
//{
//	Heading(1);
//	string(" AIS Digi mic smart - 12 \r\n");
//	Heading(0);
//	string(name);
//	string("\r");
//	string(" LOT NO : ");
//	string(Lot);
//	string("\r\n");
//	string(" TEST-#    mic(ug/inch)\r\n");
//	float add=0;
//	for(char print=1;print<=10;print++)
//	{
//		string("  ");
//		if(print<10)
//		{
//			string(" ");
//			Number(print,16);
//		}
//		else
//			string("10");
//		string("          ");
//		Number(mic_value[print-1], 18);
//		add+=mic_value[print-1];
//		string("\r");
//	}
//	add=add/(float)test;
//	Heading(1);
//	string(" ---------------------- \r");
//	string(" AVERAGE   ");
//	Number(add,18);
//	string("\r");
//	string(" ----------------------- \r\n\n\n");
//
//}
//void start_up()
//{
//	if(test<10)
//		Blink("READY FOR THE TEST");
//	else
//		Blink("  TEST COMPLETED  ");
//
//
//	if(Button_Menu_Esc || Menu==1)
//	{
//		char move=2;Menu=0;
//		SetCursor(0, 6, 5);
//		Print("  CHOOSE  OPTION  ");
//		Move(move,"NAME","LOT");
//		while(Button_Menu_Esc);
//		while((!Button_Menu_Esc) && (move & 2))
//		{
//			if(Button_Move)
//			{
//				move^=1<<0;
//				Move(move,"NAME","LOT");
//			}
//			while(Button_Move);
//			if(Button_Test_Enter)
//			{
//				while(Button_Test_Enter);
//				if((move & 1)==0)
//					Name();
//				else if((move & 1)==1)
//					lot();
//				move=0;
//			}
//		}
//		Clear();
//		Test_Mode();
//		Blank(0);
//	}
//
//	else if(Button_Test_Enter || Menu==2)
//	{
//		while(Button_Test_Enter);
//		if(test<10)
//		{
//			test++;
//			SetCursor(0, 6, 5);
//			Print("   PROCESSING...  ");
//			Blank(0);
//			//conversation to the voltage goes 0.5v while pressing the Button_Menu_Esc the conversition will stop
//			int value=1,limit=400,max_a=0;
//			volt_a=500;
//			HAL_ADCEx_Calibration_Start(&hadc1);
//			while(((int)(volt_a*1000.0)>limit) && Menu!=1)
//			{
//				SetCursor(1, 6, 21);
//				Print("   ");
//				HAL_Delay(1);
//
//				HAL_ADC_Start(&hadc1);
//				for(int i=0;i<1000;i++)
//				{
//				  HAL_ADC_PollForConversion(&hadc1, 1);
//				  value+=HAL_ADC_GetValue(&hadc1);
////				  if(Button_Menu_Esc)
////					  Menu=1;
//				}
//				value=value/1000;
//				volt_a=(float)value*0.00080586;
//
//
////				if((int)(v_max*1000.0)<(int)(volt_a*1000.0))
////					v_max=volt_a;
//
//				if(max_a<value)
//					max_a=value;
//
//				if((int)(volt_a*1000.0)>600)
//				  limit=770;
//
//				SetCursor(1, 6, 21);
//				Print("...");
//				HAL_Delay(1);
//			  }
//
//			if(Menu==1)
//			{
//				if(test!=0)
//					test--;
//				Blank(0);
//				SetCursor(0, 6, 5);
//				Blink("     CANCLED     ");
//				HAL_Delay(1000);
//			}
//			else
//				Conversition(max_a);
//			Menu=0;
//		}
//	}
//	else if(Button_Down_Result || Menu==3)
//	{
//		Menu=0;
//		while(Button_Down_Result);
//		if(test!=0)
//		{
//			Clear();
//			char  move=2;
//			Result();
//			Move(move,"NEW","PRINT");
//			while(!(Button_Menu_Esc) && (move&2))
//			{
//				if(Button_Move)
//				{
//					move^=1<<0;
//					Move(move,"NEW","PRINT");
//				}
//				while(Button_Move);
//				if(Button_Test_Enter)
//				{
//					while(Button_Test_Enter);
//					if((move & 1)==0)
//						move=test=0;
//					else if((move & 1)==1)
//						printer();
//				}
//			}
//			Clear();
//			Test_Mode();
//			Blank(1);
//		}
//	}
//	else if(Button_UP_Delete)
//		Delete();
//	while(Button_UP_Delete);
//
//}
//void Delete()
//{
//
//	if(test!=0)
//		test--;
//	SetCursor(0, 6, 30);
//	Print("Deleting...");
//	HAL_Delay(5);
//	SetCursor(0, 6, 30);
//	Print("           ");
//	HAL_Delay(5);
//	Blank(1);
//
//}
//void Blank(char init)
//{
//	SetCursor(0, 4, 30);
//	if(test<10)
//	{
//		Print("0");
//		Number(test, 0);
//	}
//	else
//		Print("10");
//	Print(":");
//
//	SetCursor(0, 4, 52);
//
//	if(init==0||test==0)
//		Print("    ");
//	else
//		Number(mic_value[test-1],2);
//	Print(" ug/inch");
//}
//void Test_Mode()
//{
//	SetCursor(0, 0, 0);
//	Print(name);
//	SetCursor(0, 2, 0);
//	Print("LOT NO :");
//	SetCursor(0, 2, 52);
//	Print(Lot);
//	SetCursor(0, 4, 0);
//	Print("TEST-");
//}
//
//void Mic_conversition(float mic,int Volt,int min,float multiplier)
//{
//	float find =(((float)(Volt - min)) * multiplier);
//	mic_value[test-1]=mic-=((int)find/(float)10.0);
//	Blank(1);
//	SetCursor(0, 6, 5);
//	Print("       OK         ");
//	HAL_Delay(1000);
//}
//
//void Conversition(int value)
//{
//	int Volt=(int)(((float)value*0.00080586)*1000.0);
//
//
//	if(Volt <= 1620 && Volt >=1532)
//		Mic_conversition(2.6, Volt, 1532, 0.0714);
//
//	else if(Volt <= 1531 && Volt >=1415)
//		Mic_conversition(3.5, Volt, 1415, 0.0775);
//
//	else if(Volt <=1414  && Volt >=1235)
//		Mic_conversition(5.0, Volt, 1235, 0.0838);
//
//	else if(Volt <= 1234 && Volt >=1175)
//		Mic_conversition(5.6, Volt, 1175, 0.1017);
//
//	else if(Volt <= 1174 && Volt >=1093)
//		Mic_conversition(6.5, Volt, 1093, 0.1111);
//
//	else
//	{
//		SetCursor(0, 6, 5);
//		Print("     REJECTED     ");
//		test--;
//		Blank(1);
//		HAL_Delay(1000);
//	}
//}
