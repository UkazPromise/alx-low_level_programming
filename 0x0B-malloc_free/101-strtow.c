#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int word_len(char *str);
int count_words(char *str);
char **split_str(char *str);

/**
 * word_len - function to locate the index marking the end of the first word contained within a string.
 * @str: The string to be searched.
 *
 * Return: The index marking the end of the initial word pointed to by str.
 */

int word_len(char *str)
{
    int len = 0;
    while (*str && *str != ' ')
    {
        len++;
        str++;
    }
    return len;
}

/**
 * count_words - Counts the number of words contained within a string.
 * @str: The string to be searched.
 *
 * Return: The number of words contained within star.
 */

int count_words(char *str)
{
    int words = 0;
    int index = 0;
    while (str[index])
    {
        if (str[index] != ' ')
        {
            words++;
            index += word_len(str + index);
        }
        else
        {
            index++;
        }
    }
    return words;
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: if str = NULL, str = "", or the function fails - NULL.
 * 			0therwise - a pointer to an array of strings (words).
 */

char **split_str(char *str)
{
    char **strings;
    int index = 0, words, w, letters, l;

    if (str == NULL || str[0] == '\0')
        return NULL;

    words = count_words(str);
    if (words == 0)
        return NULL;

    strings = (char **)malloc(sizeof(char *) * (words + 1));
    if (strings == NULL)
        return NULL;

    for (w = 0; w < words; w++)
    {
        while (str[index] == ' ')
            index++;

        letters = word_len(str + index);

        strings[w] = (char *)malloc(sizeof(char) * (letters + 1));

        if (strings[w] == NULL)
        {
            for (; w >= 0; w--)
                free(strings[w]);

            free(strings);
            return NULL;
        }

        for (l = 0; l < letters; l++)
            strings[w][l] = str[index++];

        strings[w][l] = '\0';
    }
    strings[w] = NULL;

    return strings;
}
