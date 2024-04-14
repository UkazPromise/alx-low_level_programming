#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers,
 * using the Binary search algorithm
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located, or -1 if not found
**/
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1;

    if (!array)
        return (-1);

    while (right >= left)
    {
        size_t mid = left + (right - left) / 2;
        size_t i;

        printf("Searching in array: ");
        for (i = left; i < right; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[right]);

        if (array[mid] == value)
            return (mid);

        if (array[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return (-1);
}
