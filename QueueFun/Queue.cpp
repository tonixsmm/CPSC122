#include "Queue.h"

void Queue::enqueue(int newValue){
    append(newValue);
}

int Queue::dequeue(){
    return deleteAtFront();
}

int Queue::peek(){
    if (head != NULL){
        return head->value;
    }
    return -1;
}

bool Queue::isEmpty(){
    if (head != NULL){
        return false;
    }
    return true;
}

void Queue::clear(){
    // 2 ways to implement clear()
        // 1. Write a loop
        // while (!isEmpty()){
        //     dequeue();
        // }

        // 2. Use the "destructor" code wrote in LinkedList
        destroyList();
}

int Queue::size(){
    // 2 ways to do
        // 1. Traverse the list and count the time complexity
        int count = 0;
        Node * curr = head;
        while (curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
        // 2. Add a size attribute to the LinkedList class
}