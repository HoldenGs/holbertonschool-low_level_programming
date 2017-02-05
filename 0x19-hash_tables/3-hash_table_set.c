#include "hash_tables.h"

/**
 * hash_table_set - set a key hash value node with the @key and @value in @ht
 *
 * @ht: hash table
 * @key: key string
 * @value: value string
 *
 * Return: 1 if success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;

	index = key_index((unsigned char *)key, ht->size);
	/* make linked list node */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[index];
	ht->array[index] = node;
	return (1);
}
