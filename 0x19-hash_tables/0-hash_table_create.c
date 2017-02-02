#include "hash_tables.h"

/**
 *
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	hash_node_t *head, *node;
	unsigned long int i;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);
	hash_table->size = size;
	head = malloc(sizeof(hash_node_t));
	if (head == NULL)
		return (NULL);
	head->next = NULL;
	hash_table->array = &head;
	for (i = 0; i < size; i++)
	{
		node = add_node(&head);
		if (node == NULL)
			return (NULL);
	}
	return (hash_table);
}


/**
 * add_node - add a new node at the start of a listint_t linked list
 *
 * @head: start of linked list
 *
 * Return: address of new node; NULL if failure
 */
hash_node_t *add_node(hash_node_t **head)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->next = *head;
	*head = node;
	return (node);
}
