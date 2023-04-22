#include "DoublyLinkedQueue.h"

void DoublyLinkedQueue::displayQueue() {
	Node * currNode = head;
	
	while (currNode != NULL) {
		cout << currNode->value << " ";
		// progress towards BC being false
		currNode = currNode->next;
	}
	cout << endl;
}

void DoublyLinkedQueue::enqueue(int newValue) {
	addToEnd(newValue);
}

int DoublyLinkedQueue::dequeue() {
	return deleteAtFront();
}

void DoublyLinkedQueue::clear() {
	destroyList();
}

bool DoublyLinkedQueue::isEmpty() {
	return head == NULL;
}

int DoublyLinkedQueue::size() {
	int count = 0;
	Node * curr = head;

	while (curr != NULL){
		curr = curr->next;
		count++;
	}
	return count;
}

// TODO: finish this function
void DoublyLinkedQueue::removeDivisibleBy(int p) {
	
}

