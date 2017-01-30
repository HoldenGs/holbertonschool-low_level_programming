#include "monty.h"

/**
 * push_op - add a node to the start of a doubly linked list
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
 * pall_op - prints a doubly linked list
 *
 * @head: list head
 * @line_number: the line of access
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
/**
 * pint_op - prints first element of doubly linked list
 *
 * @head: list head
 * @line_number: line of access
 *
 * Return: void
 */
void pint_op(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_op - removes top element of a doubly linked list
 *
 * @head: the list
 * @line_number: line of access
 *
 * Return: void
 *
 */
void pop_op(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(current);
	}
	else
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

}
/**
 * swap_op - swaps top two elements of doubly linked list
 *
 * @head: the list
 * @line_number: line of access
 *
 * Return: void
 */
void swap_op(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *hold;
	int holder;

	if (*head != NULL && (*head)->next != NULL)
	{
		temp = *head;
		hold = temp->next;
		holder = temp->n;
		temp->n = hold->n;
		hold->n = holder;
	}
	else
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
