#include "holberton.h"
#include <stdio.h>

/**
 * print_diagsums - print the sum of the two diagonals of a square matrix
 *
 * @a: pointer to square matrix
 * @size: size of matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i = 0, sum = 0, next = 0;

	while (i < (size * size))
	{
		next = a[i];
		sum += next;
		i += size + 1;
	}
	printf("%d, ", sum);

	i = size - 1;
	sum = 0;
	while (i < (size * size - 1))
	{
		next = a[i];
		sum += next;
		i += size - 1;
	}
	printf("%d\n", sum);
}
