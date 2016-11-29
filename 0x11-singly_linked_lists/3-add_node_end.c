#include "lists.h"

/**
 * add_node_end - add a new node at the end of a linked list
 * @head: pointer to beginning of linked list
 * @str: string to add to linked list
 *
 * Return: pointer to new element; NULL if failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	int i;
	list_t *new, *conduit;

	for (i = 0; str[i] != 0; i++)
		;
	if (*head == NULL)
	{
		new = malloc(sizeof(list_t));
		if (new == NULL)
			return (NULL);
		new->next = 0;
		new->str = strdup(str);
		new->len = i;
		*head = new;

		return (new);
	}
	conduit = *head;
	while (conduit->next != 0)
		conduit = conduit->next;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = i;
	new->next = 0;
	conduit->next = new;

	return (conduit);
}
