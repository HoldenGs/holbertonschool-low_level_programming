#include "lists.h"

/**
 * get_nodeint_at_index - return the @index node in a listint_t linked list
 * @head: linked list
 * @index: (n - 1)th place in linked list
 *
 * Return: node at @index; NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
