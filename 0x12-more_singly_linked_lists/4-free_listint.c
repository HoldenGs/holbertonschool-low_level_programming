#include "lists.h"

/**
 * free_listint - free a listint_t linked list
 * @head: linked list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
