#include "main.h"

/**
 * is_digit - checks if character is a digit
 * @c: the character to check
 *
 * Return: 1 if it's a digit, 0 otherwise
 */
int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * string_length - returns the length of a string
 * @s: the string whose length to determine
 *
 * Return: the length of the string
 */
int string_length(char *s)
{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}

/**
 * print_formatted_number - prints a number with specified options
 * @number_str: the number as a string
 * @params: the parameter struct
 *
 * Return: number of characters printed
 */
int print_formatted_number(char *number_str, params_t *params)
{
	unsigned int length = string_length(number_str);
	int is_negative = (!params->unsign && *number_str == '-');

	if (!params->precision && *number_str == '0' && !number_str[1])
		number_str = "";
	if (is_negative)
	{
		number_str++;
		length--;
	}
	if (params->precision != UINT_MAX)
		while (length++ < params->precision)
			*--number_str = '0';
	if (is_negative)
		*--number_str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(number_str, params));
	else
		return (print_number_left_shift(number_str, params));
}

/**
 * print_number_right_shift - prints a number with specified options
 * @number_str: the number as a string
 * @params: the parameter struct
 *
 * Return: number of characters printed
 */
int print_number_right_shift(char *number_str, params_t *params)
{
	unsigned int char_count = 0, is_negative, is_negative2;
	unsigned int length = string_length(number_str);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	is_negative = is_negative2 = (!params->unsign && *number_str == '-');
	if (is_negative && length < params->width &&
		padding_char == '0' && !params->minus_flag)
		number_str++;
	else
		is_negative = 0;
	if ((params->plus_flag && !is_negative2) ||
		(!params->plus_flag && params->space_flag && !is_negative2))
		length++;
	if (is_negative && padding_char == '0')
		char_count += _putchar('-');
	if (params->plus_flag && !is_negative2 &&
		padding_char == '0' && !params->unsign)
		char_count += _putchar('+');
	else if (!params->plus_flag &&
		params->space_flag && !is_negative2 &&
		!params->unsign && params->zero_flag)
		char_count += _putchar(' ');
	while (length++ < params->width)
		char_count += _putchar(padding_char);
	if (is_negative && padding_char == ' ')
		char_count += _putchar('-');
	if (params->plus_flag && !is_negative2 &&
	padding_char == ' ' && !params->unsign)
		char_count += _putchar('+');
	else if (!params->plus_flag && params->space_flag &&
	!is_negative2 &&
		!params->unsign && !params->zero_flag)
		char_count += _putchar(' ');
	char_count += _puts(number_str);

	return (char_count);
}

/**
 * print_number_left_shift - prints a number with specified options
 * @number_str: the number as a string
 * @params: the parameter struct
 *
 * Return: number of characters printed
 */
int print_number_left_shift(char *number_str, params_t *params)
{
	unsigned int char_count = 0, is_negative, is_negative2;
	unsigned int length = string_length(number_str);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	is_negative = is_negative2 = (!params->unsign && *number_str == '-');
	if (is_negative && length < params->width && padding_char == '0' && !params->minus_flag)
		number_str++;
	else
		is_negative = 0;

	if (params->plus_flag && !is_negative2 && !params->unsign)
		char_count += _putchar('+'), length++;
	else if (params->space_flag && !is_negative2 && !params->unsign)
		char_count += _putchar(' '), length++;

	char_count += _puts(number_str);

	while (length++ < params->width)
		char_count += _putchar(padding_char);

	return (char_count);
}
