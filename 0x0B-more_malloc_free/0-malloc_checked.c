#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * malloc_checked - allocate memory of byte size @b
 *
 * @b: byte size of memory to allocate
 *
 * Return: pointer to memory, 98 if failure
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	if (b == 0)
		exit(98);

	p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
