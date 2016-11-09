#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - free a 2D array previously created by alloc_grid
 *
 * @grid: double pointer to 2D array
 * @height: height of array
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = height - 1; i >= 0; i--)
		free(grid[i]);
	free(grid);
}
