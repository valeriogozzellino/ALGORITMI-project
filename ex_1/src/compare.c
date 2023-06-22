#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "compare.h"
#include "record_managment.h"

int compare_integer1(const void *first, const void *second)
{ /* Caso array di int */
    struct arrays *first_struct, *second_struct;
    first_struct = (struct arrays *)first;
    second_struct = (struct arrays *)second;

    if (first_struct->integer_field1 > second_struct->integer_field1)
    {
        return 1;
    }
    else if (first_struct->integer_field1 < second_struct->integer_field1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int compare_integer2(const void *first, const void *second)
{ /* Caso array di int */
    struct arrays *first_struct, *second_struct;
    first_struct = (struct arrays *)first;
    second_struct = (struct arrays *)second;

    if (first_struct->integer_field2 > second_struct->integer_field2)
    {
        return 1;
    }
    else if (first_struct->integer_field2 < second_struct->integer_field2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int compare_float(const void *first, const void *second)
{ /* Caso array di int */
    struct arrays *first_struct, *second_struct;
    first_struct = (struct arrays *)first;
    second_struct = (struct arrays *)second;

    if (first_struct->float_field > second_struct->float_field)
    {
        return 1;
    }
    else if (first_struct->float_field < second_struct->float_field)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int compare_string(const void *first, const void *second){
    struct arrays *first_struct, *second_struct;
    first_struct = (struct arrays *)first;
    second_struct = (struct arrays *)second;
    if (strcmp(first_struct->string_field, second_struct->string_field) > 0){
        return 1;
    } else if (strcmp(first_struct->string_field, second_struct->string_field) < 0){
        return -1;
    } else {
        return 0;
    }
}