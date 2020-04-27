/*
 *	LCD interface example
 *	Uses routines from delay.c
 *	This code will interface to a standard LCD controller
 *	like the Hitachi HD44780. It uses it in 4 bit mode, with
 *	the hardware connected as follows (the standard 14 pin 
 *	LCD connector is used):
 *	
 *	PORTB bits 0-3 are connected to the LCD data bits 4-7 (high nibble)
 *	PORTC bit 4 is connected to the LCD RS input (register select)
 *	PORTC bit 5 is connected to the LCD EN bit (enable)
 *	
 *	To use these routines, set up the port I/O (TRISA, TRISD) then
 *	call lcd_init(), then other routines as required.
 *	
 */

#ifndef _XTAL_FREQ
 // Unless specified elsewhere, 4MHz system frequency is assumed
 #define _XTAL_FREQ 20000000
#endif

#include	"lcd.h"
#include "system_configuration.h"


#define	LCD_RS RC4
#define LCD_EN RC5

#define LCD_DATA	PORTB

#define	LCD_STROBE()	((LCD_EN = 1),(LCD_EN=0))

typedef union
{
	uint8_t	ch;
	struct
	{
		unsigned	b0:		1;
		unsigned	b1:		1;
		unsigned	b2:		1;
		unsigned	b3:		1;
		unsigned	b4:		1;
		unsigned	b5:		1;
		unsigned	b6:		1;
		unsigned	b7:		1;
	} bits;
} lcdbyte;

lcdbyte lcd_bits;

/* write a byte to the LCD in 4 bit mode */

void
lcd_write(unsigned char c)
{
    lcd_bits.ch=c;

	__delay_us(40);
    RB3 = lcd_bits.bits.b7;
    RB2 = lcd_bits.bits.b6;
    RB1 = lcd_bits.bits.b5;
    RB4 = lcd_bits.bits.b4;
    LCD_STROBE();
    //__delay_us(20);
    RB3 = lcd_bits.bits.b3;
    RB2 = lcd_bits.bits.b2;
    RB1 = lcd_bits.bits.b1;
    RB4 = lcd_bits.bits.b0;
    LCD_STROBE();
  
}

/*
 * 	Clear and home the LCD
 */

void
lcd_clear(void)
{
	LCD_RS = 0;
	lcd_write(0x1);
	__delay_ms(2);
}

/* write a string of chars to the LCD */

void
lcd_puts(const char * s)
{
	LCD_RS = 1;	// write characters
	while(*s)
		lcd_write(*s++);
}

/* write one character to the LCD */

void
lcd_putch(char c)
{
	LCD_RS = 1;	// write characters
	lcd_write( c );
}


/*
 * Go to the specified position
 */

void
lcd_goto(unsigned char pos)
{
	LCD_RS = 0;
	lcd_write(0x80+pos);
}
	
/* initialise the LCD - put into 4 bit mode */
void
lcd_init()
{
	char init_value;

	init_value = 0x3;
	LCD_RS = 0;
	LCD_EN = 0;
	//LCD_RW = 0;
	
	__delay_ms(15);	// wait 15mSec after power applied,
	LCD_DATA	 = init_value;
	LCD_STROBE();
	__delay_ms(5);
	LCD_STROBE();
	__delay_us(200);
	LCD_STROBE();
	__delay_us(200);
	LCD_DATA = 2;	// Four bit mode
	LCD_STROBE();

	lcd_write(0x28); // Set interface length
    lcd_write(0x0E);  // Display On, Cursor Blinking
    //lcd_write(0x0C);  // Display On, Cursor Off
	//lcd_write(0xF);  // Display On, Cursor On, Cursor Blink
	lcd_clear();	// Clear screen
	lcd_write(0x6); // Set entry Mode
}

void lcd_start(void)
{
    lcd_init();
    lcd_clear();
}

void lcd_put_float(float val ,uint8_t lcd_position)
{
    char lcd_float_ans[FLOAT_CASTING_STRING_BUFFER_SIZE];
    lcd_goto(lcd_position);
    lcd_puts(ftoa(val,lcd_float_ans,LEVEL_ACCURECTY_FLOAT_TO_STRING));
    
}


