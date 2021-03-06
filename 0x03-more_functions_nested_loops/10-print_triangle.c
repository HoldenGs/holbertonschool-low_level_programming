#include "holberton.h"

/**
 * print_triangle - print a triangle that is @size characters big
 *
 * @size: size of triangle in characters
 *
 */
void print_triangle(int size)
{
	int line, space, hash, i, j;

	space = size - 1;
	hash = 1;

	for (line = 0; line < size; line++)
	{
		for (i = space; i > 0; i--)
		{
			_putchar(' ');
		}

		for (j = hash; j > 0; j--)
		{
			_putchar('#');
		}

		space--;
		hash++;
		_putchar('\n');
	}

	if (size < 1)
		_putchar('\n');
}
