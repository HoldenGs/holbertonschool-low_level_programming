#include "holberton.h"

/**
 * _isupper - checks for an uppercase character.
 *
 * @c: character to be checked for case
 *
 * Return: 1 if @c is uppercase; otherwise 0.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
