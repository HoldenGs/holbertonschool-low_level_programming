#include "holberton.h"

/**
 * string_toupper - change all lowercase letters of a string to uppercase
 *
 * @s: string to be converted to lowercase
 *
 * Return: @s after lowercase conversion
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}
