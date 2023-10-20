#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{

	unsigned int precision = 0;

	if (*p != '.')
		return (p);

	p++;
	if (*p == '*')
	{

		int prec = va_arg(ap, int);

		if (prec >= 0)
		{

			precision = (unsigned int)prec;

		}
		else
		{

			precision = UINT_MAX;

		}

		p++;
	}
	else
	{
		while (_isdigit(*p))
		{

			precision = precision * 10 + (*p++ - '0');

		}
	}

	params->precision = precision;

	return (p);
}
