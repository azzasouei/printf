#include "main.h"
/*** CHAR PRINTING ***/
/**
 * print_char - prints character
 * @args: list of args
 * @buffer: buffer array to handle print
 * @flags:calculates active flags
 * @width:the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_char(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*** STRING PRINTING ***/
/**
 * print_string - prints string
 * @args: list of args
 * @buffer: buffer array to handle print
 * @flags:calculates active flags
 * @width:the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_string(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/*** PERCENT SIGN PRINTING ***/
/**
 * print_per - prints percent sign
 * @args: list of args
 * @buffer: buffer array to handle print
 * @flags:calculates active flags
 * @width:the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_per(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/*** INTEGER PRINTING ***/
/**
 * print_int - printsan integer
 * @args: list of args
 * @buffer: buffer array to handle print
 * @flags:calculates active flags
 * @width:the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_int(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_numbers(is_neg, i, flags, width, precision, size));
}
/*** BINARY PRINTING ***/
/**
 * print_binary - prints unsigned num
 * @args: list of args
 * @buffer: buffer array to handle print
 * @flags:calculates active flags
 * @width:the width
 * @precision: precision specification
 * @size: size specifier
 * Return: num of characters
 */
int print_binary(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int counter;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, counter = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}
