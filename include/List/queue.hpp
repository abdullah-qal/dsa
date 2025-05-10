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
        
        Queue(Queue const &) = delete;
        Queue &operator=(Queue const &) = delete;

        Queue(Queue &&) = default;
        Queue &operator=(Queue &&) = default;

        auto isEmpty() -> bool;

        auto enqueue(int value) -> void;
        auto dequeue() -> std::unique_ptr<Node>;

        auto print() const -> void;
        auto insertAfterKth(int k, int value) -> void; // Q1
        auto minimum() -> int; // Q3
        auto dequeue2nd() -> std::unique_ptr<Node>; // Q4
        auto divideQueue() -> Queue; // Q6
        auto removeAll(Queue *list, int size) -> void; // Q14
};

#endif 
