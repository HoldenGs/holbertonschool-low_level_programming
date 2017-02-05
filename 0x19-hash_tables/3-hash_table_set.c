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

	if (key == NULL || ht == NULL)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	node = key_finder(&ht->array[index], key)
	if (node != NULL)
	{
		if (value == NULL)
			node->value = value;
		else
		{
			node->value = strdup(value);
			if (node->value == NULL)
				return (0);
		}
		return (1);
	}
	else
	{
		node = malloc(sizeof(hash_node_t));
		if (node == NULL)
			return (0);
		node->key = strdup(key);
		if (node->key == NULL)
			return (0);
		if (value == NULL)
			node->value = value;
		else
		{
			node->value = strdup(value);
			if (node->value == NULL)
				return (0);
		}
		node->next = ht->array[index];
		ht->array[index] = node;
		return (1);
	}
	return (0);
}

/**
 * key_finder - find a node with the corresponding key of @key
 *
 * @head: head of linked list
 * @key: key string
 *
 * Return: node with key if it exists, otherwise NULL
 */
hash_node_t *key_finder(hash_node_t **head, const char *key)
{
	hash_node_t *current;

	if (head == NULL)
		return (NULL);
	current = *head;
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
