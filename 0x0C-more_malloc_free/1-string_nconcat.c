#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - function that concatenates two strings.
 * second string is an n value
 * @s1: string one
 * @s2: string two
 * @n: number of element to concatenate from s2
 * Return: Pointer to the new allocated memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n) 
{
    char *result;
    unsigned int len1 = 0, len2 = 0, i, j;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    if (n >= len2)
        n = len2;
    result = (char *)malloc((len1 + n + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (i = 0; i < len1; i++)
        result[i] = s1[i];

    for (j = 0; j < n; j++, i++)
        result[i] = s2[j];

    result[i] = '\0';

    return result;
}

int main(void) 
{
    char *s1 = "Best ";
    char *s2 = "School";
    char *result = string_nconcat(s1, s2, 7);

    if (result == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("%s\n", result);
    free(result);
    return 0;
}

