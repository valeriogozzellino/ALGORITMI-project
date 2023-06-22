#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "compare.h"

//#define MAX_HEIGHT atoi(argv[3])

/**
* @author Alessandro, Sofia, Valerio
*/

struct SkipList
{
  struct Node *head;                          /* Primo nodo della skiplist */
  size_t max_level;                           /* N. Max di puntatori (al momento) in un singolo nodo */
  size_t max_height;                          /* N. Max di puntatori (in generale) che possono essere in un nodo */
  int (*compare)(const void *, const void *); /* Criterio secondo cui riordinare i dati */
};

struct Node
{
  struct Node **next; /* Array di nodi in un dato noto della lista */
  size_t size;        /* Numero di puntatori in un dato nodo della lista */
  void *item;         /* Dato memorizzato in un certo nodo della lista */
};


/*
Allora una nuova Skip_List, inizializzandone i parametri a valori appropriati
*/
void new_skiplist(struct SkipList **list, size_t max_height);                                             


/*
Dealloca la memoria 
*/
void clear_skiplist(struct SkipList **list);                                                               


/*
La funzione insert_skiplist, inserisce un nuovo nodo nella lista, trovando il punto di inserimento corretto tramite coonfronto con gli elementi già presenti nella lista.
Successivamente aggiorna i puntatori successivi degli elementi precedenti al punto di inserimento per includere il nuovo nodo nella lista.
*/
void insert_skiplist(struct SkipList **list, void *item, int (*compar)(const void *, const void *), int max_height);       


/*
La funzione search_skiplist ricerca un elemento all'interno della Skiplist.
Il controllo viene effettuato tra 'item' e il nodo corrente, controllando i suoi next a partire dal più remoto (scorre in altezza), 
si può effettuare una scelta sul quanti elementi saltare o non saltare durante la ricerca, il che la rende molto efficiente.
Quando un elemento viene trovato si restituisce il puntatore ad esso, o un messaggio di fallimento in caso contrario.
*/
const void *search_skiplist(struct SkipList *list, void *item, int (*compar)(const void *, const void *), int max_height); 


/*
La funzione random_level utilizza il timer come seme per la generazione di numeri casuali, i quali vengono utilizzati per l'allocazione 
dell'array di puntatori 'next' di ogni singolo nodo della lista, ogni nodo quindi avrà un numero di next variabile e casuale.
*/
int random_level(int max_height);                                                                                        


/*
La funzione 'create_node', crea un nuovo nodo nella struttura dati 'struct Node'. 
Viene allocata la memoria per il nodo stesso, per l'elemento 'item' e per l'array di puntatori 'next'.
L'elemento 'item' viene copiato nel nodo e il livello del nodo stesso viene assegnato tramite 
*/
struct Node *create_node(void *item, int level);


/*
Stampa la lista
*/
void print_list(struct SkipList **list); 


/* Record management */
void find_errors(struct SkipList *dictionary_list, char *file_path_dictionary, char *file_path_correctme, int max_height);