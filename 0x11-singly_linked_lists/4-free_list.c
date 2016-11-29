#include "lists.h"

/**
 * free_list - free a linked list
 * @head: beginning of linked list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *node;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node->str);
		free(node);
	}
	free(head);
}
