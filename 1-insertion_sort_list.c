#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the insertion sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current; /* Pointer to the current node in the list */
	listint_t *temp; /* Temporary pointer for swapping */

	if (!list || !*list)
	{
		/* If the list is null or empty, return without sorting */
		return;
	}
	/* Start at the second node and loop through the list */
	for (current = (*list)->next; current; current = current->next)
	{
		/* While the current node is smaller than the previous one, swap them */
		for (; current->prev && (current->prev->n > current->n);)
		{
			temp = current->prev;
			/* Adjust the links for the swap */
			if (temp->prev)
			{
				temp->prev->next = current;
			}
			else
			{
				/* Current becomes the new head if temp has no previous node */
				*list = current;
			}
			if (current->next)
			{
				current->next->prev = temp;
			}
			/* Perform the swap */
			current->prev = temp->prev;
			temp->prev = current;
			temp->next = current->next;
			current->next = temp;
			/* Move `current` back to check if further swapping is needed */
			current = temp;
			print_list(*list); /* Optional: print the list after each swap */
		}
	}
}

