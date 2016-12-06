#include "holberton.h"

/**
 * get_bit - return the value of a bit at index @index
 * @n: number to find bit in
 * @index: index of bit
 *
 * Return: value of bit at @index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int compare, i, ind;

	ind = index;
	compare = 1;
	for (i = 0; i < ind; i++)
		compare *= 2;
	if (n & compare)
		return (1);
	else
		return (0);
}
