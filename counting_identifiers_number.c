#include<stdlib.h>

/**
 * countting - counting the identifiers numbers
 *
 * @format: string to count from
 *
 * Return: the result
 */
int countting(const char *format)
{
	int res = 0, i, j, end;
	const char *str;
	char ident[] = {'c', 's', 'd', '%', 'i', 'b', 'u',
		'o', 'x', 'X', 'S', 'p', 'r', 'R'};

	str = format;
	for (i = 0; str[i] != '\0'; i++)
	{
		end = 0;
		if (str[i] == '%')
		{
			for (j = 0; j < 14 && end == 0; j++)
			{
				if (str[i + 1] == ident[j])
				{
					res++;
					i++;
					end++;
				}
			}
		}
	}
	return (res);
}
