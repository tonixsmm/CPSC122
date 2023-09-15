#include "Stack.h"

// The head of the linkedlist is the top of the stack
void Stack::push(int newItem) {
    insertAtFront(newItem);
}

int Stack::pop(){
    return deleteAtFront();
}

int Stack::peek(){
    if (head != nullptr){
        return head->value;
    }
    return -1;
}
bool Stack::isEmpty(){
    if (head != nullptr){
        return false;
    }
    return true;
}

void Stack::clear(){
    // 2 ways to implement clear()
        // 1. Write a loop 
            // while (!isEmpty) {
                // pop();
            //}
        // 2. Leverage the destructor code we've already written in LinkedList
            destroyList();
}

int Stack::size(){
    // 2 ways to implement our size();
        // 1. Write a loop - O(N)
        // 2. Add a counter size LinkedList or Stack attribute, make sure we keep it up to date on all push and pop/add and delete - O(1)
    int count = 0;
    Node * currNode = head;
    while (currNode != nullptr){
        count++;
        currNode = currNode->next;
    }
    return count;
}