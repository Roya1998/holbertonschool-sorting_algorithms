#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @array: array of integers
 * @item1: first index
 * @item2: second index
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
    int tmp;

    tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array of integers
 * @first: starting index
 * @last: ending index
 * @size: size of array
 *
 * Return: pivot position
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
 * qs - recursive quicksort
 * @array: array of integers
 * @first: starting index
 * @last: ending index
 * @size: array size
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