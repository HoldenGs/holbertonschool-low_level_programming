#include "holberton.h"

/**
 * _memcpy - copy @n byte from memory area @src to memory area @dest
 *
 * @dest: destination memory area
 * @src: source memory area
 * @n: bytes of memory to copy over
 *
 * Return: pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
