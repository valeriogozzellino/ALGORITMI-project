#ifndef RECORD_MANAGMENT_H_
#define RECORD_MANAGMENT_H_

#define N_RECORD 2000000


/**
* @author Alessandro, Sofia, Valerio
*/

struct arrays
{
    int integer_field1;
    float float_field;
    int integer_field2;
    char *string_field;
};

void read_on_file(struct arrays *ptr_arrays, int n_record, char *file_read_path);
/**
 * write on file csv
 */
void writing_on_file(struct arrays *ptr_array, int n_record, char *file_write_path);
/**
 *free the allocated memory
 */
void free_array(struct arrays *ptr_arrays, int n_items);
/**
 * check if the user input are correct for the right execution of the program
 */
int check_user_input(struct arrays *ptr_arrays, char const *argv[], int argc);
/**
 *start the merge sort, control the type used to order records
 */
void start_test(struct arrays *ptr_arrays, char *file_path_read, char *file_path_write, int k, char *field);

#endif