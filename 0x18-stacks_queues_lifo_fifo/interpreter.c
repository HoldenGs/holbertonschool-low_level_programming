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
	size_t size;
	unsigned int line_number;
	int number;
	char *buffer, *code;
	stack_t *head;
	FILE *fp;


	number = size = line_number = 0;
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
		if (strcmp("push", code) == 0)
			number = atoi(strtok(NULL, " \t"));
		execute(&head, line_number, code, number);
	}
	free_list(head);
	free(buffer);
	return (0);
}
