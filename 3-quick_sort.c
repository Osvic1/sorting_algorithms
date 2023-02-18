#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions an array of integers using Lomuto scheme
 * @array: array of integers to partition
 * @low: lower index of partition to sort
 * @high: higher index of partition to sort
 * @size: size of the array
 *
 * Return: index of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] <= array[high])
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - sorts an array of integers in ascending order using Quick sort
 * @array: array of integers to sort
 * @low: lower index of partition to sort
 * @high: higher index of partition to sort
 * @size: size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array of integers to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
	{
		quicksort(array, 0, size - 1, size);
	}
}
