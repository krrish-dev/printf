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
	params->is_unsigned = 0;
	params->has_plus_flag = 0;
	params->has_space_flag = 0;
	params->has_hashtag_flag = 0;
	params->has_zero_flag = 0;
	params->has_minus_flag = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->has_h_modifier = 0;
	params->has_l_modifier = 0;
	(void)ap;
}
