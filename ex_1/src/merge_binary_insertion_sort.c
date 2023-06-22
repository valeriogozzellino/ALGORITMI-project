#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge_binary_insertion_sort.h"
#include "record_managment.h"

/**
 * function that take as input a coid poiter to a generic array, size of the total number of element in the array, "k" is
 * the algoritm number that choose, on the number of elements in the array, the algoritm that is advised to use, the last
 * input are two poitner element.
*/

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void *))
{
    int lgt;
    int left = 0;

    mergesortt(base, left, nitems-1, k, size, nitems, compar);
}

void mergesortt(void *a, int left, int right, int k, size_t size, size_t nitems, int (*compar)(const void *, const void *)){
    int m;
    if(left < right){

        m = (left + right) /2;

        mergesortt(a, left, m, k, size, nitems, compar);
        mergesortt(a, m+1, right, k, size, nitems, compar);

        if(right - left <= k){
            Insertion_Sort(a + left * size, (right-left)+1, size, compar);
        } else {
            merge(a, left, m, right, size, nitems, compar);
        }

    }
}

void merge(void *a, int left, int m, int right, size_t size, size_t nitems, int (*compar)(const void *, const void *))
{
    int i = left, j = m + 1, k = 0;
    void *b = malloc(size * (right - left + 1));

    while ((i <= m) && (j <= right))//finchè non raggiungo la fine dei sottoarray suddivisi
    {
        if ((compar(a + (i * size), a + (j * size)) == -1) || compar(a + (i * size), a + (j * size)) == 0)
        { 
            memcpy(b + (k * size), a + (i * size), size); //switc tra il primo e quello di metà
            i++;
        }
        else
        {
            memcpy(b + (k * size), a + (j * size), size);
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        memcpy(b + (k * size), a + (i * size), size);
        i++;
        k++;
    }

    while (j <= right)
    {
        memcpy(b + (k * size), a + (j * size), size);
        j++;
        k++;
    }

    for (k = left; k <= right; k++)
    {
        memcpy(a + (k * size), b + ((k - left) * size), size);
    }

    free(b);
}

int binary_search(void *base, void *item, int left, int right, size_t size, int (*compar)(const void *, const void *))
{
    while (left <= right)
    {
        int m = left + (right - left) / 2;

        if (compar(item, base + (m * size)) == 0)
        { /* if item == a[m] */
            return m + 1;
        }
        else if (compar(item, base + (m * size)) == 1)
        { /* item > mid */
            left = m + 1;
        }
        else
        {
            right = m - 1;
        }
    }
    return left;
}

void Insertion_Sort(void *base, int n, size_t size, int (*compar)(const void *, const void *))
{
    int loc, j;
    void *selected = malloc(size);
    void *tmp = base;

    for (int i = 1; i < n;)
    {
        j = i - 1;
        memcpy(selected, base + (i * size), size); //mi copio l'elemento che sto confrontando

        loc = binary_search(base, selected, 0, j, size, compar); //ritorna posizione in cui inserire l'elemento

        while (j >= loc) //fintanto che non mi trovo sulla posizione in cui inserire l'elemento, shifto gli elementi
        { /* Shifta i numeri maggiori di selected a destra */
            memcpy(base + ((j + 1) * size), tmp + (j * size), size);
            j--;
        }

        memcpy(base + ((j + 1) * size), selected, size); /* Copia selected nella posizione giusta */

        i++;
    }

    free(selected);
}
