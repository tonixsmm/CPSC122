#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// 2 ways to think about implementing a stack
    // 1. Composition: Stack has a LinkedList
    // 2. Inheritance: Stack is a LinkedList
// We will do option 2

class Stack : public LinkedList {
    // No Stack-specific state. So, no private attribute
    public:
        void push(int);
        int pop();
        int peek();
        bool isEmpty();
        void clear();
        int size();
};

#endif
