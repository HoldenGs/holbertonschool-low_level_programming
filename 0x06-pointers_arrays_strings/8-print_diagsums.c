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
	int i = 0, sum = 0;

	while (i < size)
	{
		sum += *(a + i * (size + 1));
		printf("1, %d\n", *(a + i * (size + 1)));
		i++;
	}
	printf("%d\n", sum);

	sum = 0;
	while (i > 0)
	{
		sum += *(a + i * (size - 1));
		printf("1, %d\n", *(a + i * (size + 1)));
		i--;
	}
	printf("%d\n", sum);
}
