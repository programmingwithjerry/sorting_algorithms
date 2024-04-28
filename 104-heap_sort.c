#include "sort.h"

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: Pointer to the array to sort.
 * @array_size: Total size of the array.
 */
void heap_sort(int *array, size_t array_size)
{
	int last_index; /* Index for traversing the heap */
	int temp; /* Temporary variable for swapping elements */

	/* Build the initial max heap */
	for (last_index = array_size / 2 - 1; last_index >= 0; last_index--)
	{
		/* Heapify from the middle downwards */
		heapify(array, last_index, last_index, array_size);
	}

	/* Extract elements from the heap and rebuild the heap */
	for (last_index = array_size - 1; last_index >= 0; last_index--)
	{
		/* Swap the root with the last element in the heap */
		temp = array[0];
		array[0] = array[last_index];
		array[last_index] = temp;
		/* Optional: print the array after each swap */
		print_array(array, array_size);

		/* Re-heapify the reduced heap */
		heapify(array, last_index, 0, array_size);
	}
}

/**
 * heapify - Ensures the subtree rooted at a given index is a max heap.
 * @array: Pointer to the array.
 * @heap_size: Current size of the heap.
 * @root_index: Index of the root node of the subtree.
 * @array_size: Total size of the array.
 */
void heapify(int *array, int heap_size, int root_index, size_t array_size)
{
	int largest = root_index; /* Initially assume the root is the largest */
	int left_child = 2 * root_index + 1; /* Left child index */
	int right_child = 2 * root_index + 2; /* Right child index */
	int temp; /* Temporary variable for swapping elements */

	/* If the left child exists and is greater than the root, update largest */
	if (left_child < heap_size && array[left_child] > array[largest])
	{
		largest = left_child;
	}

	/*If the right child exists and is greater than the largest, update largest*/
	if (right_child < heap_size && array[right_child] > array[largest])
	{
		largest = right_child;
	}

	/* If the root is not the largest, swap and recursively heapify */
	if (largest != root_index)
	{
		temp = array[root_index];
		array[root_index] = array[largest];
		array[largest] = temp;
		/* Optional: print the array after swapping */
		print_array(array, array_size);
		/* Recursively heapify the affected subtree */
		heapify(array, heap_size, largest, array_size);
	}
}

