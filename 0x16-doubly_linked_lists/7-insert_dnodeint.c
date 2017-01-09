#include "lists.h"

/**
 * insert_dnodeint_at_index - insert a new node in a doubly linked list
 *
 * @h: list head
 * @idx: position in list
 * @n: node data
 *
 * Return: new node; NULL if failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *walk, *new;
	unsigned int i;

	if (*h != NULL)
	{
		walk = *h;
		for (i = 0; walk != NULL; i++)
		{
			if (i == idx)
			{
				new = malloc(sizeof(dlistint_t));
				if (new == NULL)
					return (NULL);
				new->n = n;
				new->next = walk;
				new->prev = walk->prev;
				if (walk->prev != NULL)
				{
					walk = walk->prev;
					walk->next = new;
				}
				else
					*h = new;
				walk = new->next;
				walk->prev = new;
				return (new);
			}
			walk = walk->next;
		}
	}
	if (i == idx)
		return (add_node(h, walk, n));
	return (NULL);
}

/**
 * add_node - adds a node to the correspond position of @w in a linked list
 *
 * @h: list head
 * @w: current node
 * @n: data
 *
 * Return: new node; NULL if failure
 */
dlistint_t *add_node(dlistint_t **h, dlistint_t *w, int n)
{

	dlistint_t *new, *walk;

	walk = w;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*h != NULL)
	{
		walk = *h;
		if (walk != NULL)
			while (walk->next != NULL)
				walk = walk->next;
		walk->next = new;
		new->prev = walk;
	}
	else
	{
		*h = new;
		new->prev = NULL;
	}
	return (new);
}
