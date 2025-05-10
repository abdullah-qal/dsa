#ifndef HEAP_NODE_H
#define HEAP_NODE_H

class HeapNode {
    int data, name;

    template <typename Comparison>
    friend class Heap;

    public:
        HeapNode(int data, int name);
        HeapNode() = default;
};

#endif