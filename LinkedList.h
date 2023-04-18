/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 17, 2023
Programming Assignment: PA7
Description: This program implements several tasks required by PA7
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class LinkedList {
	protected:
		struct Node {
			string value; 
			struct Node * next; 
		}; 

	   	Node * head; // list head pointer

	public:
	   	LinkedList(); // DVC
	   	~LinkedList(); // destructor
		  
	   	// common linked list operations
	   	void destroyList();
	   	void displayList();
	   	void insertAtFront(string);
	   	string deleteAtFront();
};

#endif
