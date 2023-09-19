#include "main.h"

/**
 * _puts - function name
 * @str: function parameter
 */

void _puts(char *str)
{
int i;

for (i = 0; str[i] ! =  '\10'; i++)
_putchar (str[i]);
putchar ('\n');
}
