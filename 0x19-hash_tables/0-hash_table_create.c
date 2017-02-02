#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table of @size length
 *
 * @size: size of hash table to make
 *
 * Return: pointer to hash table; or NULL if failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	hash_node_t **head;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);
	hash_table->size = size;
	head = malloc(sizeof(hash_node_t *) * size);
	hash_table->array = head;
	if (head == NULL)
		return (NULL);
	return (hash_table);
}
