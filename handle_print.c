#include"main.h"

/**
 * handle_print: prints an args based on its type
 * @formatt: Formatted string in which to print the arguments
 * @args:List of arguments to be printed
 * @index: index
 * @buff: Buffer array to handle print.
 * @flag: Calculates active flags
 * @width: get width
 * @precision:precision
 * @size: size specifier
 */
int handle_print(const char *formatt, int *index, va_list args, char buff[], int flag, int width, int precision, int size)
{
	int i, un_len = 0, p_chars = -1;
	formatt_t formatt_args[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_per}, {'i', print_int}, {'d', print_int}, {'b', print_bin}, {'u', print_unsig}, {'o', print_oct}, {'x', print_hexa}, {'X', print_hex_upper}, {'p', print_pointer}, {'S', print_non_printable}, {'r', print_rev}, {'R', print_rot13}, {'\0', NULL}
	}
	for (i = 0; formatt_args[i].formatt !='\0'; i++)
		if(formatt[*ind] == formatt_args[i].formatt)
			return (formatt_args[i].fn(args, buff, flag, width, precision, size)
					if (formatt_args[i].formatt =='\0')
					{
					if(formatt[*ind] =='\0')
					return (-1);
					unknow_len += write(1, "%%", 1);
					if(formatt[*ind - 1] ==' ')
					unknow_len += write(1, " ", 1);
					else if (width)
					{
					--(*ind);
					while (formatt[*ind] !=' '&& formatt[*ind] !='%')
					--(*ind);
					if(formatt[*ind] ==' ')
					--(*ind);
					return (1);
					}
unknow_len += write(1, &formatt[*ind], 1);
return (unknow_len);
}
return (p_chars);
			}
