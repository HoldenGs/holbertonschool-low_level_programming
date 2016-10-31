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
	int i = 0;

	while (s[i] != 0 && s[i] != c)
		++i;
	if (s[i] != 0)
		return (s + i);
	else
		return ('\0');
}
