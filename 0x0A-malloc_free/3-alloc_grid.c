#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * alloc_grid - create a new 2D integer array initialized with 0's
 *
 * @width: width of array
 * @height: height of array
 *
 * Return: pointer to array, otherwise NULL if insufficient memory
 */
int **alloc_grid(int width, int height)
{
	int **a, i, j;

	if (width == 0 || height == 0)
		return (NULL);

	a = (int **)malloc(sizeof(int *) * height);

	if (a == NULL)
		return (NULL);

	a[0] = (int *)malloc(sizeof(int) * width * height);

	if (a == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
		a[i] = (*a + width * i);

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			a[i][j] = 0;

	return (a);
}
