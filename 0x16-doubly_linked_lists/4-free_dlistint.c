#include "lists.h"

/**
 * free_dlistint - free a doubly linked list from memory
 *
 * @head: list head
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *walker, *tmp;

	walker = head;
	while (walker->next != NULL)
		walker = walker->next;
	while (walker != NULL)
	{
		tmp = walker;
		walker = walker->prev;
		free(tmp);
	}
}
