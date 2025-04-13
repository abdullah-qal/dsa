#include <climits>
#include <iostream>

#include "queue.h"


Queue::Queue(int N) : array{std::make_unique<Element[]>(N)}, first{0}, last{0}, N{N} {}

bool Queue::isFull() { return first == (last + 1) % N; }
bool Queue::isEmpty() { return first == last; }

void Queue::enqueue(int value) { 
    Element e = Element(value);
    if (!isFull()) { 
        array[last] = e;
        last = (last + 1) % N;
    }
}

Element Queue::dequeue() {
    if (!isEmpty()) {
        Element tmp = array[first];
        first = (first + 1) % N;
        return tmp;
    }
    return Element(INT_MIN);
}

void Queue::insertAfterKth(int k, int value) {
    if (isFull() || k >= N || k < 0) return;

    int len = first < last ? last - first : last - first + N;
    for (int i = len; i > k; --i) 
        array[(i + first) % N] = array[(i + first - 1) % N];

    last = (last + 1) % N;
    array[k + 1] = value;
}

void Queue::deleteKth(int k) {
    if (isEmpty() || k >= N || k < 0) return;

    int len = first < last ? last - first : last - first + N;

    for (int i = k; i < len - 1; ++i) 
        array[(i + first) % N] = array[(i + first + 1) % N];

    if ((k + first) % N == first) first = (first + 1) % N;
    last = (last - 1 + N) % N;
}
void Queue::print() const {
    int len = first < last ? last - first : last - first + N;

    for (int i = 0; i < len; ++i) 
        std::cout << array[(first + i) % N].getData() << "\n";
}