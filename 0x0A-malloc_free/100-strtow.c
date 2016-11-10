#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * strtow - split a string into words
 *
 * @str: string
 *
 * Return: Pointer array of strings containing each word; NULL if failure
 */
char **strtow(char *str)
{
	char **a;
	int j, k, wc, cc, inword;

	inword = 0;

	if (str == NULL)
		return (NULL);

	wc = word_count(str);

	a = malloc(wc * sizeof(char *));

	if (a == NULL)
		return (NULL);

	for (j = 0; j < 3; j++)
	{
		cc = char_count(str, k);
		cc++;
		a[j] = malloc(cc * sizeof(char));

		if (a[j] == NULL)
			return (NULL);

		k = wc = cc = 0;
		while (str[k] != '\0')
		{
			if (str[k] == ' ' && wc == j + 1)
				break;
			else if (str[k] == ' ')
			{
				inword = 0;
				while (str[k] == ' ')
					k++;
			}
			else
			{
				if (!inword && wc == j)
				{
					inword = 1;
					wc++;
				}
				else if (!inword)
				{
					inword = 1;
					wc++;
				}
				if (wc == j + 1)
				{
					a[j][cc] = str[k];
					cc++;
				}
				k++;
			}
		}
		a[j][cc] = '\0';
	}

	return (a);
}

/**
 * word_count - count the words in string @s
 *
 * @s: string
 *
 * Return: integer word count, or NULL if failure
 */
int word_count(char *s)
{
	int i, inword, wc;

	inword = i = wc = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			inword = 0;
			while (s[i] == ' ')
				i++;
		}
		else
		{
			if (inword == 0)
			{
				inword = 1;
				wc++;
			}
			i++;
		}
	}

	return (wc);
}

/**
 * char_count - count the number of characters in the next word
 *
 * @s: string
 * @start: starting position in string @s
 *
 * Return: number of characters in next word in string @s
 */
int char_count(char *s, int start)
{
	int i, cc, kill;

	i = start;
	cc = kill = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' && kill == 1)
			return (cc);
		else if (s[i] == ' ')
		{
			while (s[i] == ' ')
				i++;
		}
		else
		{
			cc++;
			i++;
			kill = 1;
		}
	}
	return (cc);
}
