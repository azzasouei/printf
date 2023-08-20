#include"main.h"

/**
 * handle_print -  prints an args based on its type
 * @format: Formatted string in which to print the arguments
 * @args:List of arguments to be printed
 * @index: index
 * @buff: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width
 * @precision:precision
 * @size: size specifier
 */
int handle_print(const char *format, int *index, va_list args, char buff[], int flags, int width, int precision, int size)
{
	int i, un_len = 0, p_chars = -1;
	format_t format_args[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_per}, {'i', print_int}, {'d', print_int}, {'b', print_bin}, {'u', print_unsig}, {'o', print_oct}, {'x', print_hexa}, {'X', print_hex_upper}, {'p', print_pointer}, {'S', print_non_printable}, {'r', print_rev}, {'R', print_rot13}, {'\0', NULL}
	}
	for (i = 0; format_args[i].format !='\0'; i++)
		if(format[*ind] == format_args[i].format)
			return (formatt_args[i].fn(args, buff, flags, width, precision, size)
					if (format_args[i].format =='\0')
					{
					if(format[*ind] =='\0')
					return (-1);
					unknow_len += write(1, "%%", 1);
					if(format[*ind - 1] ==' ')
					unknow_len += write(1, " ", 1);
					else if (width)
					{
					--(*ind);
					while (format[*ind] !=' '&& format[*ind] !='%')
					--(*ind);
					if(format[*ind] ==' ')
					--(*ind);
					return (1);
					}
unknow_len += write(1, &format[*ind], 1);
return (unknow_len);
}
return (p_chars);
			}
