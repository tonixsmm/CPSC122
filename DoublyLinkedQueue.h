/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 23, 2023
Programming Assignment: PA8
Description: This program implements several tasks required by PA8
*/

#ifndef DOUBLY_LINKED_QUEUE_H
#define DOUBLY_LINKED_QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

class DoublyLinkedQueue : public DoublyLinkedList {
    public:    
		// common queue operations
		// implementation provided
		void displayQueue();

		// implementations not provided
		void enqueue(int);
		int dequeue();
		void clear();
		bool isEmpty();
		int size();

		// sieve specific queue operation
		// implementation not provided
		void removeDivisibleBy(int);

};

#endif
