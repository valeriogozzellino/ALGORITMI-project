package esercizio_4;

import java.util.*;

/**
* @author Alessandro, Sofia, Valerio
*/

public class Graph<V, L> implements AbstractGraph<V, L> {
    private boolean directed;
    private boolean labelled;
    private Map<V, List<AbstractEdge<V, L>>> adjacencyMap;
    private int numEdges;

    /* Constructor of Graph's class */
    public Graph(boolean directed, boolean labelled) {
        this.directed = directed;
        this.labelled = labelled;
        this.adjacencyMap = new HashMap<>();
        this.numEdges = 0;
    }

    public boolean isDirected() {
        return directed;
    }

    public boolean isLabelled() {
        return labelled;
    }

    public boolean addNode(V a) {
        if (!containsNode(a)) {
            adjacencyMap.put(a, new ArrayList<>());
            return true;
        }
        return false;
    }

    public boolean addEdge(V a, V b, L l) {
        if (!containsEdge(a, b)) {

            adjacencyMap.get(a).add(createEdge(a, b, l));

            if (!directed) {

                adjacencyMap.get(b).add(createEdge(b, a, l));

            }

            numEdges++;

            return true;
        }

        return false;
    }

    public boolean containsNode(V a) {
        return adjacencyMap.containsKey(a);// VALORE
    }

    public boolean containsEdge(V a, V b) {
        if (containsNode(a)) {
            List<AbstractEdge<V, L>> edges = adjacencyMap.get(a);
            for (AbstractEdge<V, L> edge : edges) {
                if (edge.getEnd().equals(b)) { /* controls if edge exists */

                    return true;
                }
            }
            return false;

        }
        return false;
    }

    public boolean removeNode(V a) {
        if (containsNode(a)) {
            List<AbstractEdge<V, L>> edges = adjacencyMap.get(a); /* Alias della lista di adiacenza del vertice 'a' */
            numEdges -= edges.size(); /* num di archi meno il numero degli archi presenti nella lista da rimuovere */
            adjacencyMap.remove(a);

            if (!directed) { /*
                              * In caso il grafo non fosse diretto, si ha che per ogni arco (a,b), esiste
                              * anche un arco (b,a), che deve anch'esso essere rimosso dalla lista di
                              * adiacenza
                              */

                for (List<AbstractEdge<V, L>> neighborEdges : adjacencyMap.values()) { /*
                                                                                        * Per ogni lista di archi
                                                                                        * 'neighborEdges' presente nella
                                                                                        * lista di adiacenza, esegui il
                                                                                        * codice compreso nel ciclo
                                                                                        */
                    neighborEdges.removeIf(edge -> edge.getEnd().equals(a)); /*
                                                                              * Rimuove ogni arco (x,a) che parte dal
                                                                              * generico vertice 'x' e lo collega con il
                                                                              * vertce rimosso 'a'
                                                                              */
                }
                return true;
            }
            return false;
        }

        return true;
    }

    /*
     * removeEdge è la funzione che rimuove l'arco (a,b) (se i suddetti vertici
     * esistono).
     * Eseguo la get(a) per avere la chiave della lista di adiacenza di a, e la
     * inserisco in una lista di appoggio.
     * elimino gli archi che partono da a, i quali hanno come destinazione b.
     * Nel caso il grafo non fosse diretto, ovvero per ogni arco che va da a in b,
     * ho anche un arco contrario che va da b ad a.
     * allora rimuovo anche quello con un operazione equivalente e speculare alla
     * prima. (sul vertice a).
     */

    public boolean removeEdge(V a, V b) {
        boolean remove = false;
        if (containsNode(a) && containsNode(b)) {
            List<AbstractEdge<V, L>> edges = adjacencyMap.get(a); /* Alias della lista di adiacenza del vertice 'a' */
            remove = edges.removeIf(edge -> edge.getEnd().equals(b)); /*
                                                                       * Se nella lista di adiacenza di 'a', esiste un
                                                                       * arco con destinazione 'b', questo va rimosso
                                                                       */

            if (remove) {
                numEdges--;

                if (!directed) { /* in caso il grafo non fosse diretto, devo eliminare anche l'arco (b,a) */
                    List<AbstractEdge<V, L>> closeEdges = adjacencyMap.get(b);
                    closeEdges.removeIf(edge -> edge.getEnd().equals(a));
                }
            }
        }
        return remove;
    }

    /**
     * Create an edge needs three function
     */
    private AbstractEdge<V, L> createEdge(V start, V end, L label) {

        return new AbstractEdge<V, L>() {

            public V getStart() {

                return start;
            }

            public V getEnd() {

                return end;
            }

            public L getLabel() {

                return label;
            }

            @Override
            public String toString() {

                return "Edge: " + getStart() + " -> " + getEnd() + ", Label: " + getLabel() + "|";
            }

        };
    }

    public int numNodes() {
        return adjacencyMap.size();
    }

    /* Ritorna il numero degli archi */
    public int numEdges() {
        return numEdges;
    }

    /*
     * Returns a list of adjacency that contains all of collections of nodes' keys
     * in the graph
     */
    public AbstractCollection<V> getNodes() {
        return new ArrayList<>(adjacencyMap.keySet());
    }

    /*
     * Returns a collection of all the edges in the graph
     */
    public AbstractCollection<AbstractEdge<V, L>> getEdges() {
        AbstractCollection<AbstractEdge<V, L>> collection = new ArrayList<AbstractEdge<V, L>>();

        if (!directed) {
            Set<V> nodes_list = adjacencyMap.keySet();
            List<V> node_visited = new ArrayList<>();

            for (V node : nodes_list) {
                List<AbstractEdge<V, L>> edges = adjacencyMap.get(node);
                if (!node_visited.contains(node)) {
                    node_visited.add(node);
                    for (AbstractEdge<V, L> edge : edges) {
                        if (!node_visited.contains(edge.getEnd())) {
                            collection.add(edge);
                        }
                    }
                }
            }
        } else {
            for (List<AbstractEdge<V, L>> closeEdges : adjacencyMap.values()) {
                collection.addAll(closeEdges);
            }
        }
        collection.toString();
        return collection;
    }

    /* get collection of adjacenced nodes of a determined node */
    public AbstractCollection<V> getNeighbours(V a) {
        AbstractCollection<V> collection = new ArrayList<V>();
        List<AbstractEdge<V, L>> neighbours = adjacencyMap.get(a);

        for (AbstractEdge<V, L> edge : neighbours) {
            if (edge.getEnd() != null) {
                collection.add(edge.getEnd());
            }

        }

        return collection;
    }

    public L getLabel(V a, V b) {

        List<AbstractEdge<V, L>> neighbours = adjacencyMap.get(a);

        if (neighbours != null) {
            for (AbstractEdge<V, L> edge : neighbours) {
                if (edge.getEnd().equals(b)) {
                    return edge.getLabel();
                }
            }
        }

        return null;
    }

}
