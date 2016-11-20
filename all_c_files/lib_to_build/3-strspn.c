#include "holberton.h"

/**
 * _strspn - get the length of a prefix substring
 *
 * @s: string to search
 * @accept: substring to compare string with
 *
 * Return: number of bytes in th initial segment of @s which consist of only
 * bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0, j = 0, flag = 0, count = 0;

	while (s[i] && count == i)
	{
		while (accept[j] && !(flag))
		{
			if (accept[j] == s[i])
			{
				count++;
				flag = 1;
			}
			j++;
		}
		j = 0;
		flag = 0;
		i++;
	}
	return (count);
}
