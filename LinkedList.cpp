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


// TODO: finish this function
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

	return largest;  // TODO: fix this
}


// TODO: finish this function
int LinkedList::getMaxValue() {
	int largest = -1;
	largest = getMaxValueHelper(head, largest);
	return largest; // TODO: fix this
}
