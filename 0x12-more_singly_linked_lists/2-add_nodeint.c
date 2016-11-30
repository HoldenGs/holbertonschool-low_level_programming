#include "lists.h"

/**
 * add_nodeint - add a new node at the start of a listint_t linked list
 * @head: start of linked list
 * @n: number to add to node
 *
 * Return: address of new node; NULL if failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = *head;
	*head = node;
	return (node);
}
