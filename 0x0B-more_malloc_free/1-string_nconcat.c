#include <stdio.h>
#include <stdlib.h>
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
 * string_nconcat - concatenates two strings
 *
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes of @s2 to use
 *
 * Return: pointer to concatenation of @n bytes of @s2 to @s1; NULL if failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s, *p;
	unsigned int length1, length2, i;

	length1 = _strlen(s1);
	length2 = _strlen(s2);

	if (length2 <= n)
		n = length2;

	s = malloc((length1 + n + 1) * sizeof(char));

	if (s == NULL)
		return (NULL);

	p = s;

	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}

	i = 0;
	while (i < n)
	{
		*s = *s2;
		s++;
		s2++;
		i++;
	}
	*s = '\0';

	return (p);
}
