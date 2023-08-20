#include "main.h"
void print_buffer(char buffer[], int *buff_index);
/**
 * _printf - printf function
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, p_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			/*write(1, &format[i], 1);*/
			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			p_chars += printed;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(args);
	return (p_chars);
}
/**
 * print_buffer - prints contents of buffer if exists
 * @buffer: array of characters
 * @buff_index: index at which to add next char, represents length
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
