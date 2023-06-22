#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "compare.h"
#include "SkipList.h"

void new_skiplist(struct SkipList **list, size_t max_height); /* OK */
void clear_skiplist(struct SkipList **list); /* OK */
void insert_skiplist(struct SkipList **list, void *item, int (*compar)(const void *, const void *), int max_height); /* OK */
const void* search_skiplist(struct SkipList *list, void *item, int (*compar)(const void *, const void *), int max_height); /* OK */
int random_level(); /* OK */
// void* create_node(void* item, int level); 
struct Node* create_node(void* item, int level);
void print_list(struct SkipList **list); /* OK */

/* Record management */
void find_errors(struct SkipList *dictionary_list, char *file_path_dictionary, char *file_path_correctme, int max_height);

int main(int argc, char  const*argv[]){

    /* Parole mancanti --> da, in, dictionary */
    //#define MAX_HEIGHT atoi(argv[3])
    
    char *file_path_dictionary, *file_path_correctme;

    if (argc != 4){
        printf("metod require three argumets, insert: ./file_path where read data, ./file_path where write data, the height\n");
        return 0;
    }

    file_path_dictionary = malloc((strlen(argv[1]) + 1) * sizeof(char));
    file_path_correctme = malloc((strlen(argv[2]) + 1) * sizeof(char));
    strcpy(file_path_dictionary, argv[1]);
    strcpy(file_path_correctme, argv[2]);
    
    const char *arg3 = argv[3];
    // Converte la stringa in un numero intero
    int max_height = atoi(arg3);


    
    printf("file dictionary =[%s]\n", file_path_dictionary);
    printf("file correctme =[%s]\n", file_path_correctme);
    printf("max height =[%d]\n", max_height);

    printf("\n");

    srand(time(NULL));
    
    
    int (*generic_compare[])(const void *, const void *) = {compare_integer, compare_float, compare_string};
   
    struct SkipList* dictionary_list = NULL; 
    new_skiplist(&dictionary_list, max_height);    
    dictionary_list->compare = generic_compare[2];

    if (dictionary_list == NULL){
        fprintf(stderr, "cannot allocate memory for the array\n");
    } 

    printf("Lancio find errors\n");
    find_errors(dictionary_list, file_path_dictionary, file_path_correctme, max_height);

    //printf("Chiamo clear\n");
    //clear_skiplist(&dictionary_list);    
}