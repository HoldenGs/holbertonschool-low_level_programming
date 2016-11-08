#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * create_array - create an array of @c characters @size long
 *
 * @size: size of array
 * @c: character to fill array
 *
 * Return: pointer to array, otherwise NULL
 */
char *create_array(unsigned int size, char c)
{
	char *a;
	unsigned int i;

	a = malloc(size * sizeof(char));

	if (a == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= size; i++)
		a[i] = c;

	return (a);
}
