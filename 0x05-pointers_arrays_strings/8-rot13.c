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
	int n = 0;

	while (s[n])
	{
		if ((s[n] >= 'n' && s[n] <= 'z') || (s[n] >= 'N' && s[n] <= 'Z'))
		{
			s[n] -= 13;
		}
		else
		{
			while ((s[n] >= 'a' && s[n] <= 'm') || (s[n] >= 'A' && s[n] <= 'M'))
			{
				s[n] += 13;
			}
		}
		n++;
	}
	return (s);
}
