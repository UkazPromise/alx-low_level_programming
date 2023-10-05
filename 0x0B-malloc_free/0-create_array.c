#include "main.h"
#include <stdlib.h>

/**
 * create_array -  function that creates an array of chars, and initializes it with a specific char.
 * @size: The size of the array
 * @c: The char to fill in the array
 *
 * Return: The array filed
 */

char *create_array(unsigned int size, char c)
{

	unsigned int i;
	char *S;

	if (size == 0)
		return (NULL);

	S = malloc(size * sizeof(char));

	if (S == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		S[i] = c;
	}

	return (S);
}
