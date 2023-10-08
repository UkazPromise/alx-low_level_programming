#include <stdio.h>

/**
 * main - print the name of the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{	
    if (argc > 0)
    {
        printf("%s\n", argv[0]);
        return (0);
    }
    else
    {
	fprintf(stderr, "Usage: %s\n", argv[0]);
       	return (1);
    }
}

