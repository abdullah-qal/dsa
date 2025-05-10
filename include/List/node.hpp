#ifndef NODE_H
#define NODE_H

#include <memory>

class Node {
    int data;
    std::unique_ptr<Node> next;

    friend class LinkedList;
    friend class Stack;
    friend class Queue;

public:
    Node(int data);
};

#endif 
