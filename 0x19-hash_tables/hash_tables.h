#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * hash_node_s - node of hash value to avoid collision
 *
 * @key : The key, string
 * @value : The value corresponding to a key
 * @next : A pointer to the next node of the list
 *
 * Description: This is a node to a value with each node being a unique key
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * hash_table_s - hash table array structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 *
 * Description: Each cell of this array is a pointer to the first node of a
 * linked list, because we want our HashTable to use a Chaining collision
 * handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* Functions */
hash_table_t *hash_table_create(unsigned long int size);
hash_node_t *add_node(hash_node_t **head);

#endif
