#include "main.h"
/*** PRINTING A POINTER ***/
/**
 * print_pointer - prints value of a pointer var
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_pointer(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char arr_of[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = arr_of[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;
	index++;
	return (print_pointer(buffer, index, len,
				width, flags, padd, extra_c, padd_start));
}
/*** PRINTING NON PRINTABLE ***/
/**
 * print_non_printable - prints ascii codes in hexa of non printable chars
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_non_printable(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hex_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/*** PRINTING REVERSE STRING ***/
/**
 * print_rev - prints reverse string
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_rev(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		for (i = i - 1; i >= 0; i--)
		{
			char z = str[i];

			write(1, &z, 1);
			counter++;
		}
	return (counter);
}
/*** PRINTING A STRING IN ROT 13 ***/
/**
 * print_rot13 - prints string in rot 13
 * @args: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_rot13(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				counter++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			counter++;
		}
	}
	return (counter);
}
