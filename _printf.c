#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"


/**
 * _printf - the same function as printf but self made
 *
 * @format: a string that have what to print, with identifiers
 *
 * Return: lentgh of the str that will be printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, numb_of_char = 0, j, count = 0;
	const char *str;

	if (format == NULL)
		return (-1);
	len = _strlen(format);
	count = countting(format);
	va_start(args, format);
	str = format;

	len -= count * 2;
	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] != '%')
			_putchar(str[j]);
		if (str[j] == '%')
		{
			numb_of_char = _print_(str[j], str[j + 1], args);
			j++;

			if (numb_of_char == -1)
			{
				j--;
				len = -1;
			}
			else if (numb_of_char > 0)
				len += numb_of_char;
		}

	}
	va_end(args);
	return (len);
}
