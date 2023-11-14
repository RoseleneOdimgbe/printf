#include "main.h"

/**
 * _puts - this prints a string with a newline
 * @str: this is the string to print
 * Return: the number of characters printed (excluding the null byte)
 */

int _puts(char *str)

{
	char *start = str;

	while (*str)
		_putchar(*str++);

	_putchar('\n'); /* this prints a newline at the end */
	return (str - start + 1);
}

/**
 * _putchar - this writes the character c to stdout
 * @c: this is the character to print
 * Return: On success 1. On error, -1 is returned,
 * and errno is set appropriately
 */

int _putchar(int c)

{
	static int index;
	static char buffer[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || index >= OUTPUT_BUF_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}

	if (c != BUF_FLUSH)
		buffer[index++] = c;

	return (1);
}
