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

void DoublyLinkedList::addToFront(int newValue) {
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
