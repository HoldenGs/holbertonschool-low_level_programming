#include "holberton.h"

/**
 * _strcat - concatenates two strings, overwriting the null terminator of @dest
 *
 * @dest: the string receiving concatenation
 *
 * @src: the string concatenating to the end of @dest
 *
 * Return: @dest after concatenation
 */
char *_strcat(char *dest, char *src)
{
	int index = 0, length = 0;

	while (dest[length])
		length++;
	while (src[index])
	{
		dest[length] = src[index];
		length++;
		index++;
	}
	return (dest);
}
