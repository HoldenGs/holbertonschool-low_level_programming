#include "lists.h"

/**
 * get_dnodeint_at_index - get a doubly linked list node at @index position
 *
 * @head: list head
 * @index: location in list of node
 *
 * Return: node location; NULL if failure
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head != NULL; i++)
	{
		if (i == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}
