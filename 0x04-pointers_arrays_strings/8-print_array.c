#include "holberton.h"
#include <stdio.h>

/**
 * print_array - print an @n element array of integers, followed by a newline
 *
 * @a: pointer to array
 *
 * @n: length of array
 *
 * Return: void
 */
void print_array(int *a, int n)
{

	int m = 0;

	while (m < n)
	{
		printf("%d", *(a + m));
		if (m < n - 1)
			printf(", ");
		m++;
	}
	putchar('\n');
}
