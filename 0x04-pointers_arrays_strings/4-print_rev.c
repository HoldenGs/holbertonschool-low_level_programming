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
	int n, m = 0;

	while (*(s + m) != '\0')
	{
		++n;
		m++;
	}

	while (n >= 0)
	{
		_putchar(*(s + n));
		n--;
	}
	_putchar('\n');
}
