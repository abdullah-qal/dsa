#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>

#include "List/node.hpp"

class Queue {
    std::unique_ptr<Node> first;
    Node *last;

    public: 
        Queue();
        ~Queue();
        
        bool isEmpty();

        void enqueue(int value);
        std::unique_ptr<Node> dequeue();

        void print() const;
        void insertAfterKth(int k, int value);
};

#endif 
