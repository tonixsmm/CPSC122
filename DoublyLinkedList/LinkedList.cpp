#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::~LinkedList(){
    // TODO: Free each Node's memory in the list
    Node * currNode = head;
    Node * nextNode = nullptr;

    while (currNode != nullptr){
        // Save the link to the next node
        nextNode = currNode->next;
        // Now we can safely delete currNode
        delete currNode;
        currNode = nextNode;
    }
}

void LinkedList::insertAtFront(int newValue){
    // Make a new Node
    // Same for all "add" functions
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    // 2 case
    if (head == nullptr){
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::displayList(){
    Node * currNode = head;

    cout << "Head -> ";
    while (currNode != nullptr){
        cout << currNode->value << " -> ";
        //Progress towards BC being false
        currNode = currNode->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::append(int newValue){
    // Make a new Node
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    // 2 case
    if (head == nullptr){
        head = newNode;
    }
    else {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        while (currNode->next != nullptr){
            currNode = currNode->next;
        }
        // currNode is pointing to the last node in the list
        newNode->prev = currNode;
        currNode->next = newNode;
    }
}

void LinkedList::insertInOrder(int newValue){
    // Make a new Node
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = nullptr;
    newNode->prev = NULL;

    // 2 case
    if (head == nullptr){
        head = newNode;
    }
    else {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;

        while (currNode != nullptr && currNode->value < newValue){
            currNode = currNode->next;
        }
        
        // 2 cases to check
            // 1. inserting at head, so we didn't advance currNode (therefore prevNode is NULL)
            // 2. inserting somewhere other than the head, need to do the slicing
            if (currNode == head){
                currNode->prev = newNode;
                head = newNode;
                newNode->next = currNode;
            }
            else {
                currNode->prev->next = newNode;
                newNode->prev = currNode->prev;
                newNode->next = currNode;
                currNode->prev = newNode;
            }
    }
}

void LinkedList::deleteAtFront(){
    // Check to make sure there is something to delete
    if (head != nullptr){
        Node * nodeToDelete = head;
        head = head->next;

        if (head != NULL){ // Check if the list is not empty
            head->prev = NULL;
        }            
        delete nodeToDelete;
    }
}

void LinkedList::deleteAtEnd(){
    if (head != nullptr) {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        
        while (currNode->next != nullptr){
            currNode = currNode->next;
        }
        if (currNode == head){ // OR currNode == head
            // Deleting at head. Only one item/Node in the list
            delete head;
            head = nullptr; // We now have an empty list
        }
        else {
            currNode->prev->next = nullptr;
            delete currNode;
        }
    }
}

void LinkedList::deleteNode(int targetValue){
    if (head != nullptr) {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        // Check case 2 is occurring - The node to delete is the first node
        if (head->value == targetValue){
            head = head->next;
            if (head != NULL){
                head->prev = NULL;
            }
            delete currNode;
        }
        else { // Check case 3 - The ndoe to delete is not the first node, or might not even in the list at all
            while (currNode != nullptr && currNode->value != targetValue){
                currNode = currNode->next;
            }
            // Check if we found targetValue
            if (currNode != nullptr){
                // We did find it
                currNode->prev->next = currNode->next;
                if (currNode->next != NULL){
                    currNode->next->prev = currNode->prev;
                }
                delete currNode;
            }
        }
    }
}