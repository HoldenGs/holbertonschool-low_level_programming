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
	listint_t *node, *tmp, *current;

	current = *head;
	for (i = 0; (i + 1) < index; i++)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
	}
	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	tmp = current->next;
	current->next = node;
	node->next = tmp;
	return (node);
}
