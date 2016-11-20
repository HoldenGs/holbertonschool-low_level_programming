#include "holberton.h"

/**
 * _memset - fill @n bytes of area pointed to by @s with the constant byte @b
 *
 * @s: pointer to buffer
 * @b: constant byte to fill buffer
 * @n: number of bytes of @s to fill with @b
 *
 * Return: a pointer to the memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
