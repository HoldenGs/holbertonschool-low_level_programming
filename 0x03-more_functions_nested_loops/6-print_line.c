#include "holberton.h"

/**
 * print_line - print a straight line @n characters long, followed by a newline
 *
 * @n: character length of line
 *
 * Return: void
 */
void print_line(int n)
{
	while (n > 0)
	{
		_putchar('_');
		n--;
	}
	_putchar('\n');
}
