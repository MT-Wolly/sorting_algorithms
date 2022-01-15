#include "sort.h"
#include <stdio.h>
/**
 * swap_nums - swaps numbers
 * @arr: input array
 * @a: first index
 * @b: second index
 * Return: no return
 */
void swap_nums(int *arr, int a, int b)
{
	arr[a] = arr[a] + arr[b];
	arr[b] = arr[a] - arr[b];
	arr[a] = arr[a] - arr[b];
}

/**
 * recursion_heap - recursion that builds the max heap tree
 * @arr: input array
 * @i: index number
 * @size: size of the array
 * @limit: limit of the array
 * Return: no return
 */
void recursion_heap(int *arr, int i, size_t size, int limit)
{
	int big;
	int te;

	te = i * 2;

	if (te + 2 < limit)
	{
		recursion_heap(arr, te + 1, size, limit);
		recursion_heap(arr, te + 2, size, limit);
	}

	if (te + 1 >= limit)
		return;

	if (te + 2 < limit)
		big = (arr[te + 1] > arr[te + 2]) ? (te + 1) : (te + 2);
	else
		big = te + 1;

	if (arr[i] < arr[big])
	{
		swap_nums(arr, i, big);
		print_array(arr, size);
		recursion_heap(arr, big, size, limit);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @array: input array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t limit;

	if (!array || size == 0)
		return;

	i = 0;
	limit = size;

	while (limit > 1)
	{
		recursion_heap(array, i, size, limit);
		if (array[i] >= array[limit - 1])
		{
			swap_nums(array, i, limit - 1);
			print_array(array, size);
		}
		limit--;
	}
}
