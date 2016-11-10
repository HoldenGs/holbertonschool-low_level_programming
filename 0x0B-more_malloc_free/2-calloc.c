#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _calloc - allocate memory for an array @nmemb elements long of @size bytes
 *
 * @nmemb: number of elements
 * @size: byte size of an element
 *
 * Return: pointer to first element of array; NULL if failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);

	if (p == NULL)
		return (NULL);

	s = p;

	for (i = 0; i <= (nmemb * size); i++)
	{
		s[i] = 0;
	}
	return (p);
}
