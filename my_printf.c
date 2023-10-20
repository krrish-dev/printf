#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of bytes printed
 */
#include "main.h"

int _printf(const char *format, ...)
{
	int bytes_printed = 0;
	va_list args;
	char *format_position;
	char *specifier_start;
	params_t format_params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (format_position = (char *)format; *format_position; format_position++)
	{
		init_params(&format_params, args);

		if (*format_position != '%')
		{
			bytes_printed += _putchar(*format_position);
			continue;
		}

		specifier_start = format_position;
		format_position++;

		while (get_flag(format_position, &format_params))
		{
			format_position++;
		}

		format_position = get_width(format_position, &format_params, args);
		format_position = get_precision(format_position, &format_params, args);

		if (get_modifier(format_position, &format_params))
			format_position++;

		if (!get_specifier(format_position))
		{
			bytes_printed += print_from_to(specifier_start, format_position,
				params.l_modifier || params.h_modifier ? format_position - 1 : 0);
		}
		else
		{
			bytes_printed += get_print_func(format_position, args, &format_params);
		}
	}

	_putchar(BUF_FLUSH);
	va_end(args);
	return (bytes_printed);
}
