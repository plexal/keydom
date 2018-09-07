#include <stdio.h>
#include <stdlib.h>

void * malloc_and_error_check(const size_t size)
{
    void *mem = malloc(size);
    if (mem == NULL) {
        perror("Error");
        exit (EXIT_FAILURE);
    }
    return mem;
}

void * calloc_and_error_check(const size_t nitems, const size_t size)
{
    void *mem = calloc(nitems, size);
    if (mem == NULL) {
        perror("Error");
        exit (EXIT_FAILURE);
    }
    return mem;
}
