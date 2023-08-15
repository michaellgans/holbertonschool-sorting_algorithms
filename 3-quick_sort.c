#include "sort.h"

/**
 * lomuto_partition - partitions the array
 * @array: to be sorted
 * @low: lower limit
 * @high: upper limit
 * @size: size of array
 * Return: 0/1
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1;

	for (int y = low; y <= high - 1; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				/* Swap elements */
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}

	if ((x + 1) != high)
	{
		/* Swap elements */
		swap(&array[x + 1], &array[high]);
		print_array(array, size);
	}
	return (x + 1);
}

/**
 * swap - swaps stuff
 * @a: first int
 * @b: second int
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_recursive - sorts quickly
 * @array: to be sorted
 * @low: lower limit
 * @high: upper limit
 * @size: size of array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int z = lomuto_partition(array, low, high, size);

		/* Recursively sort subarrays */
		quick_sort_recursive(array, low, z - 1, size);
		quick_sort_recursive(array, z + 1, high, size);
	}
}

/**
 * quick_sort - sorts quickly again?
 * @array: to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	/* Call recursive Quick Sort function */
	quick_sort_recursive(array, 0, size - 1, size);
}
