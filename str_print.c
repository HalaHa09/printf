#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * string_sub_print - print for % and c
 * @str2: identifier
 * @arg: argument passed in function
 * Return: numb of printing
 */
int string_sub_print(char str2, va_list arg)
{
	int num = 0;

	if (str2 == '%')
	{
		_putchar('%');
		num++;
	}
	else if (str2 == 'c')
	{
		_putchar(va_arg(arg, int));
		num++;
	}
	return (num);
}

/**
 * rev_str - printing a string in reverse
 * @s: the string as input in a function
 * Return: num of printing
 */
int rev_str(char *s)
{
	int num = 0;

	if (s[0] == '\0')
		return (num);
	if (s[1] != '\0')
		num += rev_str(s + 1);
	_putchar(s[0]);
	num++;
	return (num);
}

/**
 * rot_str - the rot 13'ed string
 * @s :string to have the operation on
 * Return: num of printing
 */
int rot_str(char *s)
{
	int num = 0;

	if (s[0] == '\0')
		return (num);
	if ((s[0] < 'n' && s[0] >= 'a') || (s[0] < 'N' && s[0] >= 'A'))
		_putchar(s[0] + 13);
	else if ((s[0] > 'm' && s[0] <= 'z') || (s[0] > 'M' && s[0] <= 'Z'))
		_putchar(s[0] - 13);
	else
		_putchar(s[0]);
	if (s[1] != '\0')
		num += rot_str(s + 1);
	num++;
	return (num);
}

/**
 * spec_str - printing the haxadecimal value instead of non printed characters
 *
 * @str2: specifier
 * @ss: string to print passed as argument in _printf
 *
 * Return: num of printing
 */
int spec_sttr(char str2, char *ss)
{
	int num = 0;

	while (ss[0] != '\0')
	{
		if (str2 != 'S' || (ss[0] == 0 || (ss[0] > 31 && ss[0] < 127)))
		{
			_putchar(ss[0]);
			ss++;
			num++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			if (ss[0] < 15)
			{
				_putchar('0');
				num++;
			}
			num += hex_calc_upp(ss[0]);
			ss++;
			num += 2;
		}
	}
	return (num);
}

/**
 * string_printing - printing the types of strings
 * @str2: the character to choose which print it is
 * @arg: the arg passed on
 * Return: numb of printing
 */
int string_printing(char str2, va_list arg)
{
	int num = 0;
	char *ss;

	if (str2 == '%' || str2 == 'c')
		num += string_sub_print(str2, arg);
	else if (str2 == 's' || str2 == 'S' || str2 == 'r' || str2 == 'R')
	{
		ss = va_arg(arg, char *);
		if (ss == NULL)
			ss = "(null)";
		if (str2 == 'r')
			num += rev_str(ss);
		else if (str2 == 'R')
			num += rot_str(ss);
		else
		{
			num += spec_sttr(str2, ss);
		}
	}
	return (num);
}
