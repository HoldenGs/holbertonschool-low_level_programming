#include "holberton.h"

/**
 * puts2 - print the last half of a string, followed by a newline
 *
 * @str: string to be printed
 *
 * Return: 0
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
