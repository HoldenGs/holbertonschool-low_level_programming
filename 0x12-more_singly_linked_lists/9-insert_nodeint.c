#include "lists.h"

/**
 * insert_nodeint_at_index - insert a node at given position in a linked list
 * @head: linked list
 * @index: position in list to add node, startin at 0
 * @n: data to add
 *
 * Return: pointer to added node; NULL if failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	unsigned int i;
	listint_t *current, *before, *new;

	i = 0;
	current = *head;
	if (i == index)
	{
		new = malloc(sizeof(listint_t));
		new->n = n;
		new->next = current;
		current = new;
		return (new);
	}
	while (i < index)
	{
		if (current == NULL)
			return (NULL);
		before = current;
		current = current->next;
		i++;
	}
	new = malloc(sizeof(listint_t));
	new->n = n;
	new->next = current;
	before->next = new;
	return (new);
}
