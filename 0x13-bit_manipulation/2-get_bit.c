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
	unsigned long int compare;

	compare = 1;
	compare <<= index;
	if (compare > n)
		return (-1);
	if (n & compare)
		return (1);
	else
		return (0);
}
