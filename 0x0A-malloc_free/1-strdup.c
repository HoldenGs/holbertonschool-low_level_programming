#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * _strlen - return the int size of the string
 *
 * @str: string to measure
 *
 * Return: integer size of string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strdup - return a pointer to a duplicate string of @str
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicate string; NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *a;
	int i, size;


	if (str == NULL)
		return (NULL);
	size = _strlen(str);

	a = malloc((size + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		a[i] = str[i];
	}
	a[i] = str[i];
	return (a);
}
