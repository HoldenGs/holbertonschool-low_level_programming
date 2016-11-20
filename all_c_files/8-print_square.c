#include "holberton.h"

/**
 * print_square - print a square @size characters big, followed by a newline
 *
 * @size: length and width of square
 *
 * Return: void
 */
void print_square(int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}

	if (size < 1)
		_putchar('\n');
}
