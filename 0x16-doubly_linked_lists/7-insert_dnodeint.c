#include "lists.h"

/**
 * insert_dnodeint_at_idx - insert a new node in a doubly linked list at @index
 *
 * @head: list head
 * @idx: position in list
 * @n: node data
 *
 * Return: new node; NULL if failure
 */
dlistint_t *insert_dnodeint_at_idx(dlistint_t **head, unsigned int idx, int n)
{
	dlistint_t *new, *walk;
	unsigned int i;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*head != NULL)
		walk = *head;
		for (i = 0; walk != NULL; i++)
		{
			if (i == idx)
			{
				new->next = walk;
				new->prev = walk->prev;
				if (walk->prev != NULL)
				{
					walk = walk->prev;
					walk->next = new;
				}
				else
					*head = new;
				walk = new->next;
				walk->prev = new;
				return (new);
			}
			walk = walk->next;
		}
	return (NULL);
}
