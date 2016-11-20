#include "holberton.h"

/**
 * _strncat - concatenate a string with @n bytes from @src to @dest
 *
 * @dest: string receiving concatenation
 *
 * @src: string to concatenate to @dest
 *
 * @n: number of bytes of @src to concatenate
 *
 * Return: pointer to @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, length = 0;

	while (dest[length])
		length++;
	while (index < n && src[index])
	{
		dest[length++] = src[index++];
	}
	return (dest);
}
