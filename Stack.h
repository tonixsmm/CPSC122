/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 4, 2023
Programming Assignment: PA6
Description: This program implements several tasks required by PA6
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// Stack inherits from LinkedList
class Stack : public LinkedList {
	public:
	   // common stack operations
	   void push(string);
	   string pop();
	   string peek();
	   bool isEmpty();
};

#endif
