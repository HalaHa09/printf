#include<stdarg.h>
#include "main.h"

/**
 * _print_u_ - prints an unsigned integer
 * @number: the unsigned integer to print
 * Return: count of prints that was made
 */
int _print_u_(unsigned int number)
{
	int count = 0;

	if (number > 9)
		count += _print_u_(number / 10);
	_putchar((number % 10) + '0');
	count++;
	return (count);
}

/**
 * recur_putchar - recursion to print with putchar
 *
 * @value: value in int to print
 *
 * Return: number of characters printed
 */
int recur_putchar(int value)
{
	int numm = 0, k = 0;

	if (value < 0)
	{
		value += 1;
		value = -value;
		_putchar('-');
		numm++;
		k++;
	}
	if (value > 9)
		numm += recur_putchar(value / 10);
	if (k == 1)
		_putchar('0' + ((value % 10) + 1));
	else
		_putchar('0' + (value % 10));
	numm++;
	return (numm);
}
/**
 * recur_binary_put - finding and priting the binary number
 * @n: unsigned integer to be converted to binary
 * Return: num as length of the binary number
 */
int recur_binary_put(unsigned int n)
{
	unsigned int a, r;
	int num = 0;

	a = n / 2;
	if (a != 0)
		num += recur_binary_put(a);
	r = n - (2 * a);
	_putchar('0' + r);
	num++;
	return (num);
}
/**
 * recur_octal_put - printing the octal number
 * @n: unsigned integre to be converted to octal
 * Return: num as length of the octal number
 */
int recur_octal_put(unsigned int n)
{
	unsigned int a, r;
	int num = 0;

	a = n / 8;
	if (a != 0)
		num += recur_octal_put(a);
	r = n - (8 * a);
	_putchar('0' + r);
	num++;
	return (num);
}
/**
 * integer_print - getting here from _print_ for printing integers only
 *
 * @str2: character that define what to print and how
 * @arg: argument passed to be printed
 *
 * Return: count for the characters printed
 */

int integer_print(char str2, va_list arg)
{
	int count = 0;

	if (str2 == 'b')
		count += recur_binary_put(va_arg(arg, unsigned int));
	else if (str2 == 'u')
		count += _print_u_(va_arg(arg, unsigned int));
	else if (str2 == 'o')
		count += recur_octal_put(va_arg(arg, unsigned int));
	else if (str2 == 'i' || str2 == 'd')
		count += recur_putchar(va_arg(arg, int));
	return (count);
}
