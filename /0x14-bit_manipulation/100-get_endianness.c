#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
    unsigned int test = 1;
    unsigned char *byte_ptr = (unsigned char *)&test;

    return (byte_ptr[0] == 1);
}

