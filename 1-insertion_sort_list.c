#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a the doubly-linked list
 * @h: pointer to the head of the list
 * @node1: pointer to the first node to swap
 * @node2: pointer to the second node to swap
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using insertion sort algorithm.
 * @list: pointer to the head of a the list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL && iterator->n < insert->n)
		{
			swap_nodes(list, &insert, iterator);
			print_list((const listint_t *)*list);
		}
	}
}
