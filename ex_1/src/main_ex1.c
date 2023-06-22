#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "record_managment.h" /* read e write */
#include "merge_binary_insertion_sort.h"
#include "unity.h"
#include "compare.h"


//#define N_RECORD 11

/*
struct arrays 
{
    int integer_field1;
    float float_field;
    int integer_field2;
    char *string_field;
};
*/
int main(int argc, char const *argv[])
{


    struct arrays *array_ptr;
    array_ptr = malloc(sizeof(struct arrays) * N_RECORD);

    if (array_ptr == NULL)
    {
        fprintf(stderr, "cannot allocate memory for the array\n");
    }
    if (check_user_input(array_ptr, argv, argc) != 1)
    {
        printf("error, insert corret data required!");
    }

    free(array_ptr);
}