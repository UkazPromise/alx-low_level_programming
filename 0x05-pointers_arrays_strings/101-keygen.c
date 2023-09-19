#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Generate random valid password for the 
 * program 101-crackme.
 * Return: Always 0
 */

#define PASSWORD_LENGTH 10

int main(void)
{
    char password[PASSWORD_LENGTH + 1];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("%s\n", password);

    return 0;
}

