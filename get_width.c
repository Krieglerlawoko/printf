#include "main.h"

/**
 * get_width - Width for printing calculator
 * @format: String formated in which to print the arguments.
 * @i: Arguments to be printed list.
 * @list: Arguments list.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int c_i;
	int wdth = 0;

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		if (is_digit(format[c_i]))
		{
			wdth *= 10;
			wdth += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			wdth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;

	return (wdth);
}
