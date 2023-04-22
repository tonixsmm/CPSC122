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

// TODO: finish this function
void DoublyLinkedQueue::enqueue(int newValue) {

}

// TODO: finish this function
int DoublyLinkedQueue::dequeue() {
	return -1; // TODO: fix this
}

// TODO: finish this function
void DoublyLinkedQueue::clear() {

}

// TODO: finish this function
bool DoublyLinkedQueue::isEmpty() {
	return false; // TODO: fix this
}

// TODO: finish this function
int DoublyLinkedQueue::size() {
	return -1;  // TODO: fix this
}

// TODO: finish this function
void DoublyLinkedQueue::removeDivisibleBy(int p) {
	
}

