/**
* @author Alessandro, Sofia, Valerio
*/


/*
Richiama la funzione 'mergesortt' con parametri appropriati
*/
void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void *));


/*
La funzione mergesortt implementa un ibrido tra merge_sort e insertion_sort, quest'ultima viene utilizzata per sotto-array di dimensioni inferiori al parametro 'k'.
Le chiamate ricorsive di mergesortt (dopo previo controllo se l'array contiene almento 2 elementi da ordinare), vengono effettutate per ordinare i sue sotto-array separatamente.
La prima chiamata riordina la parte sinistra e la seconda chiamata la parte destra.
Se il controllo (right-left <= k) è verificato, allora si ha che il sotto-array è effettivamente sufficientemente piccolo e viene lanciato 'insertion_sort' per riordinarlo.
Altrimenti viene lanciato 'merge' per unire le due metà ordinate separatamente.
In seguito, le parti ordinate risultanti vengono ri-unite lanciando la funzione 'merge'. 
*/
void mergesortt(void *a, int left, int right, int k, size_t size, size_t nitems, int (*compar)(const void *, const void *));


/*
La funzione 'merge' implementa l'operazione di unione di due sotto-array.
Utilizza un algoritmo di 'merging' per combinare due porzioni ordinate dell'array in un unica porzione ordinata, utilizzando la funzione di confronto 'compar'.
L'array risultato 'b', allocato dinamicamente, viene copiato all'interno dell'array originale 'a', per poi disallocarne la memoria utilizzata.
*/
void merge(void *a, int left, int m, int right, size_t size, size_t nitems, int (*compar)(const void *, const void *));


/*
Implementa l'algoritmo di ricerca binaria per trovare la posizione di un elemento all'interno di un array.
Il ciclo while viene eseguito fintanto che left < right, indicando che l'intervallo di ricerca non è ancora stato esaurito.
Attraverso una serie di confronti tra l'elemento cercato e gli elementi dell'array, l'intervallo di ricerca viene diviso a metà,
fino a quando l'elemento non viene trovato oppure l'intervallo di ricerca si esaurisce (elemento inesistente).
*/
int binary_search(void *base, void *item, int left, int right, size_t size, int (*compar)(const void *, const void *));


/*
La funzione Insertion_Sort prende in input un puntatore generico 'base' (inizio dell'array da ordinare), 'n' (numero di elementi), 'size' (dimensione elementi), ed utilizza la funzione di controllo 'compar'
'loc' e 'j' sono fur variabili intere utilizzate per tenere traccia delle posizioni durante l'ordinamento.
'selected' di dimensione 'size' viene utilizzato per memorizzare temporaneamente l'elemento selezionato durante l'ordinamento, mentre 'tmp' si usa per copiare degli elementi durante lo spostamento.
L'algoritmo utilizza la ricerca binaria per individuare la posizione corretta in cui inserire ogni elemento all'interno dell'array, spostando gli elementi maggiori verso destra.
*/
void Insertion_Sort(void *base, int n, size_t size, int (*compar)(const void *, const void *));