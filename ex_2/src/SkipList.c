#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "SkipList.h"

void new_skiplist(struct SkipList **list, size_t max_height)
{

    /* Allocazione della memoria per la SkipList */
    struct SkipList *lista = (struct SkipList *)malloc(sizeof(struct SkipList));

    lista->head = (struct Node *)malloc(sizeof(struct Node));
    lista->max_level = 0;
    lista->max_height = max_height;

    /* Allocazione della memoria per il puntatore head della SkipList */
    lista->head = (struct Node *)malloc(sizeof(struct Node));

    /* Inizializzazione dei valori nel nodo head */
    lista->head->next = (struct Node **)calloc(max_height, sizeof(struct Node *));
    lista->head->size = max_height;
    lista->head->item = NULL;

    /* Salvataggio della locazione di memoria allocata nella variabile *list */
    *list = lista;
}

void clear_skiplist(struct SkipList **list)
{
    if (*list == NULL)
    {
        return;
    }
    struct Node *current = (*list)->head;
    struct Node *next = NULL;
    int i = 1;
    int done = 0;

    while (current != NULL && !done)
    {

        if (current->next[0] != NULL)
        {
            next = current->next[0];
        }

        free(current->next);
        free(current->item);
        current = next;
    
        if (current->next[0] == NULL)
        {
            done = 1;
        }
        else
        {
            /* do nothing (is not null) */
        }
    }
    
    free(current);
    free((*list)->head);
    free(*list);
    *list = NULL;
}

struct Node *create_node(void *item, int level)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("new node is null\n");
        return NULL; /* gestione dell'errore di allocazione della memoria */
    }

    new_node->item = malloc(strlen((char *)item) + 1);
    if (new_node->item == NULL)
    {
        printf("new node item is null\n");
        free(new_node); /* gestione dell'errore di allocazione della memoria */
        return NULL;
    }
    strcpy(new_node->item, (char *)item);
    new_node->size = level;

    new_node->next = malloc((level + 1) * sizeof(struct Node *));
    if (new_node->next == NULL)
    {
        printf("new node di next is null\n");
        free(new_node->item); /* gestione dell'errore di allocazione della memoria */
        free(new_node);
        return NULL;
    }
    for (int i = 0; i <= level; i++)
    {
        new_node->next[i] = NULL;
    }

    return new_node;
}


int random_level(int max_height)
{
    int lvl = 1;
    if(max_height == 1){
        return 1;
    }
    while (((double)rand() / RAND_MAX) < 0.5 && lvl < max_height)
    {
        lvl++;
    }
    
    if (max_height % 2 == 0 && lvl % 2 == 1)
    {
        lvl++; /* Se max_height è pari, incrementa il livello se è dispari. */
    }

    lvl = (lvl % max_height) + 1;
    return lvl;
}






void insert_skiplist(struct SkipList **list, void *item, int (*compar)(const void *, const void *), int max_height)
{
    struct Node *new_node = create_node(item, random_level(max_height));

    if (new_node->size > (*list)->max_level)
    {
        (*list)->max_level = new_node->size;
    }

    struct Node *x = (*list)->head;
    struct Node *update[max_height];
 //faccio il for per tutti i level
    for (int i = (*list)->max_level - 1; i >= 0; i--)
    {
        while (x->next[i] != NULL && compar(x->next[i]->item, item) < 0)
        {
            /* x->next[i] != NULL && *((int*)x->next[i]->item) < *((int*)item)  */
            x = x->next[i];
        }

        update[i] = x;
    }

    x = x->next[0];

    if (x == NULL || ((char *)x->item) != ((char *)item))
    {
        //inserisco il nuovo nodo nella lista se questo non è presente
        for (int i = 0; i < new_node->size; i++)
        {
            new_node->next[i] = update[i]->next[i];
            update[i]->next[i] = new_node;
        }
    }
}

void print_list(struct SkipList **list)
{

    if (*list == NULL || (*list)->head == NULL)
    {
        printf("Empty List.. \n");
        return;
    }

    struct Node *curr = (*list)->head->next[0];

    while (curr != NULL)
    {
        printf("[%s| %zu] --> ", ((char *)curr->item), curr->size);
        curr = curr->next[0];
    }

    printf("\n");
}

const void *search_skiplist(struct SkipList *list, void *item, int (*compar)(const void *, const void *), int max_height)
{

    struct Node *curr = (list)->head;
    int cnt = 1;
    
    for (int i = list->max_level; i >= 0;)
    {

        if (curr->next[i] == NULL)
        {
            /* printf("Cambio velocita'\n"); */
            i--;
        }
        else
        {
            /* *((int*)curr->next[i]->item) < *((int*)item) */
            if (compar(curr->next[i]->item, item) < 0)
            {
    
                curr = curr->next[i];
            }
            else if (compar(curr->next[i]->item, item) > 0)
            {
                /* *((int*)curr->next[i]->item) > *((int*)item) */
                i--;
            }
            else if (compar(curr->next[i]->item, item) == 0)
            {
                /* *((int*)curr->next[i]->item) == *((int*)item) */
                return curr->next[i];
            }
            else
            {
                /* do nothing */
            }
        }
        cnt++;
    }
    printf("..not found..\n");
    return NULL;
}


/* Record Management */

void find_errors(struct SkipList *dictionary_list, char *file_path_dictionary, char *file_path_correctme, int max_height)
{
    //printf("sono in find error------\n");
    clock_t start = clock();

    FILE *f_r_d, *f_r_c; /* r_d = dictionary, r_c = correctme */
    char *read_line_1, *word_read;
    char buffer[4096]; /* store the line red */
    int buf_size = 4096;
    f_r_d = fopen(file_path_dictionary, "r"); /* dictionary */
    f_r_c = fopen(file_path_correctme, "r");  /* correctme */
    read_line_1 = malloc((strlen(buffer) + 1) * sizeof(char));
    word_read = malloc(sizeof(char) * 1000);

    if (f_r_d == NULL || f_r_c == NULL)
    {
        if (f_r_d == NULL)
        {
            fprintf(stderr, "main:error to open th file_read dictinoary\n");
        }
        if (f_r_c == NULL)
        {
            fprintf(stderr, "main:error to open th file_read correctme\n");
        }
        exit(EXIT_FAILURE);
    }

    if (dictionary_list == NULL)
    {
        fprintf(stderr, "cannot allocate memory for struct value");
        exit(EXIT_FAILURE);
    }

    /*** Read su dictionary list ***/

    while ((fgets(buffer, buf_size, f_r_d) != NULL))
    {
        //printf("--------sono nel while di -----\n");
        strcpy(read_line_1, buffer);
        word_read = strtok(read_line_1, "\n");
        insert_skiplist(&dictionary_list, word_read, dictionary_list->compare, max_height);
    }

    /*sono in insert*/
    // printf("Stampo dictionary \n");
    // print_list(&dictionary_list);

    /*** Read su correctme list ***/
    fgets(buffer, buf_size, f_r_c);        /* copia in buffer tutto il testo */
    strcpy(read_line_1, buffer);           /* copia il testo di buffer in read_line */
    char *read_line_ptr = &read_line_1[0]; /* punta al primo elemento di read_line */
    int i = 0;
    int done = 0;

    printf("Inizio a correggere gli errori\n");

    while (!done)
    {

        char stringa[100];
        char *word_read_ptr = &stringa[0];
        int j = 0;

        if (read_line_ptr[i] == ' ')
        {
            i++;
        }
     
        while (read_line_ptr[i] != ' ' && read_line_ptr[i] != '\0' && read_line_ptr[i] != ',' && read_line_ptr[i] != '.' && read_line_ptr[i] != ':')
        {
            word_read_ptr[j] = read_line_ptr[i];
            i++;
            j++;
        }

        word_read_ptr[j] = '\0';
     
        if (search_skiplist(dictionary_list, stringa, dictionary_list->compare, max_height) == NULL)
        {

            if (strlen(stringa) != 0)
            {
                printf("--> %s\n", stringa);
            }
        }
     
        if (read_line_ptr[i] == '\0')
        {
            done = 1;
        }

        i++;
    }
    double time = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time of sorting: %f \n", time);
    clear_skiplist(&dictionary_list);
    fclose(f_r_d);
    fclose(f_r_c);
}
