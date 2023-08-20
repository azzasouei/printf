#include "main.h"
/*** PRINTING AN UNSIGNED NUM ***/
/**
 * print_unsigned - prints unsigned num
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of characters
 */
int print_unsigned(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*** PRINTING AN UNSIGNED NUM IN OCTAL ***/
/**
 * print_octal - prints unsigned num in octal
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specifier
 * @size: size specifier
 * Return: num of characters
 */
int print_octal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}
/*** PRINTING AN UNSIGNED NUM IN HEXADECIMAL ***/
/**
 * print_hexa - prints an unsigned num in hexadecimal
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_hexa(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/*** PRINTING AN UNSIGNED NUM IN UPPER HEXADECIMAL ***/
/**
 * print_hexa_upper - prints an unsigned num in upper hexadecimal
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_hexa_upper(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa_upper(args, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/*** PRINTING A HEX NUM IN UPPER OR LOWER ***/
/**
 * print_hex - prints a hexadecimal num in upper or lower
 * @args: list of args
 * @arr_of: array of values to map num to
 * @buffer: buffer array
 * @flags: calculates active flags
 * @flag_char: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specification
 * @size: size specifier
 * Return: num of characters
 */
int print_hex(va_list args, char arr_of[], char buffer[],
		int flags, char flag_char, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = arr_of[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_char;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}
