package esercizio_4;

/**
* @author Alessandro, Sofia, Valerio
*/

public interface AbstractEdge<V, L> {
    public V getStart(); /*node of the start of the edge*/ 

    public V getEnd(); /*node of the end of the edge*/ 

    public L getLabel(); /* label of the edge */
};
