#include "holberton.h"

/**
 * _strncpy - copy @n bytes of string @src to buffer @dest
 *
 * @dest: pointer to buffer destination
 *
 * @src: string to string to copy over
 *
 * @n: number of bytes of @src to copy
 *
 * Return: pointer to string @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = n;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
