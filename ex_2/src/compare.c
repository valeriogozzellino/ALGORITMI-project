#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "compare.h"

int compare_integer(const void *first, const void *second)
{ /* Ca*so array di int */
    char* first_int = (char*) first;
    char* second_int = (char*) second;

    /* printf("Primo --> %d. Secondo --> %d.\n", *first_int, *second_int); */

    if (*first_int > *second_int)
    {
        return 1;
    }
    else if (*first_int < *second_int)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int compare_float(const void *first, const void *second)
{ /* Caso array di float */
    float* first_float;
    first_float = (float*) first;
    float* second_float = (float*) second;

    if (first_float > second_float)
    {
        return 1;
    }
    else if (first_float < second_float)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


int compare_string(const void *first, const void *second) {
    return strcmp(((char*)first), ((char*)second));
}



