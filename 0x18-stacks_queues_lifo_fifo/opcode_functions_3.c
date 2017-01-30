#include "monty.h"

/**
 * mul_op - multiply the top of stack with the second top of stack
 *
 * @head: top of stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void mul_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		(*head)->n = (*head)->n * temp->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_op - find the remainder of top of stack divided by second top of stack
 *
 * @head: top of stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void mod_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		if ((*head)->n == 0)
		{
			printf("L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		temp = *head;
		*head = (*head)->next;
		(*head)->n = (*head)->n % temp->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar_op - print the character value of the top of stack
 *
 * @head: top of stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void pchar_op(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * pstr_op - print the ASCII value of each integer in the stack
 *
 * @head: top of stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void pstr_op(stack_t **head, unsigned int line_number)
{
	stack_t *node;
	size_t i;

	(void) line_number;
	node = *head;
	for (i = 0; node != NULL; i++)
	{
		printf("%c\n", node->n);
		node = node->next;
	}
}
/**
 * pchar_op - prints the char at the top of stack followed by new line
 *
 * @head: the list
 * @line_number: line of access
 *
 * Return: void
 *
 */
void pchar_op(stack_t **head, unsigned int line_number)
{
	char n;

	if (*head == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n >= 97 && (*head)->n <= 122) ||
	    ((*head)->n >= 65 && (*head)->n <= 90))
	{
		n = (*head)->n;
		putchar(n);
		putchar('\n');
	}
	else
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr_op - print string starting at top of stack followed by new line
 *
 * @head: the list
 * @line_number: line of access
 *
 * Return: void
 *
 */
void pstr_op(stack_t **head, unsigned int line_number)
{
	char n;
	(void) line_number;

	while (*head != NULL && (*head)->n >= 0 && (*head)->n <= 127
	       && (*head)->n != 0)
	{
		n = (*head)->n;
		putchar(n);
		(*head) = (*head)->next;
	}
	putchar('\n');
}
