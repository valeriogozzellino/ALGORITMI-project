package esercizio_4;

/**
* @author Alessandro, Sofia, Valerio
*/

public class Node {
    String id; /* Identifier of node */
    double key; /* key to verify its priority between nodes found */
    Node id_parent; /* node of the node's parent for the path minimum */

    public Node(String id, Node id_parent, double key) {
        this.id = id;
        this.id_parent = id_parent;
        this.key = key;
    }

    public double getKey() {
        return this.key;
    }

    public void setKey(double newKey) {
        key = newKey;
    }

    public void setParent(Node parent) {
        id_parent = parent;
    }

    @Override
    public int hashCode() {
        return id.hashCode();
    }

    @Override
    public boolean equals(Object obj) {

        Node otherNode = (Node) obj;

        // Confronta solo l'identificatore (id)
        return id.equals(otherNode.id);

    }

}