package esercizio_4;

import java.util.*;

/**
 * @author Alessandro, Sofia, Valerio
 */

public class PriorityQueue<E> implements AbstractQueue<E> {
    Comparator<E> comparatore;
    Map<E, Integer> hash_map;
    ArrayList<E> heap;

    public PriorityQueue(Comparator<E> comparatore) {
        this.comparatore = comparatore;
        this.heap = new ArrayList<>();
        this.hash_map = new HashMap<>();
    }

    /* Controlla se la coda è vuota, restituisce true se lo è, false altrimenti */
    public boolean empty() {
        return heap.isEmpty();
    }

    /* Aggiunge un elemento, true se ci riesce, false altrimenti */
    public boolean push(E e) {

        boolean added = heap.add(e); /* aggiunge alla coda */
        if (added) {
            hash_map.put(e, heap.size() - 1); /* aggiorno la hash map */
            buildMaxHeap(heap.size() - 1); /* riordino rispettando la priorita' */
        }
        return added;

    }

    public void increase_priority() { /*
                                       * increase priority gestita in questo modo perchè la priority queue, ogni volta
                                       * che aggiorna la key
                                       * di un elemento, ha come top l'elemento con key minore, quindi la increase mi
                                       * serve semplicemente per aumetare la priorità di un elemento
                                       * e se per noi la rpiorità è la key, cambiando la key con una key di valore
                                       * minore la priorità si incrementerà e riordinando avrò un increase priorità
                                       */
        buildMaxHeap(heap.size() - 1);
    }

    public boolean contains(E e) {
        return hash_map.containsKey(e); /* ritorna la key dell'elemento se esiste. */
    }

    public E top() { /* returna l'elemento in cima alla coda */
        if (empty()) {
            return null;
        }
        return heap.get(0);
    }

    public void pop() { /* elimina il primo elemento in cima alla coda (indice 0) */
        if (!empty()) {
            removeAtIndex(0); /* rimuove elemento e riordina */
        }
    }

    public boolean remove(E e) { /* rimuove un determinato elemento dalla coda */
        int index = heap.indexOf(e);

        if (index < heap.size()) {
            removeAtIndex(index); /* rimuove e riordina */
        }
        return true;
    }

    public void removeAtIndex(int index) {

        int last_elem_index = heap.size() - 1;

        if (index < last_elem_index) {
            swap(index, last_elem_index);
            /*
             * Aggiorno la mappa siccome l'ultimo elemento sarà spostato all'indice 'index'
             */
            hash_map.put(heap.get(index), index);
        }

        E removed_elem = heap.remove(last_elem_index); /* Rimuovo l'ultimo elemento dall'heap */
        hash_map.remove(removed_elem); /* Rimuovo l'elemento dalla mappa */

        buildMaxHeap(index); /* Riordino la coda a partire dall'indice 'index' */
    }

    public void buildMaxHeap(int index) {
        int parent_index = parent(index);
        while (parent_index >= 0) {
            sort(parent_index);
            parent_index--;
        }
    }

    public void sort(int index) { /*
                                   * gestisce gli indici, input il padre--> se oadre ha key >figlio.key allora
                                   * swappa
                                   * e riparto da index del figlio.
                                   */
        int min_index = index;

        if ((comparatore.compare(heap.get(index), heap.get(left(index))) == 1)
                || (comparatore.compare(heap.get(index), heap.get(right(index))) == 1)) {

            if ((comparatore.compare(heap.get(left(index)), heap.get(right(index))) == -1)) {
                min_index = left(index);
            } else {
                min_index = right(index);
            }
        }
        if (min_index != index) {// se ho modificato l'indice significa che i figli hanno priorità maggiore
            swap(index, min_index);
            sort(min_index);
        }

    }

    private void swap(int i, int j) { /* scambia due elementi */
        E elementI = heap.get(i);
        E elementJ = heap.get(j);
        heap.set(i, elementJ);
        heap.set(j, elementI);
        hash_map.put(elementI, j);
        hash_map.put(elementJ, i);
    }

    public int parent(int i) { /* return parent index */

        if (i >= 0) {

            if ((i % 2) == 0) { /* is even */
                return ((i / 2) - 1);

            } else if (i % 2 != 0) {

                return (i / 2);
            }

        }

        return -1;

    }

    public int left(int i) { /* return left child index */

        if (((2 * i) + 1) < heap.size()) {

            return ((2 * i) + 1);
        } else {

            return i;
        }

    }

    public int right(int i) { /* reutrn right child index */

        if (((2 * i) + 2) < heap.size()) {

            return ((2 * i) + 2);
        } else {

            return i;
        }
    }

}
