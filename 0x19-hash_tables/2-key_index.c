#include "hash_tables.h"

/**
 * key_index - find the index of the hash value for @key
 *
 * @key: key string
 * @size: size of hash table array
 *
 * Return: index of @key's hash in hash table array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);
	if (size > 0)
		return (hash % size);
	return (0);
}
