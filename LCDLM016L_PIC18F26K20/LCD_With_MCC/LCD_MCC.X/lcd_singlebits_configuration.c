#include "lcd_singlebits_configuration.h"
#include <xc.h>
#include "mcc_generated_files/mcc.h"

#define	LCD_RS PORTCbits.RC4
#define LCD_EN PORTCbits.RC5

#define LCD_D0 PORTBbits.RB5
#define LCD_D1 PORTBbits.RB4
#define LCD_D2 PORTBbits.RB3
#define LCD_D3 PORTBbits.RB2

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

	__delay_us(20);
    LCD_D0 = lcd_bits.bits.b7;
    LCD_D1 = lcd_bits.bits.b6;
    LCD_D2 = lcd_bits.bits.b5;
    LCD_D3 = lcd_bits.bits.b4;
    LCD_STROBE();
    //__delay_us(20);
    LCD_D0 = lcd_bits.bits.b3;
    LCD_D1 = lcd_bits.bits.b2;
    LCD_D2 = lcd_bits.bits.b1;
    LCD_D3 = lcd_bits.bits.b0;
    LCD_STROBE();

    
}

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
    lcd_write(0x0C);  // Display On, Cursor Off
	//lcd_write(0xF);  // Display On, Cursor On, Cursor Blink
	lcd_clear();	// Clear screen
	lcd_write(0x6); // Set entry Mode
}

void lcd_start(void)
{
    lcd_init();
    lcd_clear();
}


