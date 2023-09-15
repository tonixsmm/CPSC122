#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "Queue.h"

using namespace std;

class PriorityQueue : public Queue {
    public:
    void enqueue(int);
};

#endif