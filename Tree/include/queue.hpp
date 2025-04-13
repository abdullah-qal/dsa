#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "element.hpp"

class Queue {
    std::unique_ptr<Element[]> array;
    int first, last, N;

    public: 
        Queue(int N);

        bool isFull();
        bool isEmpty();

        void enqueue(TreeNode *value);
        TreeNode *dequeue();
};

#endif 