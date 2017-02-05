#include "hash_tables.h"

/**
 * hash_table_get - retrieve the value of the associated @key
 *
 * @ht: hash table
 * @key: key string
 *
 * Return: value found for @key string
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current;
	unsigned long int index;

	if (ht == NULL)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] == NULL)
		return (NULL);
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
