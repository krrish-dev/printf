#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list ap, params_t *params)
{
	char padding_char = ' ';
	unsigned int padding = 1, count = 0, character = va_arg(ap, int);

	if (params->minus_flag)
		count += _putchar(character);

	while (padding++ < params->width)
		count += _putchar(padding_char);

	if (!params->minus_flag)
		count += _putchar(character);

	return (count);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ap, params_t *params)
{
	long integer;

	if (params->l_modifier)
		integer = va_arg(ap, long);
	else if (params->h_modifier)
		integer = (short int)va_arg(ap, int);
	else
		integer = (int)va_arg(ap, int);

	return (print_number(convert(integer, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list args, params_t *params)
{
	char *text = va_arg(args, char *);
	unsigned int padding = 0, count = 0;

	if (!text)
		text = "(null)";

	padding = _strlen(text);

	if (params->precision < padding)
	{
		text[params->precision] = '\0';
		while (padding < params->precision)
			text[padding++] = ' ';
	}
	else if (params->precision > padding)
		while (padding < params->precision)
			text[padding++] = ' ';

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (int i = 0; i < padding; i++)
				count += _putchar(text[i]);
		else
			count += _puts(text);
	}

	while (padding++ < params->width)
		count += _putchar(' ');

	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (int i = 0; i < padding; i++)
				count += _putchar(text[i]);
		else
			count += _puts(text);
	}

	return (count);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
	char *text = va_arg(ap, char *);
	char *hexadecimal;
	int count = 0;

	if ((int)(!text))
		return (_puts(NULL_STRING));

	for (; *text; text++)
	{
		if ((*text > 0 && *text < 32) || *text >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hexadecimal = convert(*text, 16, 0, params);

			if (!hexadecimal[1])
				count += _putchar('0');

			count += _puts(hexadecimal);
		}
		else
		{
			count += _putchar(*text);
		}
	}

	return (count);
}
