#include "main.h"

/**
 * _isdigit - this checks if a character is a digit
 * @c: this is the character to check
 * Return: 1 if it is a digit, 0 if otherwise
 */

int _isdigit(int c)

{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - this returns the length of a string
 * @s: this is the string length to check
 * Return: integer length of the string
 */

int _strlen(char *s)

{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}
