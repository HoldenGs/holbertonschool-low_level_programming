#include "holberton.h"
#include <stdio.h>

/**
 * print_array - print an @n element array of integers, followed by a newline
 *
 * Return: void
 */
void print_array(int *a, int n)
{
	int m = 0;

	while (m < n)
	{
		if (m == n - 1)
			printf("%d\n", *(a + m));
		else
			printf("%d, ", *(a + m));
		m++;
	}
}
