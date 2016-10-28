#include "holberton.h"

/**
 * leet - encodes string into 1337
 *
 * @s: string to encode
 *
 * Return: pointer to encoded string @s
 */
char *leet(char *s)
{
	int n = 0;

	while (s[n])
	{
		while (s[n] == 'a' || s[n] == 'A')
			s[n] = '4';
		while (s[n] == 'e' || s[n] == 'E')
			s[n] = '3';
		while (s[n] == 'o' || s[n] == 'O')
			s[n] = '0';
		while (s[n] == 't' || s[n] == 'T')
			s[n] = '7';
		while (s[n] == 'l' || s[n] == 'L')
			s[n] = '1';
		n++;
	}
	return (s);
}
