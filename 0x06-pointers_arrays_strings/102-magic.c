#include <stdio.h>

/**
 * main - Entry point
 * 
 * Return: Always 0 (Success)
 */
int main(void)
{
    int a[5] = {0, 1, 98, 3, 4};
    int *p;

    p = &a[2];

    printf("a[2] = %d\n", *(p + 2));

    return (0);
}
