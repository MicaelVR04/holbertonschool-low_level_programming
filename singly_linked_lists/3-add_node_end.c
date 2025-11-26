#include <string.h>
#include "lists.h"

/**
 * create_node - creates a new list_t node duplicating a given string.
 * @str: string to duplicate; can be NULL.
 *
 * Return: pointer to the new node, or NULL on failure.
 */
static list_t *create_node(const char *str)
{
	list_t *node;
	unsigned int len = 0;

	node = (list_t *)malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	if (str != NULL)
	{
		node->str = strdup(str);
		if (node->str == NULL)
		{
			free(node);
			return (NULL);
		}
		while (node->str[len] != '\0')
			len++;
		node->len = len;
	}
	else
	{
		node->str = NULL;
		node->len = 0;
	}

	node->next = NULL;
	return (node);
}

/**
 * find_tail - returns the last node of a list_t list.
 * @head: pointer to the first node.
 *
 * Return: pointer to the last node, or NULL if head is NULL.
 */
static list_t *find_tail(list_t *head)
{
	if (head == NULL)
		return (NULL);

	while (head->next != NULL)
		head = head->next;

	return (head);
}

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: address of the pointer to the head of the list.
 * @str: string to duplicate and store in the new node.
 *
 * Return: address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *tail;

	if (head == NULL)
		return (NULL);

	new_node = create_node(str);
	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	tail = find_tail(*head);
	tail->next = new_node;
	return (new_node);
}
