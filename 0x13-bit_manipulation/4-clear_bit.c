#include "holberton.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index @index
 * @n: pointer to number
 * @index: index of bit
 *
 * Return: 1 if success; -1 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int setbit;

	setbit = 1;
	setbit <<= index;
	setbit = ~setbit;
	if (index > 63)
		return (-1);
	*n = (*n & setbit);
	return (1);
}
