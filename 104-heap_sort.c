#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @a: first element
 * @b: second element
 **/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - puts the array in max heap order
 * @array: array of integers
 * @size: size of the array
 * @index: root index
 * @len: original size of the array
 **/
void heapify(int *array, int size, int index, int len)
{
	int left, right, largest;

	left = 2 * index + 1;
	right = 2 * index + 2;
	largest = index;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, len);
		heapify(array, size, largest, len);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using heap sort
 * @array: array of integers
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
