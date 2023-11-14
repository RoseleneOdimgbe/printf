#include "main.h"

/**
 * get_specifier - this finds the corresponding format function
 * @s: the format specifier string
 * Return: the pointer to the corresponding print function
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - this gets the print function based on the format specifier
 * @s: the format specifier string
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - this sets the corresponding flag in the parameters struct
 * @s: the format specifier string
 * @params: the parameters struct
 * Return: 1 if a flag was set, 0 otherwise
 */

int get_flag(char *s, params_t *params)
{
	switch (*s)
	{
		case '+':
			return (params->plus_flag = 1);
		case ' ':
			return (params->space_flag = 1);
		case '#':
			return (params->hashtag_flag = 1);
		case '-':
			return (params->minus_flag = 1);
		case '0':
			return (params->zero_flag = 1);
		default:
			return (0);
	}
}

/**
 * get_modifier - this sets the corresponding modifier in the parameters struct
 * @s: the format specifier string
 * @params: the parameters struct
 * Return: 1 if a modifier was set, 0 otherwise
 */

int get_modifier(char *s, params_t *params)
{
	switch (*s)
	{
		case 'h':
			return (params->h_modifier = 1);
		case 'l':
			return (params->l_modifier = 1);
		default:
			return (0);
	}
}

/**
 * get_width - this extracts the width from the format specifier
 * @s: the format specifier string
 * @params: the parameters struct
 * @ap: argument pointer
 * Return: the new pointer after extracting the width information
 */

char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
