#include "lists.h"

/**
 * pop_listint - delete the head node of a listint_t linked list
 * @head: start of linked list
 *
 * Return: data stored in head node
 */
int pop_listint(listint_t **head)
{
	int i;
	listint_t *current;

	i = 0;
	if (*head != NULL)
	{
		current = *head;
		i = current->n;
		*head = (*head)->next;
		free(current);
	}
	return (i);
}
