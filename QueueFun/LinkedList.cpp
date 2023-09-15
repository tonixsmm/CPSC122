#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    tail = NULL;
}

LinkedList::~LinkedList(){
    destroyList();
}

void LinkedList::destroyList(){
    // TODO: Free each Node's memory in the list
    Node * currNode = head;
    Node * nextNode = nullptr;

    while (currNode != nullptr){
        // Save the link to the next node
        nextNode = currNode -> next;
        // Now we can safely delete currNode
        delete currNode;
        currNode = nextNode;
    }
    head = NULL;
    tail = NULL;
}

void LinkedList::displayList(){
    Node * currNode = head;

    cout << "Head -> ";
    while (currNode != nullptr){
        cout << currNode -> value << " -> ";
        //Progress towards BC being false
        currNode = currNode -> next;
    }
    cout << "NULL" << endl;
    if (tail != NULL){
        cout << "Tail -> " << tail->value << endl;
    }
    else{
        cout << "Tail -> NULL" << endl;
    }
}

void LinkedList::append(int newValue){
    // Make a new Node
    Node * newNode = new Node;
    newNode -> value = newValue;
    newNode -> next = nullptr;

    // 2 case
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        // List is not empty. Need to traverse the list, stop at the last node
        tail->next = newNode;
        tail = newNode;
    }
}

int LinkedList::deleteAtFront(){
    // Check to make sure there is something to delete
    int value = -1;
    if (head != nullptr){
        Node * nodeToDelete = head;
        head = head -> next;
        value = nodeToDelete->value;            
        delete nodeToDelete;
    }

    if (head == NULL){
        tail = NULL;
    }
    return value;
}

void LinkedList::insertInOrder(int newValue){
    // Make a new Node
    Node * newNode = new Node;
    newNode -> value = newValue;
    newNode -> next = nullptr;

    // 2 case
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        Node * prevNode = nullptr;

        while (currNode != nullptr && currNode -> value > newValue){ // Change to > to have a descending list
            prevNode = currNode;
            currNode = currNode -> next;
        }
        
        // 2 cases to check
            // 1. inserting at head, so we didn't advance currNode (therefore prevNode is NULL)
            // 2. inserting somewhere other than the head, need to do the slicing
            if (prevNode == nullptr){
                head = newNode;
                newNode -> next = currNode;
            }
            else {
                prevNode -> next = newNode;
                newNode -> next = currNode;

                if (newNode->next == NULL){
                    tail = newNode;
                }
            }
    }
}