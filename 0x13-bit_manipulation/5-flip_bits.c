#include "holberton.h"

/**
 * flip_bits - return the number of bits needed to flip from
 * one number to another
 * @n: number
 * @m: new number
 *
 * Return: number of bits you'd need to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int ntmp, mtmp;
	unsigned int i;
	int bitshift;
	char nbit, mbit;

	i = 0;
	bitshift = sizeof(unsigned long int) * 8 - 1;
	while (bitshift >= 0)
	{
		ntmp = n >> bitshift;
		mtmp = m >> bitshift;
		nbit = ntmp & 1;
		mbit = mtmp & 1;
		if (nbit ^ mbit)
			i++;
		bitshift--;
	}
	return (i);
}
