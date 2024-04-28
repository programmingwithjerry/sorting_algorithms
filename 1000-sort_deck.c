#include "deck.h"
#include <stdio.h>

/**
 * strings_equal - Compare two strings for equality.
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: 1 if the strings are equal, 0 otherwise.
 */
int strings_equal(const char *str1, const char *str2)
{
	size_t index = 0; /* Index for iteration */

	if (str1 == NULL)
	{
		/* If the first string is null, they can't be equal */
		return (0);
	}

	/* Compare characters until end of str1 */
	while (str1[index])
	{
		if (str1[index] != str2[index])
		{
			return (0); /* Return 0 if characters don't match */
		}
		index++;
	}

	/* If str1 has ended but str2 hasn't, they aren't equal */
	if (str1[index] == '\0' && str2[index])
	{
		return (0);
	}

	return (1); /* The strings are equal */
}

/**
 * get_card_rank - Get the card's rank based on its value and suit.
 * @card_node: Pointer to the card node.
 *
 * Return: The card's rank.
 */
int get_card_rank(deck_node_t *card_node)
{
	int rank; /* Variable to hold the card's rank */

	/* Convert the card's value to its numerical rank */
	rank = card_node->card->value[0] - '0';

	/* If the rank is not a valid number, determine its special rank */
	if (rank < 0 || rank > 9)
	{
		if (strings_equal(card_node->card->value, "Ace"))
		{
			rank = 1;
		} else if (strings_equal(card_node->card->value, "10"))
		{
			rank = 10;
		} else if (strings_equal(card_node->card->value, "Jack"))
		{
			rank = 11;
		} else if (strings_equal(card_node->card->value, "Queen"))
		{
			rank = 12;
		} else if (strings_equal(card_node->card->value, "King"))
		{
			rank = 13;
		}
	}

	/* Add the suit offset to get the final rank */
	rank += card_node->card->kind * 13;

	return (rank); /* Return the card's rank */
}

/**
 * swap_cards - Swap a card with its previous one in the deck.
 * @card_node: The card to swap.
 * @deck: Pointer to the deck.
 *
 * Return: Pointer to the card after swapping.
 */
deck_node_t *swap_cards(deck_node_t *card_node, deck_node_t **deck)
{
	deck_node_t *previous = card_node->prev; /* Previous card */
	deck_node_t *current = card_node; /* Current card */

	/* Update the next and previous pointers */
	previous->next = current->next;
	if (current->next)
	{
		current->next->prev = previous;
	}
	current->next = previous;
	current->prev = previous->prev;
	previous->prev = current;

	/* Update the deck's head if needed */
	if (current->prev)
	{
		current->prev->next = current;
	}
	else
	{
		*deck = current;
	}

	return (current); /* Return the current card after swapping */
}

/**
 *insertion_sort_deck - Sort a doubly linked deck of cards with insertion sort.
 * @deck: Pointer to the deck to sort.
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int prev_card_rank, current_card_rank; /* Card ranks for comparison */
	deck_node_t *current_node; /* Pointer to the current node */

	if (deck == NULL || (*deck)->next == NULL)
	{
		/* No sorting needed if the deck is empty or has only one card */
		return;
	}

	current_node = (*deck)->next; /* Start sorting from the second card */
	while (current_node)
	{
		if (current_node->prev)
		{
			/* Get the previous card's rank */
			prev_card_rank = get_card_rank(current_node->prev);
			/* Get the current card's rank */
			current_card_rank = get_card_rank(current_node);
		}

		/* While the previous card is greater than current card,swap them */
		while (current_node->prev && prev_card_rank > current_card_rank)
		{
			/* Swap the cards */
			current_node = swap_cards(current_node, deck);
			/* Update the previous rank */
			prev_card_rank = get_card_rank(current_node->prev);
			/* Update the current rank */
			current_card_rank = get_card_rank(current_node);
		}

		current_node = current_node->next; /* Move to the next card */
	}
}

/**
 * sort_deck - Prepare a deck for sorting with insertion sort.
 * @deck: Pointer to the deck to sort.
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck); /* Sort the deck */
}

