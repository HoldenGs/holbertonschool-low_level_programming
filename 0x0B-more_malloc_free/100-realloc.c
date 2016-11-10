#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _realloc - reallocates a memory block
 *
 * @ptr: pointer to memory already allocated
 * @old_size: old byte size of memory at @ptr
 * @new_size: new byte size of memory at @ptr
 *
 * Return: pointer to reallocated memory; NULL if failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	char *a, *ptc;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	ptc = ptr;

	a = malloc(new_size);
	if (a == NULL)
		return (NULL);

	if (new_size < old_size)
		old_size = new_size;

	p = a;

	for (i = 0; i < old_size; i++)
		a[i] = ptc[i];

	free(ptr);
	return (p);
}
