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

// TODO: finish this function
void DoublyLinkedList::addToEnd(int newValue) {
	
}

// TODO: finish this function
int DoublyLinkedList::deleteAtFront() {
	return -1; // TODO: fix this
}

// TODO: finish this function
int DoublyLinkedList::deleteNode(int targetValue) {
	return -1; // TODO: fix this
}

// TODO: BONUS ONLY finish this function
void DoublyLinkedList::addToFront(int newValue) {
	
}

// TODO: BONUS ONLY finish this function
int DoublyLinkedList::deleteAtEnd() {
	return -1; // TODO: BONUS ONLY fix this
}

// TODO: BONUS ONLY finish this function
void DoublyLinkedList::insertInOrder(int newValue) {
	
}
