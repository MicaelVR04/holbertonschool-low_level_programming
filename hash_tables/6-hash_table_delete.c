#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table and frees all memory
 * @ht: hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur, *tmp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		cur = ht->array[i];
		while (cur)
		{
			tmp = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			cur = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
