#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "element.h"

class Queue {
    std::unique_ptr<Element[]> array;
    int first, last, N;

    public: 
        Queue(int N);

        bool isFull();
        bool isEmpty();

        void enqueue(int value);
        Element dequeue();

        void print() const;

        void insertAfterKth(int k, int value);
        void deleteKth(int k);
};

#endif 