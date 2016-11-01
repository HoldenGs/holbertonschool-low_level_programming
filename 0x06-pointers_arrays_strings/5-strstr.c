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
	int i, n, itemp, ncount = 0;

	while (needle[ncount])
		ncount++;

	while (haystack[i])
	{
		n = 0;
		itemp = i;
		while (haystack[itemp] == needle[n])
		{
			if (n == ncount)
			{
				return (haystack + i);
			}
			itemp++;
			n++;
		}
		i++;
	}
	return ('\0');
}
