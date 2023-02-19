#include "sort.h"

/**
 * merge - Merges two subarrays of the given array
 *
 * @array: Array to be sorted
 * @low: Starting index of first subarray
 * @count: Size of subarrays
 * @dir: Order of sorting (ASCENDING or DESCENDING)
 */
void merge(int *array, size_t low, size_t count, int dir)
{
	size_t i, k;
	int tmp;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
		{
			if ((dir == ASCENDING && array[i] > array[i + k]) ||
				(dir == DESCENDING && array[i] < array[i + k]))
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}
		merge(array, low, k, dir);
		merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_rec - Recursive function that performs bitonic sort
 *
 * @array: Array to be sorted
 * @low: Starting index of subarray
 * @count: Size of subarray
 * @dir: Order of sorting (ASCENDING or DESCENDING)
 */
void bitonic_sort_rec(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%lu/%lu] (%s):\n", count, count,
			   (dir == ASCENDING) ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_sort_rec(array, low, k, ASCENDING);
		bitonic_sort_rec(array, low + k, k, DESCENDING);
		merge(array, low, count, dir);
		printf("Result [%lu/%lu] (%s):\n", count, count,
			   (dir == ASCENDING) ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_rec(array, 0, size, ASCENDING);
}
