#include "main.h"

/**
 * print_unsigned - Unsigned number printed
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Active flags calculator
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_octal - Unsigned number in octal notation printed
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Active flags calculator
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies size
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Unsigned number in hexadecimal notation printed
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Active flags calculator
 * @width: Width
 * @precision: Precision specification
 * @size: Specifies size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Unsigned number in upper hexadecimal notation printd
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Active flags calculator
 * @width: width
 * @precision: Precision specification
 * @size: Specifies size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Hexadecimal number in lower or upper printd
 * @types: List of arguments
 * @map_to: Values to map the number to array
 * @buffer: Buffer array to handle print
 * @flags:  Active flags calculator
 * @flag_ch: Active flags calculator
 * @width: Width
 * @precision: Precision specification
 * @size: Specifier size
 * @size: Specification size
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
