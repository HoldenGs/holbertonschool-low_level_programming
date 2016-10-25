#include "holberton.h"

/**
 * *_strcpy - copies @src string to @dest buffer, including '\0'
 *
 * @dest: pointer to buffer for string
 *
 * @src: pointer to string to copy to buffer
 *
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	int n = 0;

	while (*(src + n))
	{
		*(dest + n) = *(src + n);
		n++;
	}
	if (n == 0)
		*(dest + n) = 0;
	n++;
	*(dest + n) = '\0';
	return (dest);
}
