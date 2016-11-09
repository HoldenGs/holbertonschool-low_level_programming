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
	{
		str++;
		i++;
	}
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
	int i, s1length, s2length;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s1length = _strlen(s1);
	s2length = _strlen(s2);

	a = malloc(s1length + s2length + 1);

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
	a[i] = '\0';

	return (a);
}
