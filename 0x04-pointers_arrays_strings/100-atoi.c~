#include "holberton.h"
#include <stdio.h>

/**
 * _atoi - convert a string to an integer
 *
 * @s: pointer to a string to parse
 *
 * Return: @s
 */
int _atoi(char *s)
{
	int new_int = 0, sign = 0, n, on_int = 0;

	for (n = 0; *(s + n) != 0; n++)
	{
		if (s[n] == '-')
		{
			sign--;
		}
		else if (s[n] == '+')
			sign++;
		if (s[n] >= '0' && s[n] <= '9')
		{
			if (sign < 0)
			{
				sign = -1;
			}
			else if (sign >= 0)
				sign = 1;

			on_int = 1;
			new_int = new_int * 10 + (s[n] - '0');
		}
		else if (on_int == 1)
		{
			return (new_int * sign);
		}
	}
	return (new_int * sign);
}
