#include<stdarg.h>
#include<stddef.h>
#include"main.h"

/**
 * hex_calc_low - getting hexadecimal number in lower case
 *
 * @n: the number to be converted
 *
 * Return: count for how many prints
 */
int hex_calc_low(unsigned int n)
{
	int count = 0;
	unsigned int a, r;

	a = n / 16;
	if (a != 0)
		count += hex_calc_low(a);
	r = n - (a * 16);
	if (r < 10)
		_putchar('0' + r);
	else
		_putchar('a' + (r % 10));
	count++;
	return (count);
}

/**
 * hex_calc_upp - getting hexadecimal number in upper case
 *
 * @n: the number to be converted
 *
 * Return: count for how many prints
 */

int hex_calc_upp(unsigned int n)
{
	int num = 0;
	unsigned int a, r;

	a = n / 16;
	if (a != 0)
		num += hex_calc_upp(a);
	r = n - (a * 16);
	if (r < 10)
		_putchar('0' + r);
	else
		_putchar('A' + (r % 10));
	num++;
	return (num);
}

/**
 * printing_hexa - printing a haxadicamal number (address of memory)
 *
 * @n: the number to be printed
 *
 * Return: length of the number
 */

int printing_hexa(unsigned long int n)
{
	int num = 0;

	if (n > 15)
		num += printing_hexa(n / 16);
	if ((n % 16) > 9)
		_putchar('a' + (n % 16) - 10);
	else
		_putchar('0' + (n % 16));
	num++;
	return (num);
}

/**
 * transit - function as bridge from print_hexa and printing_hexa
 *
 * @adr: address passed on for p identifier
 *
 * Return: number of prints made
 */

int transit(void *adr)
{
	int num = 0;
	char *ss;
	unsigned long int address;

	ss = "(nil)";
	address = (unsigned long int)adr;
	if (address == 0)
	{
		while (ss[0] != '\0')
		{
			_putchar(ss[0]);
			num++;
			ss++;
		}
	}
	else
	{
		_putchar('0');
		_putchar('x');
		num += 2;
		num += printing_hexa(address);
	}
	return (num);
}

/**
 * print_hexa - printing a number in hexadecimal
 *
 * @str2: char that give the path of each func
 * @arg: argument passed to be printed
 *
 * Return: num as time of printed characters
 */

int print_hexa(char str2, va_list arg)
{
	int num = 0;

	if (str2 == 'x')
		num += hex_calc_low(va_arg(arg, unsigned int));
	else if (str2 == 'X')
		num += hex_calc_upp(va_arg(arg, unsigned int));
	else if (str2 == 'p')
		num += transit(va_arg(arg, void *));
	return (num);
}
