#include "sort.h"

void swap(int *array, int a, int b);
int partition(int *array, int lo, int hi, size_t size);
void quicksort(int *array, int lo, int hi, size_t size);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap - Swaps two elements in an array
 * @array: Array containing the elements
 * @a: Index of the first element to swap
 * @b: Index of the second element to swap
 */
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: Array to sort
 * @lo: Starting index of the array
 * @hi: Ending index of the array
 * @size: Size of the array
 *
 * Return: Index of the partition
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[hi])
	{
		swap(array, i + 1, hi);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers in ascending order using the
 * quicksort algorithm with Lomuto partition scheme
 * @array: Array to sort
 * @lo: Starting index of the array
 * @hi: Ending index of the array
 * @size: Size of the array
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 * quicksort algorithm with Lomuto partition scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
