/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 23, 2023
Programming Assignment: PA8
Description: This program implements several tasks required by PA8
*/

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
	// free each Node's memory in the list
	destroyList();
}

Node * DoublyLinkedList::getHead() const {
	return head;
}

Node * DoublyLinkedList::getTail() const {
	return tail;
}

void DoublyLinkedList::setHeadAndTail(Node * newHead, Node * newTail) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
	tail = newTail;
}

void DoublyLinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;

	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
	tail = NULL;
}

void DoublyLinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "<->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
	if (tail != NULL) {
		cout << "tail->" << tail->value << endl;
	}
	else {
		cout << "tail->NULL" << endl;
	}
}

/*
Function: addToEnd()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function inserts a node to the end of a doubly-linked list
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
void DoublyLinkedList::addToEnd(int newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL){
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

/*
Function: deleteAtFront()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function deletes the node at the head of a doubly-linked list
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
int DoublyLinkedList::deleteAtFront() {
	int value = -1;
	if (head != NULL){
		Node * nodeToDelete = head;
		head = head->next;

		if (head != NULL){
			head->prev = NULL;
		}
		else{
			tail = NULL;
		}
		value = nodeToDelete->value;
		delete nodeToDelete;
	}
	return value; 
}

/*
Function: deleteNode()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function deletes a node in a doubly-linked list based on a provided value and 
 				returns that value
 * Input parameters: An int
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
int DoublyLinkedList::deleteNode(int targetValue) {
	int value = -1;
	if (head != NULL) {
        Node * currNode = head;

        if (head->value == targetValue){
            head = head->next;
            if (head != NULL){
                head->prev = NULL;
            }
            else {
                tail = NULL;
            }
			value = currNode->value;
            delete currNode;
        }

        else {
            while (currNode != NULL && currNode->value != targetValue){
                currNode = currNode->next;
            }
        
            if (currNode != NULL){
                currNode->prev->next = currNode->next;
                if (currNode->next != NULL){
                    currNode->next->prev = currNode->prev;
                }
                else {
                    tail = currNode->prev;
                }
				value = currNode->value;
                delete currNode;
            }
        }
    }
	return value;
}

/*
Function: addToFront()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function inserts a node to the head of a doubly-linked list
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
void DoublyLinkedList::addToFront(int newValue) {
    Node * newNode = new Node;
    newNode->value = newValue;
    newNode->next = NULL;
    newNode->prev = NULL;

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

/*
Function: deleteAtEnd()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function deletes the node at the end of a doubly-linked list and returns the value 
  				of that node
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
int DoublyLinkedList::deleteAtEnd() {
	int value = -1;
	if (head != NULL) {
        if (head == tail){
			value = head->value;
            delete head;
            head = NULL;
			tail = NULL;
        }
        else {
			Node * nodeToDelete = tail;
            tail->prev->next = NULL;
			tail = tail->prev;
			value = nodeToDelete->value;
			delete nodeToDelete;
        }
    }
	return value;
}

/*
Function: insertInOrder()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function inserts a node in order to a doubly-linked list
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
void DoublyLinkedList::insertInOrder(int newValue) {
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
