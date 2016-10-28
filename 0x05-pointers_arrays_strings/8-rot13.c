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
		while (s[n] >= 'a' && s[n] <= 'z')
		{
			while (s[n] <= 'm')
			{
				s[n] += 13;
				n++;
			}
			while (s[n] >= 'n')
			{
				s[n] -= 13;
				n++;
			}
		}
		while (s[n] >= 'A' && s[n] <= 'Z')
		{
			while (s[n] <= 'M')
			{
				s[n] += 13;
				n++;
			}
			while (s[n] >= 'N')
			{
				s[n] -= 13;
				n++;
			}
		}
		n++;
	}
	return (s);
}
