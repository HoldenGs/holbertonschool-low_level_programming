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

	long m = 0, p = n;

	while (m < p)
	{
		if (m == p - 1)
			printf("%d\n", *(a + m));
		else
			printf("%d, ", *(a + m));
		m++;
	}
}
