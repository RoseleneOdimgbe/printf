#include "main.h"

/**
 * get_precision - this extracts the precision from the format specifier
 * @p: the format specifier string
 * @params: the parameters struct
 * @ap: argument pointer
 * Return: the new pointer after extracting the precision information
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int precision = 0;

	if (*p != '.')
		return (p);

	p++;  /* move to the character after the dot '.' */

	if (*p == '*')
	{
		precision = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			precision = precision * 10 + (*p++ - '0');
	}

	params->precision = precision;
	return (p);
}
