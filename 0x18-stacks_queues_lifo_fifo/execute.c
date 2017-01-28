#include "monty.h"

/**
 * execute - execute the opcode's corresponding function
 *
 * @code: bytecode to execute
 *
 * @number: number to push if opcode is push
 *
 * Return: void
 */
int execute(stack_t **head, unsigned int line_number, char *code, int number)
{
	int i;
	instruction_t opcodes[] = {
		{"pall", pall_op}, {"pint", pint_op},
		{"pop", pop_op}, {"swap", swap_op},
		{"add", add_op}, {"nop", nop_op},
		{"sub", sub_op}, {"div", div_op},
		{"mul", mul_op}, {"mod", mod_op},
		{"pchar", pchar_op}, {"pstr", pstr_op},
		{"rotl", rotl_op}, {"rotr", rotr_op},
		{"stack", stack_op}, {"queue", queue_op},
		{NULL, NULL}
	};

	for (i = 0; code[i]; i++)
		if (code[i] == '#')
			return (0);
	if (strcmp(code, "push") == 0)
	{
		push_op(head, number, line_number);
		return (0);
	}
	else
		(void) number;
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(code, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(head, line_number);
			return (0);
		}
	}
	printf("%d: unknown instruction %s\n", line_number, code);
	exit(EXIT_FAILURE);
}
