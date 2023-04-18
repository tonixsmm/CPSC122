/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 17, 2023
Programming Assignment: PA7
Description: This program implements several tasks required by PA7
*/

#include "Stack.h"

/*
Function: push()
 * Date Created: 04/14/2023
 * Date Last Modified: 04/14/2023
 * Description: This function pushes a new string into the stack
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Stack class member function. Stack class is inherited from LinkedList base class
*/
void Stack::push(string newValue) {
	insertAtFront(newValue);
}

/*
Function: pop()
 * Date Created: 04/14/2023
 * Date Last Modified: 04/14/2023
 * Description: This function pops a new string out of the stack and returns its value
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Stack class member function. Stack class is inherited from LinkedList base class
*/
string Stack::pop() {
	return deleteAtFront();
}

/*
Function: peek()
 * Date Created: 04/14/2023
 * Date Last Modified: 04/14/2023
 * Description: This function returns the value of the item on the top of the stack
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Stack class member function. Stack class is inherited from LinkedList base class
*/
string Stack::peek() {
	if (head != NULL) {
		return head->value;
	}
	return "";
}

/*
Function: isEmpty()
 * Date Created: 04/14/2023
 * Date Last Modified: 04/14/2023
 * Description: This function checks if the stack is empty or not
 * Input parameters: None
 * Returns: Bool
 * Pre: None
 * Post: None
 * Note: This is a Stack class member function. Stack class is inherited from LinkedList base class
*/
bool Stack::isEmpty() {
	if (head != NULL){
		return false;
	}
	return true;
}
