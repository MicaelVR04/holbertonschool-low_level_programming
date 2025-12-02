#include "hash_tables.h"

/**
 * _create_node - creates a hash node with duplicated key/value
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *_create_node(const char *key, const char *value)
{
	hash_node_t *node;
	char *key_dup, *val_dup;

	val_dup = strdup(value);
	if (!val_dup)
		return (NULL);

	node = malloc(sizeof(hash_node_t));
	if (!node)
	{
		free(val_dup);
		return (NULL);
	}

	key_dup = strdup(key);
	if (!key_dup)
	{
		free(val_dup);
		free(node);
		return (NULL);
	}

	node->key = key_dup;
	node->value = val_dup;
	node->next = NULL;

	return (node);
}

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: hash table
 * @key: key (non-empty)
 * @value: value (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *cur, *node;

	if (!ht || !key || !*key || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			free(cur->value);
			cur->value = strdup(value);
			if (!cur->value)
				return (0);
			return (1);
		}
		cur = cur->next;
	}

	node = _create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}
