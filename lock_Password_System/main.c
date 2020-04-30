/*
 * main.c

 *
 *  Created on: Jan 14, 2020
 *      Author: SARA
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"

#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "Keypad_interface.h"
#include <avr/delay.h>

int  main(void)
{
	PortInit();
	CLCD_VoidIntialize();


	//u8 *name="sara";
	//CLCD_voidGOToLocation(2,0);
	//CLCD_voidWriteCmd(Display_control);
	 //CLCD_voidWriteString(name);
	/*CLCD_voidWriteDate('S');
	CLCD_voidWriteDate('A');
	CLCD_voidWriteDate('R');
	CLCD_voidWriteDate('R');*/

	 u8 postion=0;
	 u8 value=0;
	 u8 line =1;
	 u8 pass=1;
	 u8 test=0;
	 //u8 x=0;
	while(1)
	{
		    u8 * paswd = "Enter password: 1";
			u8 *ch="***";
			u8 *correct="correct password,welcome";
			u8 *try_again="Invalid,Try again";
			u8 *invalid="srry,no more try";

		CLCD_voidGOToLocation(1,postion);
		CLCD_voidWriteString(paswd);
		CLCD_voidGOToLocation(2,postion);
		value=KEYPAD_GetPressedKey();

		 /*if(value ==0xff)
				{
					value=0;

				}*/
		 while(value==0xff)
		 {value=KEYPAD_GetPressedKey();
		 }
		 line=2;
		CLCD_voidGOToLocation(line,postion);
		CLCD_voidWriteString(ch);
		_delay_ms(700);

		if (value ==1)
		{

			CLCD_voidWriteCmd(Clear_Display);
			line=1;
			CLCD_voidGOToLocation(line,postion);
			CLCD_voidWriteString(correct);
			_delay_ms(2000);
			test=0;

		}
		else
		{
			line =1;
			CLCD_voidWriteCmd(Clear_Display);
			CLCD_voidGOToLocation(line,postion);
			CLCD_voidWriteString(try_again);
			test++;
			_delay_ms(1000);
			CLCD_voidWriteCmd(Clear_Display);
			CLCD_voidWriteString(paswd);
			_delay_ms(2000);
			//value=KEYPAD_GetPressedKey();
			line=2;
			CLCD_voidGOToLocation(line,postion);
		}
		if(test==3)
		{
			CLCD_voidWriteCmd(Clear_Display);
			line=1;
			CLCD_voidGOToLocation(line,postion);
			CLCD_voidWriteString(invalid);
			//x=1;
			_delay_ms(5000);

		}



		}





}

