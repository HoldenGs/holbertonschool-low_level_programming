#include "lists.h"

/**
 * add_node - add a new node to the beginning of a linked list
 * @head: pointer to beginning of list
 * @str: string to add
 *
 * Return: pointer to new element
 */
list_t *add_node(list_t **head, const char *str)
{
	int i;
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	for (i = 0; str[i] != 0; i++)
		;
	new->len = i;
	new->next = *head;
	*head = new;

	return (*head);
}
