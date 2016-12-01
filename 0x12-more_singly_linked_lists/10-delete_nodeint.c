#include "lists.h"

/**
 * delete_nodeint_at_index - delete a node from a linked list at @index
 * @head: linked list
 * @index: position of node to delete
 *
 * Return: 1 if success; -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *afternode, *beforenode, *delete, *current;

	current = *head;
	if (current == NULL)
		return (-1);
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}
	for (i = 0; (i + 1) < index; i++)
	{
		if (current == NULL)
			return (-1);
		current = current->next;
	}
	beforenode = current;
	current = current->next;
	if (current == NULL)
		return (-1);
	afternode = current->next;
	beforenode->next = afternode;
	delete = current;
	free(delete);
	return (1);
}
