#include "lists.h"

/**
 * free_listint2 - free a listint_t linked list and set the @head to NULL
 * @head: linked list start point
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}
