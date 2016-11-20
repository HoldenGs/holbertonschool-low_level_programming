#include "holberton.h"

/**
 * _strpbrk - search string @s for the first occurance of any bytes of @accept
 *
 * @s: string to search
 * @accept: string to search @s for bytes from
 *
 * Return: a pointer to the byte @s that matches one of the bytes in accept,
 * otherwise NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (accept[j] == s[i])
				return (s + i);
			j++;
		}
		i++;
	}
	return ('\0');
}
