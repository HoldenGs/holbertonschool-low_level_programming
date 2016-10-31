#include "holberton.h"

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
	int i;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		else
			i++;
	}
	return (s + i + 1);
}
