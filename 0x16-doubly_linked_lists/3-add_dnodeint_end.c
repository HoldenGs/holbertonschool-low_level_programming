#include "lists.h"

/**
 * add_dnodeint_end - add a node to the end of a doubly linked list
 *
 * @head: list head
 * @n: integer data
 *
 * Return: new node; NULL if failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *walk;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head != NULL)
	{
		walk = *head;
		if (walk != NULL)
			while (walk->next != NULL)
				walk = walk->next;
		walk->next = new;
		new->prev = walk;
	}
	else
	{
		*head = new;
		new->prev = NULL;
	}
	return (new);
}
