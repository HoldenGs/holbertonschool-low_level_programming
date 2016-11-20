#include "holberton.h"

/**
 * puts2 - print one char for every two in a string, followed by a newline
 *
 * @str: string to be printed
 *
 * Return: void
 */
void puts2(char *str)
{
	int n = 0;

	while (*(str + n) != 0)
	{
		if (n % 2 == 0)
			_putchar(*(str + n));
		n++;
	}
	_putchar('\n');
}
