#include <stdlib.h>
#include <stdio.h>

int rand(void) {
    return 9; 
}

int __real_rand(void);

int __wrap_rand(void) {
    return 9;
}

