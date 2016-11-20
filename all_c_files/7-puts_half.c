#include "holberton.h"

/**
 * puts_half - print the last half of a string, followed by a newline
 *
 * @str: string to be printed
 *
 * Return: void
 */
void puts_half(char *str)
{
	int n = 0;

	while (*(str + n))
	{
		n++;
	}

	if (n % 2)
		n++;
	n /= 2;

	while (*(str + n))
	{
		_putchar(*(str + n));
		n++;
	}
	_putchar('\n');
}
