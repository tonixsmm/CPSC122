#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// A linked list of Nodes. Each Node stores a single integer value can be expanded to store multiple values or templated to store any value type
class LinkedList {
    // Self-referential
    protected: // Change from private to protected so that Stack can access head
        struct Node {
            int value;  // Dtata value Node stores
            struct Node * next; // Points to next Node in the list
            struct Node * prev;
        };
        Node * head;    // List head pointer
        Node * tail;
    
    public:
        LinkedList();   // DVC
        ~LinkedList();  // Destructor

        // common linked list operations
        void insertAtFront(int);
        void displayList();
        void append(int); // aka insert at end
        void insertInOrder(int);
        int deleteAtFront();
        void deleteAtEnd();
        void deleteNode(int);
        void destroyList();
};

#endif