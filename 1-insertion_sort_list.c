#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm.
 *
 * @head: Pointer to a pointer to the head of the doubly linked list.
 * Return: void
 */
void insertion_sort_list(listint_t **head)
{
	listint_t *current_node; /* Pointer to the current node being checked */
	listint_t *next_node; /* Temporary pointer for the node to be swapped */

	if (!head || !*head)
	{
		return;
	}
	current_node = *head;
	while (current_node)
	{
		while (current_node->next && (current_node->n > current_node->next->n))
		{
			next_node = current_node->next; /* Set the node to swap with current */
			current_node->next = next_node->next; /* Connect to the following node */
			next_node->prev = current_node->prev; /* Connect to the previous node */
			if (current_node->prev)
			{
				current_node->prev->next = next_node;
			}
			else
			{
				*head = next_node;
			}
			if (next_node->next)
			{
				next_node->next->prev = current_node;
			}
			current_node->prev = next_node;
			next_node->next = current_node;
			if (next_node->prev)
			{
				current_node = next_node->prev;
			}
			else
			{
				current_node = next_node;
			}
			print_list(*head); /* Optional: print the current state of the list */
		}
		current_node = current_node->next;
	}
}

