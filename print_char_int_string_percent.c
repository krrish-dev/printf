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
 * pad_string - Handles padding and precision truncation
 * for a string before printing.
 * @str: The string to pad.
 * @params: Struct containing settings like precision.
 * Return: new padded/truncated string length
 */
int pad_string(char *str, params_t *params)
{
	unsigned int len = _strlen(str);
	int precision = params->precision;

	if (params->precision >= 0 && (unsigned int)params->precision < len)
	{
		str[params->precision] = '\0';
		len = (unsigned int)params->precision;
	}

	return (int)len;
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
	char *str = va_arg(ap, char *);
	unsigned int count = 0;
	unsigned int len = str ? _strlen(str) : 6;

	len = pad_string(str, params);

	if (params->minus_flag)
	{
		if (params->precision != INT_MAX)
			count += _puts(str);
	}
	else
	{
		while (len++ < params->width)
			count += _putchar(' ');
		if (params->precision != INT_MAX)
			count += _puts(str);
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
