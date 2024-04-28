#include "sort.h"
#include <stdio.h>

/**
 * swap_elements - Utility function to swap two integers.
 * @first: Pointer to the first integer.
 * @second: Pointer to the second integer.
 */
void swap_elements(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}

/**
 * heapfyMax - Ensures the subtree rooted at a given index is a max-heap.
 * @array: Pointer to the array.
 * @array_size: Size of the whole array.
 * @root_index: Index of the root node of the subtree.
 * @heap_size: Current size of the heap.
 */
void heapfyMax(int *array, size_t array_size, int root_index, size_t heap_size)
{
	int largest = root_index; /* Assume root is the largest initially */
	int left_child = 2 * root_index + 1; /* Left child index */
	int right_child = 2 * root_index + 2; /* Right child index */
	/*int heap_size;*/

	/* If the left child exists and is greater than the root, update largest */
	if (left_child < (int)heap_size && array[left_child] > array[largest])
	{
		largest = left_child;
	}

	/**
	* If the right child exists and is greater than the largest so far,
	* update largest
	*/
	if (right_child < (int)heap_size && array[right_child] > array[largest])
	{
		largest = right_child;
	}

	/**
	*If root is not the largest, swap with the largest
	* and heapify recursively
	*/
	if (largest != root_index)
	{
		/* Swap the root with the largest */
		swap_elements(&array[root_index], &array[largest]);
		/* Optional: Print the array after swapping */
		print_array(array, array_size);
		/* Recursively heapify the affected subtree */
		heapfyMax(array, array_size, largest, heap_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: Pointer to the array to sort.
 * @array_size: Size of the whole array.
 */
void heap_sort(int *array, size_t array_size)
{
	int current_index; /* Index for traversing the array */

	if (array == NULL || array_size < 2)
	{
		/**
		*If the array is null or has fewer than
		* two elements, nothing to sort
		*/
		return;
	}

	/* Build a max-heap from the array */
	current_index = (array_size - 2) / 2;
	while (current_index >= 0)
	{
		heapfyMax(array, array_size, current_index, array_size);
		current_index--;
	}

	/* Extract elements from the heap and rebuild it */
	current_index = array_size - 1;
	while (current_index > 0)
	{
		/* Swap the root of the heap (largest element) with the last element */
		swap_elements(&array[0], &array[current_index]);
		/* Optional: Print the array after each swap */
		print_array(array, array_size);

		/* Reduce the heap size by one and re-heapify the root */
		heapfyMax(array, array_size, 0, current_index);
		current_index--;
	}
}

