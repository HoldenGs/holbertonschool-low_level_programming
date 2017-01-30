#include "monty.h"

/**
 * main - main function to take arguments for monty interpreter
 *
 * @ac: argument count
 * @av: pointer array of arguments
 *
 * Return: 0 if success, EXIT_FAILURE if failure
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	interpreter(av[1]);
	return (0);
}

/**
 * interpreter - interpreter loop; opens file, parses, and executes bytecode
 *
 * @file: file name
 *
 * Return: 0 if success, EXIT_FAILURE if failure
 */
int interpreter(char *file)
{
	int number, err;
	size_t size;
	unsigned int line_number;
	char *buffer, *code, *numstr;
	stack_t *head;
	FILE *fp;


	size = line_number = err = 0;
	head = NULL;
	buffer = NULL;
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fp) != -1)
	{
		line_number++;
		code = strtok(buffer, " \t\n");
		if (code != NULL)
		{
			if (strcmp("push", code) == 0)
			{
				numstr = strtok(NULL, " \t\n");
				number = push_checker(numstr, line_number);
			}
			execute(&head, line_number, code, number);
		}
	}
	free_list(head);
	free(buffer);
	fclose(fp);
	return (0);
}
