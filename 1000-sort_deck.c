#include "deck.h"

/**
 * compare_strings - Compares two strings and returns
 * the difference in ASCII values.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: Positive if str1 > str2, zero if they are equal,
 * negative if str1 < str2.
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2); /* Difference in ASCII values */
}

/**
 * get_card_value - Get the numerical value of a card.
 * @card_node: Pointer to a deck node representing the card.
 *
 * Return: The numerical value of the card.
 */
int get_card_value(deck_node_t *card_node)
{
	if (compare_strings(card_node->card->value, "Ace") == 0)
		return (1); /* Ace is often represented as 1 */
	if (compare_strings(card_node->card->value, "10") == 0)
		return (10);
	if (compare_strings(card_node->card->value, "Jack") == 0)
		return (11);
	if (compare_strings(card_node->card->value, "Queen") == 0)
		return (12);
	if (compare_strings(card_node->card->value, "King") == 0)
		return (13);

	/* If not a face card, return the numerical value */
	return (card_node->card->value[0] - '0');
}

/**
 * insertion_sort_deck_by_suit - Sort a deck by suit (from spades to diamonds).
 * @deck_head: Pointer to the head of a deck_node_t doubly linked list.
 */
void insertion_sort_deck_by_suit(deck_node_t **deck_head)
{
	deck_node_t *current, *previous, *next_card;

	for (current = (*deck_head)->next; current != NULL; current = next_card)
	{
		next_card = current->next;
		previous = current->prev;

		while (previous != NULL && previous->card->kind > current->card->kind)
		{
			previous->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = previous;
			}
			current->prev = previous->prev;
			current->next = previous;
			if (previous->prev != NULL)
			{
				previous->prev->next = current;
			}
			else
			{
				*deck_head = current; /* Update the head if needed */
			}
			previous->prev = current;
			previous = current->prev;
		}
	}
}

/**
 * insertion_sort_deck_by_value - Sort a deck by value
 * (from ace to king, and then by suit).
 * @deck_head: Pointer to the head of a deck_node_t doubly linked list.
 */
void insertion_sort_deck_by_value(deck_node_t **deck_head)
{
	deck_node_t *current, *previous, *next_card;

	for (current = (*deck_head)->next; current != NULL; current = next_card)
	{
		next_card = current->next;
		previous = current->prev;

		while (previous != NULL &&
		       previous->card->kind == current->card->kind &&
		       get_card_value(previous) > get_card_value(current))
		{
			previous->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = previous;
			}
			current->prev = previous->prev;
			current->next = previous;
			if (previous->prev != NULL)
			{
				previous->prev->next = current;
			}
			else
			{
				*deck_head = current; /* Update the head if needed */
			}
			previous->prev = current;
			previous = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards by suit and then by value.
 * @deck_head: Pointer to the head of a deck_node_t doubly linked list.
 */
void sort_deck(deck_node_t **deck_head)
{
	if (deck_head == NULL || *deck_head == NULL || (*deck_head)->next == NULL)
	{
		/* No sorting needed if the deck is empty or has only one card */
		return;
	}

	insertion_sort_deck_by_suit(deck_head); /* Sort by suit first */
	insertion_sort_deck_by_value(deck_head); /* Then sort by value */
}

