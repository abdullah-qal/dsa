#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "node.h"


class Queue {
    std::unique_ptr<Node> first;
    Node *last;

    public: 
        Queue();

        bool isEmpty();

        void enqueue(int value);
        std::unique_ptr<Node> dequeue();

        void print() const;
        void insertAfterKth(int k, int value);
};

#endif 
