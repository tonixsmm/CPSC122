/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 4, 2023
Programming Assignment: PA6
Description: This program implements several tasks required by PA6
*/

#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	// free each Node's memory in the list
	destroyList();
}

void LinkedList::destroyList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		// save the link to the next node
		nextNode = currNode->next;
		// can safely delete currNode
		delete currNode;
		currNode = nextNode;
	}
	head = NULL; // for good practice
}

void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

/*
Function: insertAtFront()
 * Date Created: 04/14/2023
 * Date Last Modified: 04/14/2023
 * Description: This function inserts a node to the front of a linked list
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a LinkedList class member function
*/
void LinkedList::insertAtFront(string newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;

	if (head == NULL){
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}

/*
Function: deleteAtFront()
 * Date Created: 04/14/2023
 * Date Last Modified: 04/14/2023
 * Description: This function deletes and returns the value of the node at the front of a linked list
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a LinkedList class member function
*/
string LinkedList::deleteAtFront() {
	string value = "";
	if (head != NULL){
		Node * curr = head;
		head = curr->next;
		value = curr->value;
		delete curr;
	}
	return value;
}