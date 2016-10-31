#include "holberton.h"
#define NULL "NULL"

/**
 * _strchr - locate a character in a string
 *
 * @s: pointer to string
 * @c: character
 *
 * Return: pointer to first occurrence of @c in @s
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (c == '\0')
		return (s + (i + 1));
	return (NULL);
}
