/*
 * File:   lcd_string.c
 * Author: zachar.papkov
 *
 * Created on March 24, 2020, 12:52 PM
 */
#include "addtional_string.h"
#include <string.h>
/**
    <p><b>ftoa(....)</b></p>
  
    <p><b>convert float  to string :</b></p>

    <p><b>None:</b></p>

    <p><b>None:</b></p>

    <p><b>value to convert local buffer ,precision:</b></p>

    <p><b>string ( of floating value):</b></p>

    <p><b>Example:</b></p>
    <code>
 * 
 *  char lcd_float_ans[5];
 *  char lcd_float_buff[5];
 * lcd_puts(ftoa(8.25f,lcd_float_ans,2));
 * strcpy(lcd_float_ans,ftoa(4.75f,lcd_float_ans,2) // it is possible put the function into printf or any IO 
 
    </code>

    <p><b>Remarks:</b></p>
 */

static const double rounders[MAX_PRECISION + 1] =
{
	0.5,				// 0
	0.05,				// 1
	0.005,				// 2
	0.0005,				// 3
	0.00005,			// 4
	0.000005,			// 5
	0.0000005,			// 6
	0.00000005,			// 7
	0.000000005,		// 8
	0.0000000005,		// 9
	0.00000000005		// 10
};


char * ftoa(double f, char * buf, int precision)
{
	char * ptr = buf;
	char * p = ptr;
	char * p1;
	char c;
	long intPart;

	// check precision bounds
	if (precision > MAX_PRECISION)
		precision = MAX_PRECISION;

	// sign stuff
	if (f < 0)
	{
		f = -f;
		*ptr++ = '-';
	}

	if (precision < 0)  // negative precision == automatic precision guess
	{
		if (f < 1.0) precision = 6;
		else if (f < 10.0) precision = 5;
		else if (f < 100.0) precision = 4;
		else if (f < 1000.0) precision = 3;
		else if (f < 10000.0) precision = 2;
		else if (f < 100000.0) precision = 1;
		else precision = 0;
	}

	// round value according the precision
	if (precision)
		f += rounders[precision];

	// integer part...
	intPart = f;
	f -= intPart;

	if (!intPart)
		*ptr++ = '0';
	else
	{
		// save start pointer
		p = ptr;

		// convert (reverse order)
		while (intPart)
		{
			*p++ = '0' + intPart % 10;
			intPart /= 10;
		}

		// save end pos
		p1 = p;

		// reverse result
		while (p > ptr)
		{
			c = *--p;
			*p = *ptr;
			*ptr++ = c;
		}

		// restore end pos
		ptr = p1;
	}

	// decimal part
	if (precision)
	{
		// place decimal point
		*ptr++ = '.';

		// convert
		while (precision--)
		{
			f *= 10.0;
			c = f;
			*ptr++ = '0' + c;
			f -= c;
		}
	}

	// terminating zero
	*ptr = 0;

	return buf;
}

void concatenate(char *a, char *b,char*c,char *result)
{
    int size=0;
    size=strlen(a) + strlen(b)+strlen(c)+1;
    strcpy (result, a);
    strcat (result, b);
    strcat (result, c);
    
}

