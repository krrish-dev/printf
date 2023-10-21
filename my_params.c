#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ap;
}

/**
 * print_text - prints text with specified parameters
 * @text: the string to print
 * @params: the parameters struct
 *
 * Return: number of characters printed
 */
int print_text(char *text, params_t *params)
{
	char padding_char = ' ';
	unsigned int count = 0, i = 0;

	unsigned int padding = _strlen(text);
	unsigned int j = padding;

	if (params->precision >= 0 && params->precision < padding)
	{
		padding = params->precision;
		j = padding;
	}

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			while (i < padding)
				count += _putchar(*text++);
		else
			count += _puts(text);
	}

	while (j++ < params->width)
		count += _putchar(padding_char);

	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			while (i < padding)
				count += _putchar(*text++);
		else
			count += _puts(text);
	}

	return (count);
}
