#include "holberton.h"

/**
 * _strlen - return the length of a string
 *
 * @s: string whose length to return
 *
 * Return: length of @s
 */
int _strlen(char *s)
{
	int n, m = 0;

	while (*(s + m) != '\0')
	{
		++n;
		m++;
	}
	return (n);
}
