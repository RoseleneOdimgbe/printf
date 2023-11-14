#ifndef _MYPRINTF_H
#define _MYPRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _puts(char *str);
int _putchar(int c);
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
int _isdigit(int c);
int _strlen(char *s);
int _printf(const char *format, ...);

#endif
