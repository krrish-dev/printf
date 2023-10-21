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
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, params_t *params)
{
	char *text = va_arg(ap, char *), padding_char = ' ';
	unsigned int padding = 0, count = 0, i = 0, j;

	(void)params;

	switch ((int)(!text))
		case 1:
			text = NULL_STRING;

	j = padding = _strlen(text);

	if (params->precision < padding)
		j = padding = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				count += _putchar(*text++);
		else
			count += _puts(text);
	}

	while (j++ < params->width)
		count += _putchar(padding_char);

	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				count += _putchar(*text++);
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
