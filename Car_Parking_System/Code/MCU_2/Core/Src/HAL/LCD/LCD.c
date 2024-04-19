/* Source file for the LCD driver */

#include "LCD.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{
	/************ Clock Initialization ****************/
	MRCC_vEnableClock(AHB1, RCC_GPIOA_EN);

	/* Configure the direction for RS and E pins as output pins */
	MGPIO_voidSetPinMode(LCD_RS_PORT_ID, LCD_RS_PIN_ID, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(LCD_E_PORT_ID, LCD_E_PIN_ID, _MODE_OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, _MODE_OUTPUT  );

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure 8 pins in the data port as output pins */
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB0_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB1_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB2_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB3_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, _MODE_OUTPUT  );
	MGPIO_voidSetPinMode(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, _MODE_OUTPUT  );

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command)
{
	MGPIO_voidWriteData(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOW);		/* Instruction Mode RS=0 */

	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, HIGH);			/* Enable LCD E=1 */

	_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command,4));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command,5));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command,6));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command,7));
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW); 			/* Disable LCD E=0 */
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, HIGH);			/* Enable LCD E=1 */
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command,0));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command,1));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command,2));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command,3));
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW); 			/* Disable LCD E=0 */
	_delay_ms(1);

#elif(LCD_DATA_BITS_MODE == 8)
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB0_PIN_ID, GET_BIT(command,0));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB1_PIN_ID, GET_BIT(command,1));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB2_PIN_ID, GET_BIT(command,2));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB3_PIN_ID, GET_BIT(command,3));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command,4));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command,5));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command,6));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command,7));
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW); 			/* Disable LCD E=0 */
	_delay_ms(1);
#endif
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data)
{
	MGPIO_voidWriteData(LCD_RS_PORT_ID, LCD_RS_PIN_ID ,HIGH); 		/* Data Mode RS=1 */
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, HIGH); 		/* Enable LCD E=1 */
	_delay_ms(1);

#if(LCD_DATA_BITS_MODE == 4)

	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data,4));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data,5));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data,6));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data,7));
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW); 			/* Disable LCD E=0 */
	_delay_ms(1);
	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, HIGH); 		/* Enable LCD E=1 */
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data,0));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data,1));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data,2));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data,3));
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW); 			/* Disable LCD E=0 */
	_delay_ms(1);

#elif(LCD_DATA_BITS_MODE == 8)
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB0_PIN_ID, GET_BIT(data,0));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB1_PIN_ID, GET_BIT(data,1));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB2_PIN_ID, GET_BIT(data,2));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB3_PIN_ID, GET_BIT(data,3));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data,4));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data,5));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data,6));
	MGPIO_voidWriteData(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data,7));
	_delay_ms(1);

	MGPIO_voidWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, LOW); 			/* Disable LCD E=0 */
	_delay_ms(1);
#endif
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const s8 *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	 *********************************************************/
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row, u8 col)
{
	u8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x10;
		break;
	case 3:
		lcd_memory_address=col+0x50;
		break;
	}					
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const s8 *Str)
{
	LCD_moveCursor(row , col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(s32 data)
{
	s8 buff[16]; /* String to hold the ascii result */
	itoa(data , buff, 10); /* Use itoa C function to convert the data to its corresponding ASCII value*/
	LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}

