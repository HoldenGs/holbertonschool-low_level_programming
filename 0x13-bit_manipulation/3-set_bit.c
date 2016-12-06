#include "holberton.h"

/**
 * set_bit - set the value of a bit to 1 at index @index
 * @n: number
 * @index: index of bit
 *
 * Return: 1 if success; -1 if failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int addbit;

	addbit = 1;
	addbit <<= index;
	if (index > 63)
		return (-1);
	*n = (*n | addbit);
	return (1);
}
