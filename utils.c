#include "main.h"

/**
 * is_printable - Char evaluated if printable
 * @c: Evaluated Char.
 *
 * Return: If c is printable 1 else 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Ascci in hexadecimal code to buffer apended
 * @buffer: Chars array.
 * @i: Starting index to appending.
 * @ascii_code: ASSCI CODE.
 * Return: 3 always
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_t[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_t[ascii_code / 16];
	buffer[i] = map_t[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Char is verified if digit
 * @c: Evaluated char
 *
 * Return: If c is a digit 1 else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Number cast to specified size
 * @num: Number to be cast.
 * @size: Number indicating type to be cast.
 *
 * Return: Value cast of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Number cast to specified size
 * @num: Number casted
 * @size: Number indicating type to cast
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
