#include "holberton.h"

/**
 * print_rev - print a string, in reverse, followed by a newline
 *
 * @s: string to manipulate
 *
 * Return: void
 */
void print_rev(char *s)
{
	int m = 0;

	while (*(s + m) != '\0')
	{

		m++;
	}

	m--;
	while (m >= 0)
	{
		_putchar(*(s + m));
		m--;
	}
	_putchar('\0');
	_putchar('\n');
}
