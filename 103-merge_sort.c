#include "sort.h"
#include <stdio.h>
/**
 * print_data - print data
 * @msg: message
 * @a: array
 * @from: from
 * @to: to
 * Return: no return
 */
void print_data(char *msg, int *a, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - Auxiliary function for merge sort algorithm
 * @a: array
 * @low: low index
 * @middle: middle
 * @high: high index
 * @buff: buffer
 * Return: no return
 */
void merge(int *a, int low, int middle, int high, int *buff)
{
	int lw, lm, i;

	lw = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	print_data("left", a, low, middle);
	print_data("right", a, middle + 1, high);

	while (lw <= middle && lm <= high)
	{
		if (a[lw] < a[lm])
			buff[i++] = a[lw++];
		else
			buff[i++] = a[lm++];
	}

	while (lw <= middle)
		buff[i++] = a[lw++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	print_data("Done", a, low, high);
}
/**
 * msort -2nd auxiliary function for merge sort algorithm
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 * Return: no return
 */
void msort(int *array, int low, int high, int *buffer)
{
	int mid;

	if (low < high)
	{
		mid = (low + high - 1) / 2;
		msort(array, low, mid, buffer);
		msort(array, mid + 1, high, buffer);
		merge(array, low, mid, high, buffer);
	}
}
/**
 * merge_sort -sorts an array of integers
 * in ascending order.
 * @array: array
 * @size: size
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	msort(array, 0, size - 1, buffer);
	free(buffer);
}
