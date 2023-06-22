package esercizio_4;

/**
* @author Alessandro, Sofia, Valerio
*/

public interface AbstractQueue<E> {
  public boolean empty(); /* control if the queue is empty -- O(1) */

  public boolean push(E e); /* add an element iìat the queue -- O(logN) */

  public boolean contains(E e); /* control if the queue contains the element e -- O(1) */

  public E top(); /* get the top of the queue -- O(1) */

  public void pop(); /* remove the element in the top of the queue -- O(logN) */

  public boolean remove(E e); /* remove an element (only if it exists) -- O(logN) */

  public void increase_priority();
  /*
   * increase the priority of an element if e1 == e2, else if replace with e2;
   * return true if the key is modified, else false
   */
};