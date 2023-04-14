#include "Stack.h"

void Stack::push(string newValue) {
	insertAtFront(newValue);
}

string Stack::pop() {
	return deleteAtFront();
}

// TODO: finish this function
string Stack::peek() {
	if (head != NULL) {
		return head->value;
	}
	return "";
}

bool Stack::isEmpty() {
	if (head != NULL){
		return false;
	}
	return true;
}
