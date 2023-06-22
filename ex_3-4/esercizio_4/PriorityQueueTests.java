package esercizio_4;

/**
 * da correggere: tipi missmach negli assert diversi tipi di array che non èuo confrontare, 
 * controllare le variabili passate e i valori nell'array exp di appoggio per il test
 */
import java.util.Comparator;
import static org.junit.Assert.*;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

import java.util.*;

/**
 * This class specifies tests to verify the right work of the PriorityQueue
 * library
 * 
 * @author Alessandro, Sofia, Valerio
 */
public class PriorityQueueTests {

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

    private Integer a, b, c, d, e, f, g, h;
    private PriorityQueue<Integer> queue;

    /**
     * create the object of PriorityQueue
     * 
     * @throws PriorityQueueException
     */
    @Before
    public void createPriorityQueue() throws PriorityQueueException {
        a = 12;
        b = 26;
        c = 3;
        d = 45;
        e = 1;
        f = 5;
        g = 8;
        h = 31;
        this.queue = new PriorityQueue<Integer>(comparator);
    }

    /**
     * Control that PriorityQueue is empty
     * 
     * @throws Exception
     */
    @Test
    public void testIsEmpty_zeroEl() throws Exception {
        assertTrue(queue.empty());
    }

    /**
     * Control that the PriorityQueue is not empty and so has a element
     * 
     * @throws Exception
     */
    @Test
    public void testIsEmpty_oneEl() throws Exception {
        queue.push(a);
        assertFalse(queue.empty());
    }

    /**
     * Control that the addition in the PriorityQueue of one element
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_oneEl() throws Exception {
        queue.push(a);
        assertTrue(a == queue.top());
    }

    /**
     * Control that the addition in the PriorityQueue of two elements
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_twoEl() throws Exception {
        ArrayList<Integer> array_exp = new ArrayList<>();
        array_exp.add(12);
        array_exp.add(26);
        queue.push(a);
        queue.push(b);
        assertArrayEquals(array_exp.toArray(), queue.heap.toArray());
    }

    /**
     * Control that the addition in the PriorityQueue of three elements
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_threeEl() throws Exception {
        ArrayList<Integer> array_exp = new ArrayList<>();
        array_exp.add(3);
        array_exp.add(12);
        array_exp.add(26);
        queue.push(c);
        queue.push(a);
        queue.push(b);
        assertArrayEquals(array_exp.toArray(), queue.heap.toArray());
    }

    /**
     * Control that the PriorityQueue is correctly sorted
     * 
     * @throws Exception
     */
    @Test
    public void testSorted() throws Exception {
        ArrayList<Integer> array_exp = new ArrayList<>();
        array_exp.add(3);
        array_exp.add(5);
        array_exp.add(8);
        array_exp.add(45);
        array_exp.add(12);
        array_exp.add(26);
        array_exp.add(31);

        queue.push(c);
        queue.push(a);
        queue.push(b);
        queue.push(d);
        queue.push(f);
        queue.push(g);
        queue.push(h);
        queue.sort(queue.heap.size() - 1);
        assertArrayEquals(array_exp.toArray(), queue.heap.toArray());
    }

    /**
     * Control that the PriorityQueue removes correctly the element requested
     * 
     * @throws Exception
     */
    @Test
    public void testRemove() throws Exception {
        ArrayList<Integer> array_exp = new ArrayList<>();
        array_exp.add(3);
        array_exp.add(5);
        array_exp.add(26);
        array_exp.add(12);
        array_exp.add(8);
        array_exp.add(31);

        queue.push(c);
        queue.push(a);
        queue.push(b);
        queue.push(f);
        queue.push(g);
        queue.push(h);
        queue.sort(queue.heap.size() - 1);

        assertArrayEquals(array_exp.toArray(), queue.heap.toArray());
    }
}
