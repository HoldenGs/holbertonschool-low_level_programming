#include "holberton.h"

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: binary string
 *
 * Return: unsigned integer equivalent of @b
 */
unsigned int binary_to_uint(const char *b)
{
	int i, multiplier;
	unsigned int n;

	i = n = 0;
	multiplier = 1;
	if (b == NULL)
		return (0);
	while (b[i] != 0)
		i++;
	i--;
	while (i >= 0)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		if (b[i] == '1')
			n += multiplier;
		multiplier *= 2;
		i--;
	}
	return (n);
}
