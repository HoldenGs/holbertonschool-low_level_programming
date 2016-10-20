#include "holberton.h"

/**
 * print_most_numbers - print numbers 0-9, without 2 and 4, followed by
 * a newline
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int i;

	while (i < 10)
	{
		if (i != 2 && i != 4)
			_putchar(i + '0');
		i++;
	}
	_putchar('\n');
}
