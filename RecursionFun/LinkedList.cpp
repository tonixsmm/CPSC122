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
        nextNode = currNode -> next;
        // Now we can safely delete currNode
        delete currNode;
        currNode = nextNode;
    }
}

void LinkedList::insertAtFront(int newValue){
    // Make a new Node
    // Same for all "add" functions
    Node * newNode = new Node;
    newNode -> value = newValue;
    newNode -> next = nullptr;

    // 2 case
    if (head == nullptr){
        head = newNode;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
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
}

void LinkedList::displayListRecursiveHelper(Node * currNode){
    if (currNode == head){
        cout << "head->";
    }
    if (currNode == NULL){
        cout << "NULL" << endl;
        return;
    }
    cout << currNode->value << "->";
    // Recursive step
    displayListRecursiveHelper(currNode->next);
}

void LinkedList::displayListRecursive(){
    // Public interface function
    // Node and head are private. That's why we need this head function "getter/setter"
    displayListRecursiveHelper(head);
}

void LinkedList::displayListReverseHelper(Node * currNode){
    if (currNode == NULL){
        cout << "NULL";
        return;
    }
    // Recursive step
    displayListReverseHelper(currNode->next);
    cout << "<-" << currNode->value;
    if (currNode == head){
        cout << "<-head" << endl;
    }
}

void LinkedList::displayListReverse(){
    // Public interface function
    // Node and head are private. That's why we need this head function "getter/setter"
    displayListRecursiveHelper(head);
}

void LinkedList::append(int newValue){
    // Make a new Node
    Node * newNode = new Node;
    newNode -> value = newValue;
    newNode -> next = nullptr;

    // 2 case
    if (head == nullptr){
        head = newNode;
    }
    else {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        while (currNode -> next != nullptr){
            currNode = currNode -> next;
        }
        // currNode is pointing to the last node in the list
        currNode -> next = newNode;
    }
}

void LinkedList::insertInOrder(int newValue){
    // Make a new Node
    Node * newNode = new Node;
    newNode -> value = newValue;
    newNode -> next = nullptr;

    // 2 case
    if (head == nullptr){
        head = newNode;
    }
    else {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        Node * prevNode = nullptr;

        while (currNode != nullptr && currNode -> value < newValue){
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
            }
    }
}

void LinkedList::deleteAtFront(){
    // Check to make sure there is something to delete
    if (head != nullptr){
        Node * nodeToDelete = head;
        head = head -> next;            
        delete nodeToDelete;
    }
}

void LinkedList::deleteAtEnd(){
    if (head != nullptr) {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        Node * prevNode = nullptr;
        while (currNode -> next != nullptr){
            prevNode = currNode;
            currNode = currNode -> next;
        }
        if (prevNode == nullptr){ // OR currNode == head
            // Deleting at head. Only one item/Node in the list
            delete head;
            head = nullptr; // We now have an empty list
        }
        else {
            delete currNode;
            prevNode -> next = nullptr;
        }
    }
}

void LinkedList::deleteNode(int targetValue){
    if (head != nullptr) {
        // List is not empty. Need to traverse the list, stop at the last node
        Node * currNode = head;
        // Check case 2 is occurring - The node to delete is the first node
        if (head -> value == targetValue){
            head = head -> next;
            delete currNode;
        }
        else { // Check case 3 - The ndoe to delete is not the first node, or might not even in the list at all
            Node * prevNode = nullptr;
            while (currNode != nullptr && currNode -> value != targetValue){
                prevNode = currNode;
                currNode = currNode -> next;
            }
            // Check if we found targetValue
            if (currNode != nullptr){
                // We did find it
                prevNode -> next = currNode -> next;
                delete currNode;
            }
        }
    }
}