#include <climits>
#include <iostream>

#include "Array/queue.hpp"


Queue::Queue(int N) : array{std::make_unique<Element[]>(N)}, first{0}, last{0}, N{N} {}

auto Queue::isFull() -> bool { return first == (last + 1) % N; }
auto Queue::isEmpty() -> bool { return first == last; }

auto Queue::enqueue(int value) -> void { 
    Element e = Element(value);
    if (!isFull()) { 
        array[last] = e;
        last = (last + 1) % N;
    }
}

auto Queue::dequeue() -> Element {
    if (!isEmpty()) {
        Element tmp = array[first];
        first = (first + 1) % N;
        return tmp;
    }
    return Element(INT_MIN);
}

auto Queue::insertAfterKth(int k, int value) -> void {
    if (isFull() || k >= N || k < 0) return;

    int len = first < last ? last - first : last - first + N;
    for (int i = len; i > k; --i) 
        array[(i + first) % N] = array[(i + first - 1) % N];

    last = (last + 1) % N;
    array[k + 1] = value;
}

auto Queue::deleteKth(int k) -> void {
    if (isEmpty() || k >= N || k < 0) return;

    int len = first < last ? last - first : last - first + N;

    for (int i = k; i < len - 1; ++i) 
        array[(i + first) % N] = array[(i + first + 1) % N];

    if ((k + first) % N == first) first = (first + 1) % N;
    last = (last - 1 + N) % N;
}
auto Queue::minimum() -> int {
    int len = first < last ? last - first : last - first + N;
    int min = array[first].data;

    for (int i = 0; i < len; ++i) 
        if (min > array[(i + first) % N].data)
            min = array[(i + first) % N].data;
    return min;
}

auto Queue::dequeue2nd() -> Element {
    Element second = array[(first + 1) % N];
    array[(first + 1) % N] = array[first];
    first = (first + 1) % N;
    
    return second;
}

auto Queue::insertAfterLargest(int data) -> void {
    int len = first < last ? last - first : last - first + N;
    int max = array[first].data, index = first;

    for (int i = 0; i < len; ++i) {
        int currentIndex = (i + first) % N;
        if (array[currentIndex].data > max) {
            max = array[currentIndex].data;
            index = currentIndex;
        }
    }
    for (int i = len; i > index; --i) 
        array[(first + i) % N] = array[(first + i - 1) % N];
    last = (last + 1) % N;
    array[(index + 1) % N] = Element(data);
}

auto Queue::divideQueue() -> Queue {
    Queue q{N / 2};

    int size = first < last ? last - first : last - first + N;
    int write = 0; 
    for (int i = 0; i < size; ++i) {
        int pos = (first + i) % N;
        if (i % 2 == 1) {
            q.enqueue(array[pos].data);
        } else {
            array[write] = array[pos];
            write = (write + 1) % N;
        }
    }
    first = 0; 
    last = write;

    std::cout << "Even queue:\n";
    q.print();
    std::cout << "\n Odd queue:\n";
    print();
    return q;
}

auto Queue::removeOddIndexed() -> void {
    Queue q{N};

    while (!isEmpty())
        q.enqueue(dequeue().data);

    while (!q.isEmpty()) {
        q.dequeue();
        if (!q.isEmpty()) enqueue(q.dequeue().data);
    }
    print();
}

auto Queue::copyPaste(Queue const &src, int index) -> void {
    int len = first < last ? last - first : last - first + N;
    int src_len = src.first < src.last ? src.last - src.first : src.last - src.first + src.N;

    if (len + src_len > N) return;
    if (index < 0 || index > len) return;
    
    for (int i = len - 1; i >= index; --i) 
        array[(first + i + src_len) % N] =  array[(first + i) % N];

    for (int i = index, j = 0; j < src_len; ++i, ++j) 
        array[(first + i) % N] = src.array[(src.first + j) % src.N];
    last = (last + src_len) % N;
    print();
}

auto Queue::print() const -> void {
    int len = first < last ? last - first : last - first + N;

    for (int i = 0; i < len; ++i) 
        std::cout << array[(first + i) % N].data << "\n";
}