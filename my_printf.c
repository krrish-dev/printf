#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int bytes_printed = 0;
	va_list args;
	char *format_iterator, *specifier_start;
	params_t format_params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (format_iterator = (char *)format; *format_iterator; format_iterator++)
	{
		init_params(&format_params, args);
		if (*format_iterator != '%')
		{
			bytes_printed += _putchar(*format_iterator);
			continue;
		}
		specifier_start = format_iterator;
		format_iterator++;
		while (get_flag(format_iterator, &format_params))
		{
			format_iterator++;
		}
		format_iterator = get_width(format_iterator, &format_params, args);
		format_iterator = get_precision(format_iterator, &format_params, args);
		if (get_modifier(format_iterator, &format_params))
			format_iterator++;
		if (!get_specifier(format_iterator))
			bytes_printed += print_from_to(specifier_start, format_iterator,
				format_params.l_modifier ||
						format_params.h_modifier ? format_iterator - 1 : 0);
		else
			bytes_printed += get_print_func(format_iterator, args, &format_params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (bytes_printed);
}

