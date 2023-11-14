#include "main.h"

/**
 * init_params - this initializes and clears the parameters struct
 * @params: the parameters struct to be initialized
 * @ap: the argument pointer (unused in this function)
 * this function initializes the fields of
 * the parameters struct to default values.
 * the flags are set to 0, width to 0, precision
 * to UINT_MAX, and modifiers to 0.
 * Return: void
 */

void init_params(params_t *params, va_list ap)
{
	/* clear all flags and set default values */
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

	/* unused argument */
	(void)ap;
}
