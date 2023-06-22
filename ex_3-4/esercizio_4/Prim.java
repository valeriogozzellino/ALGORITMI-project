package esercizio_4;

import java.util.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * @author Alessandro, Sofia, Valerio
 */

public class Prim {
    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(
            Graph<V, L> graph) {

        Comparator<V> comparator = new Comparator<V>() {
            public int compare(V o1, V o2) {
                Node O1 = (Node) o1;
                Node O2 = (Node) o2;

                if (O1.key > O2.key) {
                    return 1;
                } else if (O1.key < O2.key) {
                    return -1;
                } else {
                    return 0;
                }
            }
        };

        /* A <-- ø */
        Graph<V, L> mst = new Graph<>(false, true);

        if (graph.numNodes() == 0) {
            return mst.getEdges();
        }

        /* Q <-- MAKEPRIORITYQUEUE(V) */
        PriorityQueue<V> queue = new PriorityQueue<>(comparator);
        for (V node : graph.getNodes()) { // inserisce tutti i nodi nella priorityqueue
            queue.push(node);
        }
        System.out.println("num Nodi nella coda: " + queue.heap.size());

        /* r.key <-- 0 */
        Node TopNode = (Node) queue.top();
        TopNode.setKey(0);

        int i = graph.numNodes() - 1;

        /* while(Q ≠ ø) Do */
        while (!queue.empty()) { // fino a quando ho nodi da scoprire ci saranno elementi nella coda

            /* u <-- EXTRACTMIN(Q) */
            Node u = (Node) queue.top();
            // System.out.println("il top è " + u.id + " con key " + u.key);
            queue.pop();
            i--;

            if (u.id_parent != null && u.id != null) {
                L convertedValue = (L) Double.valueOf((double) graph.getLabel((V) u.id_parent, (V) u));
                mst.addNode((V) u.id_parent);
                mst.addNode((V) u);
                // System.out.println(u.id_parent.id + " -- (" + convertedValue + ") -- " +
                // u.id);
                mst.addEdge((V) u.id_parent, (V) u, convertedValue);
            }

            /* FOR ALL V IN ADJ[U] AND V IN Q DO */
            for (V adjNode : graph.getNeighbours((V) u)) {

                if (queue.contains(adjNode)) {
                    Node v = (Node) adjNode;

                    if (v.key > (double) graph.getLabel((V) u, (V) v)) {
                        v.setKey((double) graph.getLabel((V) u, (V) v));
                        v.setParent(u);
                        queue.buildMaxHeap(i);
                    }

                }

            }
        }
        System.out.println("Num nodi minimi MST-------> " + mst.numNodes());
        return mst.getEdges();
    }

    public static void main(String[] args) {

        Graph<Node, Double> graph = new Graph<>(false, true);

        String path_rd = "ex_3-4/italian_dist_graph.csv";
        String record = "";
        try {
            BufferedReader br = new BufferedReader(new FileReader(path_rd));
            record = br.readLine();
            while (record != null) {

                String[] splits = record.split(",");
                Node node1 = new Node(splits[0], null, Float.MAX_VALUE);
                graph.addNode(node1);
                Node node2 = new Node(splits[1], null, Float.MAX_VALUE);
                graph.addNode(node2);
                graph.addEdge(node1, node2, Double.parseDouble(splits[2]));
                record = br.readLine();
            }
            System.out.println("Albero di Copertura Minimo:");
            Collection<? extends AbstractEdge<Node, Double>> minimumSpanningTree = minimumSpanningForest(graph);
            double totalweigth = 0;
            for (AbstractEdge<Node, Double> edge : minimumSpanningTree) {
                totalweigth = totalweigth + edge.getLabel().doubleValue();
            }

            System.out.println("weigth totale MST----> " + totalweigth);
            System.out.println("numero edges MST:---> " + minimumSpanningTree.size());
            System.out.println("numero di nodi inseriti GRAFO: " + graph.numNodes());
            System.out.println("numero di archi inseriti GRAFO:   " + graph.numEdges());
            System.out.println("Complessità dell'algoritmo:");
            System.out.println("  - Complessità temporale: O(|E| log |V|)");
            System.out.println("  - Complessità spaziale: O(|V| + |E|)");
            br.close();
        } catch (IOException e) {
            e.printStackTrace();

        }
    }
}
