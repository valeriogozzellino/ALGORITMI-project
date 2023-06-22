package esercizio_4;

import java.util.AbstractCollection;

/**
* @author Alessandro, Sofia, Valerio
*/

public interface AbstractGraph<V, L> {
    public boolean isDirected(); /* tell you if the graph is directed  -- O(1)*/

    public boolean isLabelled(); /* tell you if the graph is labelled -- O(1)*/

    public boolean addNode(V a); /* add a node -- O(1) */

    public boolean addEdge(V a, V b, L l); /* add a edge taking two node (start and end) and label -- O(1)*/ 

    public boolean containsNode(V a); /* control if a node is contained -- O(1) */

    public boolean containsEdge(V a, V b); /* control if a edge is contained -- O(1) */

    public boolean removeNode(V a); /* remove a node from a graph -- O(N)*/

    public boolean removeEdge(V a, V b); /* remove a edge from a graph -- O(1)*/

    public int numNodes(); /* number of nodes -- O(1)*/ 

    public int numEdges(); /* number of edges -- O(N)*/ 

    public AbstractCollection<V> getNodes(); /* get nodes from a graph -- O(N)*/

    public AbstractCollection<AbstractEdge<V, L>> getEdges(); /* get edges from a graph -- O(N)*/

    public AbstractCollection<V> getNeighbours(V a); /* get nodes adjacent of a node -- O(1)*/ 

    public L getLabel(V a, V b); /* get label from a graph -- O(1)*/ 
};
