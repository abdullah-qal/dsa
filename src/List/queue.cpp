#include <iostream>

#include "List/queue.hpp"

Queue::Queue() : first{nullptr}, last{nullptr} {}

Queue::~Queue() {
    while (first) 
        first = std::move(first->next);
}

bool Queue::isEmpty() { return first == nullptr; }

void Queue::enqueue(int value) {
    std::unique_ptr<Node> tmp = std::make_unique<Node>(value);

    if (!isEmpty()) { 
        last->next = std::move(tmp);
        last = last->next.get();
    } else {
        first = std::move(tmp);
        last = first.get();
    }
}

std::unique_ptr<Node> Queue::dequeue() {
    if (isEmpty()) return nullptr;

    std::unique_ptr<Node> result = std::move(first);

    first = std::move(result->next); 
    if (!first) last = nullptr;

    return result;
}

void Queue::insertAfterKth(int k, int value) {
    Node *tmp = first.get();
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);

    for (int i = 0; i < k && tmp; ++i) 
        tmp = tmp->next.get();
    newNode->next = std::move(tmp->next);
    tmp->next = std::move(newNode);   
}

void Queue::print() const {
    for (Node *tmp = first.get(); tmp; tmp = tmp->next.get()) 
        std::cout << tmp->data << "\n";
}

