#include "main.h"

/**
 * get_size - Size to cast the argument calculator
 * @format: String formated in which to print the arguments
 * @i: Arguments to be printed list.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sz = 0;

	if (format[curr_i] == 'l')
		sz = S_LONG;
	else if (format[curr_i] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sz);
}
