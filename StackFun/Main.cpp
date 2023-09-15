#include "LinkedList.h"
#include "Stack.h"

int main(){
    Stack stack; // Start out with empty stack
    // Invoke the default DVC of Stack, which will involve the DVC LinkedList
    // Inheritance: Superclass constructor execute first before the subclass, and the opposite for destructor

    // It is okay to push and pop with chars with out stack. Each node in the LinkedList stores an ASCII value int
    string toReverse = "Stack ADTs are awesome!!";
    int asciiValue = -1;
    for (char c : toReverse){
        stack.push(c);
    }
    cout << stack.size() << endl;
    cout << "Output: ";
    while (!stack.isEmpty()){
        asciiValue = stack.pop();
        cout << static_cast<char>(asciiValue);
    }
    cout << endl;


    // stack.push(5);
    // stack.push(3);
    // cout << "Peek: " << stack.peek() << endl;
    // cout << "isEmpty: " << stack.isEmpty() << endl;
    // cout << "Size: " << stack.size() << endl;

    // cout << "----" << endl;
    // int value = -1;
    // value = stack.pop();
    // cout << "Pop value: " << value << endl;
    // cout << "Peek: " << stack.peek() << endl;
    // cout << "isEmpty: " << stack.isEmpty() << endl;
    // cout << "Size: " << stack.size() << endl;

    // cout << "----" << endl;
    // stack.push(5);
    // stack.push(3);
    // stack.clear();
    // cout << "Stack cleared" << end;
    // cout << "Peek: " << stack.peek() << endl;
    // cout << "isEmpty: " << stack.isEmpty() << endl;
    // cout << "Size: " << stack.size() << endl;


    // LinkedList list; // Start out empty
    
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