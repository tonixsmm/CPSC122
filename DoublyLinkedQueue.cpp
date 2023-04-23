/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 23, 2023
Programming Assignment: PA8
Description: This program implements several tasks required by PA8
*/

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

/*
Function: enqueue()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function enqueues a value to a queue
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
void DoublyLinkedQueue::enqueue(int newValue) {
	addToEnd(newValue);
}

/*
Function: dequeue()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function dequeues the value at the front of a queue and returns that value
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
int DoublyLinkedQueue::dequeue() {
	return deleteAtFront();
}

/*
Function: clear()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function clears out a queue and sets head & tail to NULL
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
void DoublyLinkedQueue::clear() {
	destroyList();
}

/*
Function: isEmpty()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function checks if a queue is empty
 * Input parameters: None
 * Returns: Bool
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
bool DoublyLinkedQueue::isEmpty() {
	return head == NULL;
}

/*
Function: size()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function counts the number of value in a queue and returns that number
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
int DoublyLinkedQueue::size() {
	int count = 0;
	Node * curr = head;

	while (curr != NULL){
		curr = curr->next;
		count++;
	}
	return count;
}

/*
Function: removeDivisibleBy()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/22/2023
 * Description: This function checks if a value in a queue is divisible by a provided number. 
 				If so, the remove it out of the queue.
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
void DoublyLinkedQueue::removeDivisibleBy(int p) {
	Node * curr = head;
	while (curr != NULL){
		Node * nextNode = curr->next;
		if (curr->value % p == 0){
			deleteNode(curr->value);
		}
		curr = nextNode;
	}
}

