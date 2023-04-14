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


