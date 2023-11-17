#include "sort.h"
/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}
