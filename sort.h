#ifndef _SORT_H
#define _SORT_H


#include <stddef.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print Functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

void quicksort_recursive(int *array, ssize_t start, ssize_t end, int array_size);
int hoare_partition(int *array, int start, int end, int array_size);
void my_swaps(int *array, ssize_t first_index, ssize_t second_index);
void bitoSort(int array[], int start, int elCout, int isAscend, int array_size);
void merge_sequences(int array[], int start, int elCout, int isAscend);
void elements_swap(int array[], int index1, int index2, int isAscend);
void count_sort(int *array, size_t size, int exp, int *temp_array);
void swap_elements(int *first, int *second);
void heapify(int *array, int heap_size, int root_index, size_t array_size);
void merge_arrays(int *array, int *temp_array, int start, int middle, int end);
void *allocate_and_init(unsigned int element_count, unsigned int element_size);
void *calloc_custom(unsigned int num_elements, unsigned int element_size);
void swap(int *array, int first_index, int second_index);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);


#endif
