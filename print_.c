#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _print_ - printing the argument in va_list
 *
 * @str1: the identifier
 * @str2: the identifier after '%'
 * @arg: arg in _printf
 * Return: number of characters printed
 */
int _print_(char str1, char str2, va_list arg)
{
	int num = 0, i, done = 0;
	char str_chr[] = {'c', 's', '%', 's', 'r', 'R'};
	char numb[] = {'b', 'd', 'i', 'u', 'o'};

	if (str1 == '%')
	{
		for (i = 0; i < 6 && done == 0; i++)
		{
			if (str2 == str_chr[i])
			{
				num += string_printing(str2, arg);
				done++;
			}
		}
		for (i = 0; i < 6 && done == 0; i++)
		{
			if (str2 == numb[i])
			{
				num += integer_print(str2, arg);
				done++;
			}
		}
		if (done == 0 && (str2 == 'x' || str2 == 'X' || str2 == 'p'))
		{
			num += print_hexa(str2, arg);
			done++;
		}
		else if (str2 == '\0' && done == 0)
		{
			num = -1;
			done++;
		}
		else if (done == 0)
		{
			_putchar('%');
			_putchar(str2);
		}
	}
	return (num);
}
