#include "monty.h"

/**
 * push - add a node to the start of a doubly linked list
 *
 * @head: list head
 * @n: integer data
 *
 * Return: 0
 */
void push_op(stack_t **head, int n)
{
	stack_t *new;

	new = smart_alloc(sizeof(stack_t));
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

/**
 * pall - prints a doubly linked list
 *
 * @h: list head
 *
 * Return: void
 */
void pall_op(stack_t **head, unsigned int line_number)
{
	stack_t *node;
	size_t i;

	(void)line_number;
	node = *head;
	for (i = 0; node != NULL; i++)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

void pint_op(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

void pop_op(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

void swap_op(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
