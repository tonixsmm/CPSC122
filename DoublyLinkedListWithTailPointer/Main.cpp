#include "LinkedList.h"

int main(){
    LinkedList list; // Start out empty

    list.append(3);
    list.append(5);
    list.append(12);
    list.displayList();
    list.deleteNode(5);
    list.displayList();
    list.displayListInReverseOrder();
    // list.displayListInReverseOrder();
    
    // list.insertAtFront(12);
    // list.insertAtFront(5);
    // list.insertAtFront(3);
    // list.displayList();

    // list.append(15);
    // list.displayList();

    // list.insertInOrder(7);
    // list.displayList();
    // list.insertInOrder(2);
    // list.displayList();
    // list.insertInOrder(15);
    // list.displayList();
    /* TERMIAL
    Head -> 3 -> 5 -> 12 -> NULL
    Head -> 3 -> 5 -> 12 -> 15 -> NULL
    Head -> 3 -> 5 -> 7 -> 12 -> 15 -> NULL
    Head -> 2 -> 3 -> 5 -> 7 -> 12 -> 15 -> NULL
    Head -> 2 -> 3 -> 5 -> 7 -> 12 -> 15 -> 15 -> NULL
    */


    // list.deleteAtFront();
    // list.displayList();
    // list.deleteAtFront();
    // list.displayList();
    // list.deleteAtFront();
    // list.displayList();
    /* TERMINAL
    Head -> 3 -> 5 -> 12 -> NULL
    Head -> 5 -> 12 -> NULL
    Head -> 12 -> NULL
    Head -> NULL
    */

    // list.deleteAtEnd();
    // list.displayList();
    // list.deleteAtEnd();
    // list.displayList();
    // list.deleteAtEnd();
    // list.displayList();
    /* TERMINAL
    Head -> 3 -> 5 -> 12 -> NULL
    Head -> 3 -> 5 -> NULL
    Head -> 3 -> NULL
    Head -> NULL
    */

    // list.deleteNode(50);
    // list.displayList();
    // list.deleteNode(3); // Delete first node
    // list.displayList();
    // list.deleteNode(5);
    // list.displayList();
    // list.deleteNode(12);
    // list.displayList();
    /* TERMINAL
    Head -> 3 -> 5 -> 12 -> NULL
    Head -> 3 -> 5 -> 12 -> NULL
    Head -> 5 -> 12 -> NULL
    Head -> 12 -> NULL
    Head -> NULL
    */

    return 0;
}