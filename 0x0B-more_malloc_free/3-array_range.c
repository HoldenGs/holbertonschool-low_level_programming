#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * array_range - create an array of integers containing values increasing from
 * @min to @max
 *
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to integer array; NULL if failure
 */
int *array_range(int min, int max)
{
	int *a, i;

	if (min > max)
		return (NULL);

	a = malloc((max - min + 1) * sizeof(*a));

	if (a == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
	{
		a[i] = min;
		min++;
	}
	return (a);
}
