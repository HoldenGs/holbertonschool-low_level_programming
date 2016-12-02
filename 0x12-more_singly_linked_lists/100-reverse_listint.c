#include "lists.h"

/**
 * reverse_listint - reverse a linked list
 * @head: linked list
 *
 * Return: pointer to first node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *prev;

	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		*head = current->next;
		current->next = prev;
		prev = current;
		current = *head;
	}
	*head = prev;
	return (*head);
}
