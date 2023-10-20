#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of bytes printed
 */
int _printf(const char *format, ...)
{
	int bytes_printed = 0; /* Counter for bytes printed */
	va_list args;           /* Variable argument list */
	char *format_position;  /* Pointer to the current position in the format string */
	char *specifier_start;  /* Pointer to the start of a format specifier */
	params_t format_params = PARAMS_INIT; /* Formatting parameters */

	va_start(args, format);

	/* Check for NULL format or empty format */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	/* Check for invalid format starting with "% " (space) */
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (format_position = (char *)format; *format_position; format_position++)
	{
		/* Initialize format parameters for each iteration */
		init_params(&format_params, args);

		/* If the current character is not a '%', print it and continue */
		if (*format_position != '%')
		{
			bytes_printed += _putchar(*format_position);
			continue;
		}

		specifier_start = format_position; /* Record the start of the specifier */
		format_position++;                /* Move to the next character */

		/* Loop to handle flag characters */
		while (get_flag(format_position, &format_params))
		{
			format_position++; /* Move to the next character */
		}

		/* Extract and set width, if specified */
		format_position = get_width(format_position, &format_params, args);

		/* Extract and set precision, if specified */
		format_position = get_precision(format_position, &format_params, args);

		/* Handle length modifier if present */
		if (get_modifier(format_position, &format_params))
			format_position++;

		/* Check if the specifier is valid; otherwise, print as regular text */
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

	/* Flush the buffer */
	_putchar(BUF_FLUSH);
	va_end(args);
	return (bytes_printed);
}
