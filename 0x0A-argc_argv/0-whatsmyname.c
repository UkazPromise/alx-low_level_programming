#include "main.h"

/**
 * main - print the name of the program
 * @argc: Number of arguments
 * @argv: Arrays of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc_attribute_((unused)), char *argv[])
{
	print("%s\n", *argv);
	return (0);
}
