#include "holberton.h"

/**
 * rot13 - encode string @s using rot13
 *
 * @s: string to encode
 *
 * Return: pointer to encoded string @s
 */
char *rot13(char *s)
{
	int n = 0, m = 0;

	while (s[n])
	{
		for (m = n; ((s[m] >= 'a' && s[m] <= 'z') || (s[m] >= 'A' && s[m] <= 'Z')) && m <= n; m++)
		{
			if (s[m] <= 'm' || s[m] <= 'M')
				s[m] += 13;
			else
				s[m] -= 13;
		}
		n++;
	}
	return (s);
}
