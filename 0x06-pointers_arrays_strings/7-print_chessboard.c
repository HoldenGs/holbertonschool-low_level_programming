#include "holberton.h"

/**
 * print_chessboard - print a chessboard
 *
 * @a: 2D array matrix to be printed
 *
 * Return: void
 */
void print_chessboard(char *a[8])
{
	int i, j;

	for (i = 0; a[i][0]; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
