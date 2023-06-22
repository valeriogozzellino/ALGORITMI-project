package esercizio_4;

import java.util.*;

/**
 * @author Alessandro, Sofia, Valerio
 */

public class Main_ex3 {

    public static void main(String[] args) {

        Comparator<Integer> comparator = new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                if (o1 > o2) {
                    return 1;
                } else if (o1 < o2) {
                    return -1;
                }
                return 0;
            }
        };
        /**
         * TEST 1
         * test su tutti i metodi una lista tipica
         */
        System.out.println("-----------HEAP---------");
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>(comparator);

        /* PUSH - OK */
        System.out.println("Pusho 5 ");
        heap.push(5);
        System.out.println("Pusho 4");
        heap.push(4);
        System.out.println("Pusho 9 ");
        heap.push(9);
        System.out.println("Pusho 3 ");
        heap.push(3);
        System.out.println("Pusho 2 ");
        heap.push(2);
        System.out.println("Pusho 0 ");
        heap.push(0);
        System.out.println("------- EMPTY --------");
        System.out.println("Pusho 1 ");
        heap.push(1);
        System.out.println("------- EMPTY --------");
        /**
         * EMPTY - ?
         * test su una lista vuota
         */
        PriorityQueue<Integer> empty_heap = new PriorityQueue<Integer>(comparator);
        System.out.println("empty_heap is empty (exp true) --> " +
                empty_heap.empty());

        // System.out.println("------- CONTAINS --------");
        // /* CONTAINS - ? */
        // System.out.println("heap contains 4 (exp true) --> " + heap.contains(4));
        // System.out.println("heap contains 99 (exp false) --> " + heap.contains(99));
        // System.out.println("empty_heap contains 4?: --> " + empty_heap.contains(4));

        System.out.println("------- TOP --------");

        /* TOP - ? */
        System.out.println("top of heap (exp 0) --> " + heap.top());
        System.out.println("top of empty_heap (exp: _null_) --> " +
                empty_heap.top());

        System.out.println("------- POP --------");

        /* POP - ? */

        System.out.println("____heap prima di pop_____");
        for (int i = 0; i < heap.heap.size(); i++) {
            System.out.println("stampo lo heap i=" + i + "=" + heap.heap.get(i));
        }

        heap.pop();
        System.out.println("______heap dopo di pop, elimino elemento in radice_____");

        for (int i = 0; i < heap.heap.size(); i++) {
            System.out.println("stampo lo heap i=" + i + "=" + heap.heap.get(i));
        }

        System.out.println("------- REMOVE --------");

        /* REMOVE - ? */
        System.out.println("heap remove (3)");
        heap.remove(3);
        System.out.println("heap dopo remove");

        for (int i = 0; i < heap.heap.size(); i++) {
            System.out.println("stampo lo heap i=" + i + "=" + heap.heap.get(i));
        }
        /**
         * // * TEST 3
         * // * test sul metodo increase, da controllare se stampa effettivamente
         * l'albero
         * // * della heap
         * //
         */
        System.out.println("-----------TEST INCREASE--------");
        PriorityQueue<Integer> increase_heap = new PriorityQueue<>(comparator);
        System.out.println("push elemento 4");
        increase_heap.push(4);
        System.out.println("push elemento 7");
        increase_heap.push(7);
        System.out.println("push elemento 13");
        increase_heap.push(13);
        System.out.println("push elemento 15");
        increase_heap.push(15);
        System.out.println("push elemento 21");
        increase_heap.push(21);
        System.out.println("push elemento 1");
        increase_heap.push(1);
        System.out.println("push elemento 3");
        increase_heap.push(3);
        System.out.println("------stampo la lista PRIMA controllo increase--------");

        for (int i = 0; i < increase_heap.heap.size(); i++) {
            System.out.println("heap i = " + i + " = " +
                    increase_heap.heap.get(i));
        }
        increase_heap.increase_priority();
        System.out.println("------stampo la lista DOPO controllo increase------");

        for (int i = 0; i < increase_heap.heap.size(); i++) {
            System.out.println(" heap i = " + i + " = " +
                    increase_heap.heap.get(i));
        }

    }
}
