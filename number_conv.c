#include "main.h"

/**
 * convert - the converter function, a clone of itoa
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 * @params: the parameter struct
 * Return: string
 */

char *convert(long int num, int base, int flags, params_t *params)

{
	static char buffer[50];
	char *array = (flags & CONVERT_LOWERCASE)
		? "0123456789abcdef" : "0123456789ABCDEF";
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	/* handle negative numbers */
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	ptr = &buffer[49];
	*ptr = '\0';

	/* converts the number to the specified base */
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	/* add the sign if necessary */
	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * print_unsigned - this prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	/* retrieves the argument based on modifiers */
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - this prints the address
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	/* handle NULL pointer */
	if (!n)
		return (_puts("(nil)"));

	/* converts the address to hexadecimal and add '0x' */
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';

	return (print_number(str, params));
}
