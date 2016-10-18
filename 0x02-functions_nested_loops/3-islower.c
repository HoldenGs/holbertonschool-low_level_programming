#include "holberton.h"

/**
 * _islower - check for a lowercase character
 *
 * @c: the integer to be checked
 * Return: 0
 */
int _islower(int c)
{
	if (c < 'a' || c > 'z')
		return (0);
	else
		return (1);
}
