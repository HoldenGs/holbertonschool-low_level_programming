#include "monty.h"

/**
 * push_checker - error checks the argument after push
 *
 * @numstr: the argument string, should be numbers
 *
 * @line_number: line number in file
 *
 * Return: integer version of @numstr; EXIT_FAILURE if failure
 */
int push_checker(char *numstr, unsigned int line_number)
{
	int number, i;

	if (numstr == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; numstr[i]; i++)
	{
		if (isdigit(numstr[i]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(numstr);
	return (number);
}
