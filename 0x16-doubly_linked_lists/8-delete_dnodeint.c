#include "lists.h"

/**
 * delete_dnodeint_at_index - delete a node in a doubly linked list at @index
 *
 * @head: list head
 * @index: position of node
 *
 * Return: 1 if success; -1 if failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *walker, *tmp;
	unsigned int i;

	if (*head != NULL)
	{
		walker = *head;
		for (i = 0; walker != NULL; i++)
		{
			if (i == index)
			{
				tmp = walker;
				if (tmp->prev != NULL)
				{
					walker = walker->prev;
					walker->next = tmp->next;
				}
				else
					*head = tmp->next;
				if (tmp->next != NULL)
				{
					walker = tmp->next;
					walker->prev = tmp->prev;
				}
				free(tmp);
				return (1);
			}
			walker = walker->next;
		}
	}
	return (-1);
}
