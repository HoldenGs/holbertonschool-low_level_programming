#include "holberton.h"

/**
 * get_endianness - find the endianness of the current machine architecture
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int i;
	char *c;

	i = 1;
	c = (char *)&i;
	if (*c)
		return (1);
	return (0);
}
