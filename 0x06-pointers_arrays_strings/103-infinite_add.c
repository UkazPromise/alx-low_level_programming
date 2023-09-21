#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number as a string
 * @n2: second number as a string
 * @r: buffer to store the result
 * @size_r: size of the buffer
 *
 * Return: pointer to the result (r) or 0 if the result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int carry = 0;
    int sum, digit;
    int len1 = 0, len2 = 0;
    int i, j, k;

    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    if (len1 + 1 > size_r || len2 + 1 > size_r)
        return (0);

    i = len1 - 1;
    j = len2 - 1;
    k = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';

        digit = sum % 10;
        carry = sum / 10;

        r[k] = digit + '0';

        i--;
        j--;
        k++;
    }

    r[k] = '\0';

    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }

    return (r);
}
