#include "lists.h"

/**
 * add_nodeint_end - add a new node to the end of a listint_t linked list
 * @head: pointer to start of linked list
 * @n: number to add to node
 *
 * Return: pointer to new node; NULL if failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node, *current;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
	return (current);
}
