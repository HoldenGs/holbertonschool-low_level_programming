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
	int i, j, k, wc, cc;

	if (str == NULL)
		return (NULL);

	putchar('a');
	for (i = 0; str[i] != '\0'; i++)
	{
		putchar('b');
		if (str[i] == ' ' && str[i - 1] != ' ' && i > 0)
			wc++;
	}

	printf("%d", wc);

	a = malloc(wc * sizeof(char *));

	if (a == NULL)
		return (NULL);

	i = 0;
	for (j = 0; j <= wc; j++)
	{
		putchar('d');
		cc = 0;
		while (str[i] != '\0')
		{
			if (str[i] != ' ')
				cc++;
			else if (str[i] == ' ' && str[i - 1] != ' ' && i > 0)
				break;
			i++;
		}
		i++;

		cc++;
		a[j] = malloc(cc * sizeof(char));

		if (a[j] == NULL)
			return (NULL);

		for (k = 0; k < cc; k++)
		{
			putchar('E');
			a[j][k] = str[i - cc + k + 1];
		}
		str[i - cc + k + 1] = '\0';
	}

	return (a);
}
