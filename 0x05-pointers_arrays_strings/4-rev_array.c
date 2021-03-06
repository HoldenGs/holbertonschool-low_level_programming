#include "holberton.h"

/**
 * reverse_array - reverse the contents of an array of integers
 *
 * @a: array to be reversed
 *
 * @n: number of elements in array @a
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int m = 0, p[1000];

	while (n > 0)
	{
		p[m] = a[n - 1];
		n--;
		m++;
	}

	n = 0;
	while (n < m)
	{
		a[n] = p[n];
		n++;
	}
}
