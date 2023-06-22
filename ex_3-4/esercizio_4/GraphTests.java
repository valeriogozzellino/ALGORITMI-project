package esercizio_4;

import java.util.Comparator;
import static org.junit.Assert.*;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

/**
* @author Alessandro, Sofia, Valerio
*/

public class GraphTests {
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

    private Graph<Node, Integer> graph;
    private Node A;
    private Node B;
    private Node C;
    private Node D;
    private Node E;
    private Node F;
    private Node G;
    private Node H;

    /**
     * create the object of Graph
     * 
     * @throws PriorityQueueException
     */
    @Before
    public void createGraph() throws GraphException {
        this.graph = new Graph<>(false, true);
        A = new Node("A", null, Integer.MAX_VALUE);
        B = new Node("B", null, Integer.MAX_VALUE);
        C = new Node("C", null, Integer.MAX_VALUE);
        D = new Node("D", null, Integer.MAX_VALUE);
        E = new Node("E", null, Integer.MAX_VALUE);
        F = new Node("F", null, Integer.MAX_VALUE);
        G = new Node("G", null, Integer.MAX_VALUE);
        H = new Node("H", null, Integer.MAX_VALUE);
    }

    /**
     * Control that Graph is empty
     * 
     * @throws Exception
     */
    @Test
    public void testIsEmpty_zeroEl() throws Exception {
        assertTrue(graph.numNodes() == 0);
    }

    /**
     * Control that the Graph is not empty and so has a node
     * 
     * @throws Exception
     */
    @Test
    public void testIsEmpty_oneNode() throws Exception {
        graph.addNode(A);
        assertFalse(graph.numNodes() == 0);
    }

    /**
     * Control that the addition in the Graph of one node
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_oneNode() throws Exception {
        graph.addNode(A);
        assertTrue(graph.numNodes() == 1);
    }

    /**
     * Control that the addition in the Graph of one edge
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_oneEdge() throws Exception {
        graph.addNode(A);
        graph.addNode(B);
        graph.addEdge(A, B, 5);
        assertTrue(graph.numEdges() == 1);
    }

    /**
     * Control that the addition in the Graph of two nodes
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_twoNode() throws Exception {
        graph.addNode(A);
        graph.addNode(B);
        assertTrue(graph.numNodes() == 2);
    }

    /**
     * Control that the addition in the Graph of two edges
     * 
     * @throws Exception
     */
    @Test
    public void testAdd_twoEdge() throws Exception {
        graph.addNode(A);
        graph.addNode(B);
        graph.addNode(C);
        graph.addEdge(A, C, 10);
        assertTrue(graph.numEdges() == 1);
    }

    /**
     * Control that the PriorityQueue removes correctly the node requested
     * 
     * @throws Exception
     */
    @Test
    public void testRemoveNode() throws Exception {
        graph.addNode(A);
        graph.addNode(B);
        graph.addNode(C);
        graph.addEdge(A, C, 10);
        assertTrue(graph.numNodes() == 3);
        graph.removeNode(C);
        assertTrue(graph.numNodes() == 2);
    }

    /**
     * Control that the PriorityQueue removes correctly the edge requested
     * 
     * @throws Exception
     */
    @Test
    public void testRemoveEdge() throws Exception {
        graph.addNode(D);
        graph.addNode(E);
        graph.addNode(F);
        graph.addNode(D);
        graph.addNode(G);
        graph.addNode(H);
        graph.addEdge(D, E, 1);
        graph.addEdge(F, D, 6);
        graph.addEdge(H, G, 4);
        graph.addEdge(D, G, 7);
        graph.addEdge(H, E, 7);
        assertTrue(graph.numEdges() == 5);
        graph.removeEdge(D, E);
        graph.removeEdge(H, G);
        assertTrue(graph.numEdges() == 3);
    }

}
