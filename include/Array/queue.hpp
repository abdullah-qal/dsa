#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>
#include "element.hpp"

class Queue {
    std::unique_ptr<Element[]> array;
    int first, last, N;

    public: 
        Queue(int N);
                
        auto isFull() -> bool;
        auto isEmpty() -> bool;

        auto enqueue(int value) -> void;
        auto dequeue() -> Element;

        auto print() const -> void;

        auto insertAfterKth(int k, int value) -> void; // Q1
        auto deleteKth(int k) -> void; // Q2
        auto minimum() -> int; // Q3
        auto dequeue2nd() -> Element; // Q4
        auto insertAfterLargest(int data) -> void; // Q5
        auto divideQueue() -> Queue; // Q6
        auto removeOddIndexed() -> void; // Q7
        auto copyPaste(Queue const &src, int index) -> void; // Q9
};

#endif 