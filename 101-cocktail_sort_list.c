#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps a node with its previous node in a doubly linked list.
 * @node: The node to swap.
 * @list: Pointer to the head of the doubly linked list.
 * Return: Pointer to the swapped node.
 */
listint_t *swap_nodes(listint_t *node, listint_t **list)
{
	listint_t *previous_node = node->prev; /* Node before the current one */
	listint_t *current_node = node; /* The node to be swapped */

	previous_node->next = current_node->next; /* Update the next pointer */
	if (current_node->next)
	{
		/* Update the previous pointer of the following node */
		current_node->next->prev = previous_node;
	}

	current_node->next = previous_node; /* Swap the nodes */
	/* Connect to the previous previous node */
	current_node->prev = previous_node->prev;
	/* Update the previous node's previous pointer */
	previous_node->prev = current_node;

	if (current_node->prev)
	{
		/* Connect to the previous node's next */
		current_node->prev->next = current_node;
	}
	else
	{
		/* Update the list head if swapped node becomes the first */
		*list = current_node;
	}

	return (current_node); /* Return the swapped node */
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the
 * cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node; /* Pointer to the current node in the list */
	int swaps_made = 1; /* Flag to indicate if swaps were made in a pass */

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		/* Return if the list is null, empty, or has only one element */
		return;
	}

	/* Loop until no swaps are made in a full pass (both directions) */
	for (; swaps_made;)
	{
		swaps_made = 0; /* Reset flag to detect if swaps are made in this pass */
		current_node = *list; /* Start from the beginning */
		/* Forward pass to sort the list */
		for (; current_node->next; current_node = current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				current_node = swap_nodes(current_node->next, list);
				swaps_made = 1; /* Indicate a swap was made */
				print_list(*list); /* Optional: print the list after each swap */
			}
		}
		if (swaps_made == 0)
			break; /* If no swaps were made, sorting is complete */

		swaps_made = 0; /* Reset flag for the backward pass */

		/* Backward pass to sort the list */
		for (; current_node->prev; current_node = current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				current_node = swap_nodes(current_node, list); /* Swap if out of order */
				swaps_made = 1; /* Indicate a swap was made */
				print_list(*list); /* Optional: print the list after each swap */
			}
		}
	}
}

