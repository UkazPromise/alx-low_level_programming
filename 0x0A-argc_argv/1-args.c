#include <stdio.h>

/**
 * main - print the number of arguments passed to the program (excluding program name)
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
    if (argc > 1) {
        printf("%d\n", argc - 1);
    } else {
        printf("No additional arguments.\n");
    }

    return 0;
}
