#include "holberton.h"

/**
 * _strstr - locate substring @needle in string @haystack
 *
 * @haystack: string to search for instances of @haystack
 * @needle: substring to search @haystack for
 *
 * Return: a pointer to the beginning of the located substring, otherwise NULL
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int flag = 0, i, j, ncount = 0;

	while (needle[ncount])
		ncount++;



	for (i = 0; haystack[i]; i++)
	{
		j = i;
		while (needle[flag] == haystack[j] && needle[flag] && haystack[i])
		{
			j++;
			flag++;
		}

		if (flag == ncount)
			return (haystack + i);
	}
	return (0);
}
