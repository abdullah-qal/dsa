#include <climits>
#include <iostream>

#include "queue.hpp"


Queue::Queue(int N) : array{std::make_unique<Element[]>(N)}, first{0}, last{0}, N{N} {}

bool Queue::isFull() { return first == (last + 1) % N; }
bool Queue::isEmpty() { return first == last; }

void Queue::enqueue(TreeNode *value) { 
    Element e = Element(value);
    if (!isFull()) { 
        array[last] = e;
        last = (last + 1) % N;
    }
}

TreeNode *Queue::dequeue() {
    if (!isEmpty()) {
        Element tmp = array[first];
        first = (first + 1) % N;
        return tmp.data;
    }
    return nullptr;
}
