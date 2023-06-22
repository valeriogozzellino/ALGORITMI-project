#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "record_managment.h"
#include "merge_binary_insertion_sort.h"
#include "compare.h"
#include <time.h>

void read_on_file(struct arrays *ptr_arrays, int n_record, char *file_path_read)
{
    FILE *f_r;
    char *read_line;
    char buffer[1024]; /* store the line red */
    int buf_size = 1024;
    int count = 0; /* calculate number of element in an array */
    f_r = fopen(file_path_read, "r");
    if (f_r == NULL)
    {
        fprintf(stderr, "main:error to open th file_read");
        exit(EXIT_FAILURE);
    }

    if (ptr_arrays == NULL)
    {
        fprintf(stderr, "cannot allocate memory for struct value");
        exit(EXIT_FAILURE);
    }

    while ((fgets(buffer, buf_size, f_r) != NULL) && (count < n_record))
    {
        
        read_line = malloc((strlen(buffer) + 1) * sizeof(char));

        if (read_line == NULL)
        {
            fprintf(stderr, "cannot allocate memory for var readline");
            exit(EXIT_FAILURE);
        }
        
        strcpy(read_line, buffer);
        char *store_integer_field1_read = strtok(read_line, ",");
        char *store_string_field_read = strtok(NULL, ",");
        char *store_integer_field2_read = strtok(NULL, ",");
        char *store_float_field_read = strtok(NULL, ",");
        ptr_arrays[count].string_field = malloc((strlen(store_string_field_read) + 1) * sizeof(char));
        /*
        * load field in the struct
        */
        ptr_arrays[count].integer_field1 = atoi(store_integer_field1_read);
        strcpy(ptr_arrays[count].string_field, store_string_field_read);
        ptr_arrays[count].integer_field2 = atoi(store_integer_field2_read);
        ptr_arrays[count].float_field = atof(store_float_field_read);
        /* printf("read variable int1 from struct==[%d]\n", ptr_arrays[count].integer_field1); */
        /* printf("read variable string from struct==[%s]\n", ptr_arrays[count].string_field); */
        /* printf("read variable int2 from struct==[%d]\n", ptr_arrays[count].integer_field2); */
        /* printf("read variable float from struct==[%f]\n", ptr_arrays[count].float_field); */

        count++;
        free(read_line);
    }
    fclose(f_r);
}

void writing_on_file(struct arrays *ptr_arrays, int n_record, char *file_write_path)
{
    int count = 0;
    FILE *f_w;
    f_w = fopen(file_write_path, "w");
    if (f_w == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while (n_record > 0)
    {
        /* printf("NRECORD --> %d\n", n_record); */
        /* printf("COUNT --> %d\n", count); */
        /* printf("dopo while in WRITE, count==[%d]\n", count); */
        /* printf("WRITE variable int1 from struct==[%d]\n", ptr_arrays[count].integer_field1); */
        /* printf("WRITE variable float from struct==[%f]\n", ptr_arrays[count].float_field); */ 
        /* printf("WRITE variable int2 from struct==[%d]\n", ptr_arrays[count].integer_field2); */
        /* printf("WRITE variable string from struct==[%s]\n", ptr_arrays[count].string_field); */
        fprintf(f_w, "%d, ", ptr_arrays[count].integer_field1);
        fprintf(f_w, " %s, ", ptr_arrays[count].string_field);
        fprintf(f_w, " %d, ", ptr_arrays[count].integer_field2);
        fprintf(f_w, " %f\n", ptr_arrays[count].float_field);
        count++;
        /* printf(" in WRITE prima del while dopo incremento count==[%d]\n", count); */
        /* printf("n_record==[%d]\n", n_record); */
        n_record--;
    }
    fclose(f_w);
}

void free_array(struct arrays *ptr_arrays, int n_items)
{
    for (int i = 0; i < n_items; i++)
    {
        free(ptr_arrays[i].string_field);
    }
    free(ptr_arrays);
}

int check_user_input(struct arrays *ptr_arrays, char const *argv[], int argc)
{
    char *file_path_read, *file_path_write;
    int k;
    char *field;
    if (argc != 5)
    {
        printf("metod require four argumets, insert: ./file_path where read data, ./file_path where write data, (k) the numerber where less we use insertion and the field used to order\n");
        return 0;
    }
    file_path_read = malloc((strlen(argv[1]) + 1) * sizeof(char));
    file_path_write = malloc((strlen(argv[2]) + 1) * sizeof(char));
    k = atoi(argv[3]);
    field = malloc((strlen(argv[4]) + 1) * sizeof(char));
    strcpy(file_path_read, argv[1]);
    strcpy(file_path_write, argv[2]);
    strcpy(field, argv[4]);

    printf("file read =[%s]\n", file_path_read);
    printf("file write=[%s]\n", file_path_write);
    printf("k=[%d]\n", k);
    printf("field=[%s]\n", field);
    printf("start simulation\n");
    start_test(ptr_arrays, file_path_read, file_path_write, k, field);
    /**test corretto ritorna 1*/
    return 1;
}

void start_test(struct arrays *ptr_arrays, char *file_path_read, char *file_path_write, int k, char *field)
{
    int (*generic_compare[])(const void *, const void *) = {compare_integer1, compare_integer2, compare_float, compare_string};

    read_on_file(ptr_arrays, N_RECORD, file_path_read);
    clock_t start = clock();

    if (strcmp("field_integer1", field) == 0)
    {
        printf("field_integer1\n");
        merge_binary_insertion_sort(ptr_arrays, (sizeof(*ptr_arrays) / sizeof(struct arrays)) * N_RECORD, sizeof(struct arrays), k, generic_compare[0]);
        double time = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("time of sorting: %f \n", time);
        writing_on_file(ptr_arrays, N_RECORD, file_path_write);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp("field_float", field) == 0)
    {
        printf("float\n");
        merge_binary_insertion_sort(ptr_arrays, (sizeof(*ptr_arrays) / sizeof(struct arrays)) * N_RECORD, sizeof(struct arrays), k, generic_compare[2]);
        double time = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("time of sorting: %f \n", time);
        writing_on_file(ptr_arrays, N_RECORD, file_path_write);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp("field_integer2", field) == 0)
    {
        printf("integer2\n");
        merge_binary_insertion_sort(ptr_arrays, (sizeof(*ptr_arrays) / sizeof(struct arrays)) * N_RECORD, sizeof(struct arrays), k, generic_compare[1]);
        double time = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("time of sorting: %f \n", time);
        writing_on_file(ptr_arrays, N_RECORD, file_path_write);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp("field_string", field) == 0)
    {
        printf("string\n");
        merge_binary_insertion_sort(ptr_arrays, (sizeof(*ptr_arrays) / sizeof(struct arrays)) * N_RECORD, sizeof(struct arrays), k, generic_compare[3]);
        double time = (double)(clock() - start) / CLOCKS_PER_SEC;
        printf("time of sorting: %f \n", time);
        writing_on_file(ptr_arrays, N_RECORD, file_path_write);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("insert a corret field like: -field_type- \n");
        free(ptr_arrays);
        exit(EXIT_FAILURE);
    }
}
