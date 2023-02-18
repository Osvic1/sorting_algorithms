#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * counting sort algorithm
 * @array: The array of integers to sort
 * @size: The number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
int i, k = 0;
int *count = NULL, *output = NULL;

for (i = 0; i < (int)size; i++)
k = (array[i] > k) ? array[i] : k;
count = malloc(sizeof(int) * (k + 1));

if (count == NULL)
return;

for (i = 0; i <= k; i++)
count[i] = 0;

for (i = 0; i < (int)size; i++)
count[array[i]]++;

printf("%d", count[0]);
for (i = 1; i <= k; i++)
printf(", %d", count[i]);
printf("\n");

for (i = 1; i <= k; i++)
count[i] += count[i - 1];

output = malloc(sizeof(int) * size);
if (output == NULL)
return;

for (i = (int)size - 1; i >= 0; i--)
output[--count[array[i]]] = array[i];

for (i = 0; i < (int)size; i++)
array[i] = output[i];

free(output);
free(count);
}
