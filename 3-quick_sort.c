#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: array of integers
 * @item1: index of first element
 * @item2: index of second element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: array of integers
 * @first: starting index of the partition
 * @last: ending index of the partition (pivot index)
 * @size: total size of the array
 *
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	return (current);
}

/**
 * qs - recursive helper for quick sort
 * @array: array of integers
 * @first: starting index of the subarray
 * @last: ending index of the subarray
 * @size: total size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort
 * @array: array of integers
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs(array, 0, size - 1, size);
}
