#include <stdio.h>
#include "holberton.h"

/**
 * rev_string - reverse a string
 *
 * @s: pointer to array holding string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int n = 0, m = 0;
	char hold[1000];

	while (*(s + n) != 0)
	{
		hold[n] = *(s + n);
		n++;
	}

	n--;
	while (n >= 0)
	{
		*(s + n) = hold[m];
		n--;
		m++;
	}
}
