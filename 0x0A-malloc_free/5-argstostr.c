#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenate all the arguments passed to the program
 *
 * @ac: number of arguments
 * @av: pointer array of arguments
 *
 * Return: pointer to new string; NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *a;
	int i, j, size, strcount;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; *(*(av + i) + j) != '\0'; j++)
			size++;
		size++;
	}

	a = malloc((size + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	strcount = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; *(*(av + i) + j) != '\0'; j++)
		{
			*(a + strcount) = *(*(av + i) + j);
			strcount++;
		}
		*(a + strcount) = '\n';
		strcount++;
	}
	*(a + strcount) = '\0';

	return (a);
}
