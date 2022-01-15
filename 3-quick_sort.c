#include "sort.h"
/**
* quick_sort - function that sorts an array
* of integers in ascending order using the quick sort algorithm.
* @array: input arrray
* @size: size of the array
* Return: no return
*/
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
/**
 * _qsort - auxiliary function for the quick_sort fnc
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, int low, int high, int size)
{
	int t, p, i;
	int tmp;

	if (low < high)
	{
		t = high;
		p = low;
		for (i = low; i < high; i++)
		{
			if (a[i] < a[t])
			{
				if (i != p)
				{
					tmp = a[i];
					a[i] = a[p];
					a[p] = tmp;
					print_array(a, size);
				}
				p++;
			}
		}
		if (p != t && a[p] != a[t])
		{
			tmp = a[p];
			a[p] = a[t];
			a[t] = tmp;
			print_array(a, size);
		}
		_qsort(a, low, p - 1, size);
		_qsort(a, p + 1, high, size);
	}
}
