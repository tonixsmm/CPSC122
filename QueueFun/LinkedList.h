#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// A linked list of Nodes. Each Node stores a single integer value can be expanded to store multiple values or templated to store any value type
class LinkedList {
    // Self-referential
    protected:
        struct Node {
            int value;  // Dtata value Node stores
            struct Node * next; // Points to next Node in the list
            struct Node * prev;
        };
    
    protected:
        Node * head;    // List head pointer
        Node * tail;
    
    public:
        LinkedList();   // DVC
        ~LinkedList();  // Destructor

        // common linked list operations
        void displayList();
        void append(int); // aka insert at end
        int deleteAtFront();
        void destroyList();
        void insertInOrder(int);
};

#endif