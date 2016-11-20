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
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *lookingforme = needle;

		while (*lookingforme == *haystack && *lookingforme != '\0'
		       && *haystack != '\0')
		{
			haystack++;
			lookingforme++;
		}
		if (*lookingforme == '\0')
			return (start);
		haystack = start + 1;
	}
	return ('\0');
}
