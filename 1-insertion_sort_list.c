#include "sort.h"

/**
 * swap_nodes - awap two adjacent nodes in a doubly linked list
 * @list: double pointer to a linked list
 * @node1: pointer to first node
 * @node2: poiinter to second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	/* Update next pointer of node1's previous node */
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	/* Update previous pointer of node2's next node */
	if (node2->next != NULL) /* if not null */
		node2->next->prev = node1;

	/* Update previous and next pointers of node1 and node2 */
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: double pointer to a linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (list == NULL || *list == NULL || (*list)->next == NULL) /*single/empty*/
		return;

	/* set current to the 2nd node in the list */
	current = (*list)->next;
	while (current != NULL)
	{
		/* save a reference to the previous node */
		previous = current->prev;

		/* check if current node is smaller than previous */
		while (previous != NULL && current->n < previous->n)
		{
			swap_nodes(list, previous, current);

			/* update the previous reference */
			previous = current->prev;

			/* print current state of the list */
			print_list(*list);
		}

		current = current->next;
	}
}
