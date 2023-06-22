package esercizio_4;

import java.util.*;

/**
* @author Alessandro, Sofia, Valerio
*/

public class MainGraph {
    public static void main(String[] args) {
        Graph<String, Integer> graph = new Graph<>(true, true);

        graph.addNode("A");
        graph.addNode("B");
        graph.addNode("C");
        graph.addNode("D");
        graph.addNode("E");
        graph.addNode("F");
        graph.addNode("G");
        graph.addNode("H");
        graph.addEdge("A", "B", 8);
        graph.addEdge("A", "C", 3);
        graph.addEdge("B", "D", 5);
        graph.addEdge("D", "E", 4);
        graph.addEdge("F", "E", 7);
        graph.addEdge("E", "H", 9);

        if (!graph.isDirected()) {
            System.out.println("-----TEST NON DIRETTO-----");
            System.out.println("edge E-->D: exp(true)---->" + graph.containsEdge("E", "D"));
            System.out.println("edge E-->F: exp(true)---->" + graph.containsEdge("E", "F"));
            System.out.println("edge E-->G: exp(false)---->" + graph.containsEdge("E", "G"));

        }
        System.out.println(" ");

        if (graph.isDirected()) {
            System.out.println("-----TEST CONTAINS EDGE-----");
            System.out.println("edge A-->B: exp(true)---->" + graph.containsEdge("A", "B"));
            System.out.println("edge D-->E: exp(true)---->" + graph.containsEdge("D", "E"));
            System.out.println("edge F-->E: exp(true)---->" + graph.containsEdge("F", "E"));
            System.out.println("edge E-->G: exp(false)---->" + graph.containsEdge("E", "G"));
            System.out.println("edge E-->D: exp(false)---->" + graph.containsEdge("E", "D"));
            System.out.println("edge E-->F: exp(false)---->" + graph.containsEdge("E", "F"));
        }
        System.out.println(" ");
        System.out.println("-----TEST num Egde -----");
        System.out.println("numedge: exp(6)---->" + graph.numEdges());

        System.out.println(" ");
        System.out.println("-----TEST NUM NODE -----");
        System.out.println("numNODI: exp(8)---->" + graph.numNodes());

        System.out.println(" ");
        System.out.println("-----TEST GETLABEL -----");
        System.out.println("LABEL A-->B: exp(8)---->" + graph.getLabel("A", "B"));
        System.out.println("LABEL D-->E: exp(4)---->" + graph.getLabel("D", "E"));
        System.out.println("LABEL E-->H: exp(9)---->" + graph.getLabel("E", "H"));

        System.out.println(" ");
        System.out.println("-----TEST CONTAINS NODE-----");
        System.out.println("B: exp(true)---->" + graph.containsNode("B"));
        System.out.println("E: exp(true)---->" + graph.containsNode("E"));
        System.out.println("P: exp(false)---->" + graph.containsNode("P"));
        System.out.println("G: exp(true)---->" + graph.containsNode("G"));
        System.out.println(" ");
        System.out.println("-----TEST CONTAINS NODE-----");
        System.out.println("remove A--->B: exp(true)---->" + graph.removeEdge("A", "B"));
        System.out.println("numEdge dopo remove: exp(5)---->" + graph.numEdges());
        System.out.println(" ");

        System.out.println("-----TEST REMOVE NODE-----");
        System.out.println("remove NODE: exp(true)---->" + graph.removeNode("A"));
        System.out.println("NO");
        System.out.println(" ");

        System.out.println("-----TEST COLLECTION EGDE-----");
        System.out.println("collection EDGE: ---->" + graph.getEdges());
        System.out.println(" ");

        System.out.println("-----TEST COLLECTION NODE-----");
        System.out.println("collection NODE: ---->" + graph.getNodes());
        System.out.println(" ");

        System.out.println("-----TEST GET NEIGHBOURS-----");
        System.out.println("ADIACENTI DI (B): ---->exp(D)" + graph.getNeighbours("B"));

    }

}