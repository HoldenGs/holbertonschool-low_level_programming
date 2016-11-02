#include "holberton.h"

/**
 * _strlen_recursion - return the length of a string
 *
 * @s: string to measure
 *
 * Return: int length of string
 */
int _strlen_recursion(char *s)
{
	int length;

	length = 0;
	if (*s == 0)
		return (0);
	return ((length + 1) + _strlen_recursion(s + 1));

}
