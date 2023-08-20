#include"main.h"

/**
 * width - Calculates the width for printing
 * @format: Formatted string in which to print the args
 * @i: list of args to be printed
 * @args: list of args
 *
 * return:width
 */
int width(const char *format, int *i, va_list args)
{
	int current_i;
	int width = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			width *= 10;
			width += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*i = current_i - 1;
	return (width);
}
