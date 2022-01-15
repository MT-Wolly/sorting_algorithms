#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 * @array: input array of integers
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, n;

	for (i = 0; i < size; i++)
	{
		n = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[n] > array[j])
				n = j;
		}

		if (i != n)
		{
			tmp = array[i];
			array[i] = array[n];
			array[n] = tmp;
			print_array(array, size);
		}
	}
}
