#include "sort.h"

/**
 * swap - function swaps two integers in an array
 *
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - funtion partitions an array using
 * the Lomuto partition scheme
 *
 * @array: array to be partitioned
 * @low: starting index of partition
 * @high: ending index of partition
 * @size: size of array
 * Return: index of the pivot element after partition
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low - 1;

	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
		j++;
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - function sorts an array using
 * recursion and the Quick Sort algorithm
 *
 * @array: array to be sorted
 * @low: starting index of partition
 * @high: ending index of partition
 * @size: size of array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - function sorts an array of integers
 * in ascending order using Quick Sort
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	size_t low, high;

	if (array == NULL || size < 2)
		return;
	low = 0;
	high = size - 1;
	quick_sort_recursive(array, low, high, size);
}
