#include "main.h"
#include <stdlib.h>

/**
 * _strdup -  function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter
 * @str : The string to duplicate
 * 
 * Return: The string duplicated
 */

char *_strdup(char *str)
{
	int a = 0, i = 1;
	char *S;

	if (str == NULL)
		return (NULL);

	while (str[i])
	{
		i++;
	}

	S =  malloc((sizeof(char) * i )+ 1);

	if (S == NULL)
		return (NULL);

	while (a < 1)
	{
		S[a] = str[a];
		
		a++;
	}

	S[a] = '\0';
	return (S);
}
