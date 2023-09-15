#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

class Queue : public LinkedList {
    // No queue specific attributes needed
    public:
        // Common queue operations
        virtual void enqueue(int); // To determine if it is a priority queue or not
        int dequeue();
        int peek();
        void clear();
        bool isEmpty();
        int size();
};

#endif