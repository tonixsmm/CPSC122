#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    tail = NULL;
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
    // For good practice
    head = NULL;
    tail = NULL;
}

void LinkedList::insertAtFront(int newValue){
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    // 2 case
    if (head == NULL){
        head = newNode;
		tail = newNode;
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
    cout << "tail -> ";
    if (tail == NULL){
        cout << "NULL" << endl;
    } 
    else {
        cout << tail->value << endl;
    }
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
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LinkedList::insertInOrder(int newValue){
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL){
        head = newNode;
		tail = newNode;
    }
    else {
        Node * currNode = head;
        while (currNode != NULL && currNode->value < newValue){
            currNode = currNode->next;
        }
        
        if (currNode == head){
            currNode->prev = newNode;
            head = newNode;
			newNode->next = currNode;
        }
		else if (currNode == NULL){
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
        else {
            currNode->prev->next = newNode;
            newNode->prev = currNode->prev;
            currNode->prev = newNode;
			newNode->next = currNode;
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
        else { // If the list is empty, both head and tail is NULL
            tail = NULL;
        }            
        delete nodeToDelete;
    }
}

void LinkedList::deleteAtEnd(){
    if (head != NULL) {
        if (head == tail){
            delete head;
            head = NULL;
			tail = NULL;
        }
        else {
			Node * nodeToDelete = tail;
            tail->prev->next = NULL;
			tail = tail->prev;
			delete nodeToDelete;
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
            else {
                tail = NULL;
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
                if (currNode->next != NULL){ // Checking if there is a next node
                    currNode->next->prev = currNode->prev;
                }
                else {
                    tail = currNode->prev;
                }
                delete currNode;
            }
        }
    }
}

void LinkedList::displayListInReverseOrder(){
    Node * curr = tail;

    cout << "Tail -> ";
    while (curr != NULL){
        cout << curr->value;
        cout << " -> ";
        curr = curr->prev;
    }
    cout << "Head" << endl;
}