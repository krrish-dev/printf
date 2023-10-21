#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
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

