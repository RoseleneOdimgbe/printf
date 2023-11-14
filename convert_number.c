#include "main.h"

/**
 * print_hex - this prints unsigned hex numbers in lowercase
 * @ap: this is the argument pointer
 * @params: this is the parameters struct
 * Return: bytes printed
 */

int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	/* this retrieves the argument based on modifiers */
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	/* this converts the number to a string */
	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);

	/* add '0x' if hashtag_flag is set and the number is not zero */
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}

	/* set the unsign flag and return the bytes printed */
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - this prints unsigned hex numbers in uppercase
 * @ap: this is the argument pointer
 * @params: this is the parameters struct
 * Return: bytes printed
 */

int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	/* this retrieves the argument based on modifiers */
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	/* this converts the number to a string */
	str = convert(l, 16, CONVERT_UNSIGNED, params);

	/* this adds '0X' if hashtag_flag is set and the number is not zero */
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}

	/* this sets the unsign flag and return the bytes printed */
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_binary - this prints unsigned binary numbers
 * @ap: this is the argument pointer
 * @params: this is the parameters struct
 * Return: bytes printed
 */

int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	/* add '0' if hashtag_flag is set and the number is not zero */
	if (params->hashtag_flag && n)
		*--str = '0';

	/* set the unsigned flag and return the bytes printed */
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - this prints unsigned octal numbers
 * @ap: this is the argument pointer
 * @params: this is the parameters struct
 * Return: bytes printed
 */

int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	/* this retrieves the argument based on modifiers */
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	/* c onvert the number to a string */
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	/* add '0' if hashtag_flag is set and the number is not zero */
	if (params->hashtag_flag && l)
		*--str = '0';

	/* set the unsigned flag and return the bytes printed */
	params->unsign = 1;
	return (c += print_number(str, params));
}
