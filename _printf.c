#include "main.h"

/**
 * _printf - this prints the formatted output
 * @format: this is the format string
 * Return: the number of bytes printed
 */

int _printf(const char *format, ...)
{
	if (!format || (format[0] == '%' && !format[1]) || (format[0] ==
				'%' && format[1] == ' ' && !format[2]))
	return (-1);

	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);
	for (p = (char *)format; *p; p++)
	{
	init_params(&params, ap);
	if (*p != '%')
	{
		sum += _putchar(*p);
		continue;
	}
	start = p++;
	while (get_flag(p, &params))
		p++;

	p = get_width(p, &params, ap);
	p = get_precision(p, &params, ap);

	if (get_modifier(p))
		p++;

	if (!get_specifier(p))
		sum += print_from_to(start, p, params.l_modifier ||
				params.h_modifier ? p - 1 : 0);
	else
		sum += get_print_func(p, ap, &params);
	}

	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
