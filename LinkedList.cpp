/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 30, 2023
Programming Assignment: PA9
Description: This program implements several tasks required by PA9
I attempted the ART Review Bonus
*/

#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	Node * currNode = head;
	Node * nextNode = NULL;
	
	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
	
	head = NULL;
}

void LinkedList::displayList() {
	Node * currNode = head;
	
	cout << "head->";
	while (currNode != NULL) {
		cout << currNode->value << "->";
		currNode = currNode->next;
	}
	cout << "NULL" << endl;
}

void LinkedList::appendNode(int newValue) {
	Node * newNode = new Node;
	newNode->value = newValue;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
	} 
	else {
		Node * currNode = head;
		while (currNode->next != NULL) {
			currNode = currNode->next;
		}
		currNode->next = newNode;
	}
}

/*
Function: getMaxValueHelper()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function returns the largest value in a doubly-linked list
 * Input parameters: An int, a Node pointer
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function. This is a helper function of LinkedList::getMaxValue()
*/
int LinkedList::getMaxValueHelper(Node *nodePtr, int largest) {
	if (head == NULL){
		return -1;
	}

	// Base case	
	if (nodePtr == NULL){
		return largest;
	}

	// Check condition
	if (nodePtr->value > largest){
		largest = nodePtr->value;
	}

	// Recursive step
	largest = getMaxValueHelper(nodePtr->next, largest);

	return largest;
}

/*
Function: getMaxValue()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function returns the largest value in a doubly-linked list
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedList class member function
*/
int LinkedList::getMaxValue() {
	int largest = -1;

	largest = getMaxValueHelper(head, largest);
	
	return largest;
}
