#include "holberton.h"

/**
 * cap_string - capitalize all words in a string
 *
 * @s: string to manipulate
 *
 * Return: pointer to char string @s
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z')
		    && (s[i - 1] == ',' || s[i - 1] == ';' || s[i - 1] == '.'
			|| s[i - 1] == '!' || s[i - 1] == '?' || s[i - 1] == '"'
			|| s[i - 1] == '(' || s[i - 1] == ')' || s[i - 1] == '{'
			|| s[i - 1] == '}' || s[i - 1] == ' ' || s[i - 1] == '\n'
			|| s[i - 1] == '\t'))
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}
