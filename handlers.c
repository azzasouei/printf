#include "main.h"

/**
 * write_char -  Prints a string tbadlha write_char - Prints a string
 * @c: char types.
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_char(char c, char buff[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buff's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/**
 * write_num -  Prints a string
 * @is_neg: Lista of arguments
 * @ind: char types.
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_num(int is_neg, int ind, char buff[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buff, flags, width, precision,
		len, padd, extra_ch));
}

/**
 * num - Write a number using a buff
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @len: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int num(int ind, char buff[],
	int flags, int width, int prec,
	int len, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
		buff[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buff */
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & F_MIN) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(flags & F_MIN) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], len));
}

/**
 * unsgnd -  Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int unsgnd(int is_neg, int ind,
	char buff[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < len)
		padd = ' ';

	while (precision > len)
	{
		buff[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MIN))
		padd = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buff[i] = padd;

		buff[i] = '\0';

		if (flags & F_MIN) /* Asign extra char to left of buff [buff>padd]*/
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		}
		else /* Asign extra char to left of padding [padd>buff]*/
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
		}
	}

	return (write(1, &buff[ind], len));
}

/**
 * pointer -  Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int pointer(char buff[], int ind, int len,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buff */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & F_MIN) && padd == ' ')/* extra char to left of buff */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flags & F_MIN) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], len - (1 - padd_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
