#include "hash_tables.h"

/**
 * hash_table_print - print out the keys and values in the hash table @ht
 *
 * @ht: hash table
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;
	unsigned long int i;
	int flag;

	if (ht != NULL)
	{
		flag = 0;
		putchar('{');
		for (i = 0; i < ht->size; i++)
		{
			if (ht->array[i] != NULL)
			{
				current = ht->array[i];
				while (current != NULL)
				{
					if (flag != 0)
						printf(", ");
					printf("'%s': ", current->key);
					printf("'%s'", current->value);
					current = current->next;
					flag = 1;
				}
			}
		}
		printf("}\n");
	}
}
