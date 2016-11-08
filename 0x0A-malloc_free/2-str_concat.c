#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _strlen - get string length
 *
 * @str: string
 *
 * Return: Length of string
 */
int _strlen(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
		i++;
	return (i);
}

/**
 * str_concat - concatenate two strings into memory space
 *
 * @s1: First string
 * @s2: Second string
 *
 * Return: pointer to combined string
 */
char *str_concat(char *s1, char *s2)
{
	char *a;
	int i;

	a = malloc(sizeof(*s1) + sizeof(*s2));

	if (a == NULL)
		return (NULL);

	i = 0;
	while (*s1 != '\0')
	{
		a[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		a[i] = *s2;
		i++;
		s2++;
	}

	return (a);
}
