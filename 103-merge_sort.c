#include "sort.h"

/**
 * merge - Merges two subarrays of array
 *
 * @array: Array to be merged
 * @tmp: Temporary array to store the merge result
 * @l_idx: Starting index of the left subarray
 * @m_idx: Ending index of the left subarray (exclusive)
 * @r_idx: Ending index of the right subarray (exclusive)
 */
void merge(int *array, int *tmp, size_t l_idx, size_t m_idx, size_t r_idx)
{
	size_t i = l_idx, j = m_idx, k = l_idx;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l_idx, m_idx - l_idx);

	printf("[right]: ");
	print_array(array + m_idx, r_idx - m_idx);

	while (i < m_idx && j < r_idx)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	while (i < m_idx)
		tmp[k++] = array[i++];

	while (j < r_idx)
		tmp[k++] = array[j++];

	for (i = l_idx; i < r_idx; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array + l_idx, r_idx - l_idx);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	int tmp[100000];

	if (size < 2 || array == NULL)
		return;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, tmp, 0, mid, size);
}
