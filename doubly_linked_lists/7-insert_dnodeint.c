#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the pointer of the head of the list
 * @idx: index to insert the new node at (starts at 0)
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp, *new_node;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* Insert at beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* Traverse to the node before the insertion point */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If index out of range */
	if (temp == NULL)
		return (NULL);

	/* Insert at the end if next is NULL */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Insert in the middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = temp;
	new_node->next = temp->next;

	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
