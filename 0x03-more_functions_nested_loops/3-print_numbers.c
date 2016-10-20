#include "holberton.h"

/**
 * print_numbers - print numbers 0-9, followed by a newline
 *
 * Return: void
 */
void print_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		_putchar(i + '0');
		i++;
	}
	_putchar('\n');
}
