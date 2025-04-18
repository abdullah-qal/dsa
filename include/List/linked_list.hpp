#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>

#include "List/node.hpp"

class LinkedList {
    std::unique_ptr<Node> head;
    Node *tail;

    friend class Hash;
public:
    LinkedList();
    ~LinkedList();

    auto insertFirst(int value) -> void;
    auto insertLast(int value) -> void;
    auto search(int value) -> Node *;
    auto deleteValue(int value) -> void;
    // void print();
    // void printReverse();
    // void printOddNodes();
    
    // void addAfterEachNode(Node *newNode);
    // void deleteBetween(int p, int q);

    // void remove(LinkedList const &l1);
};

#endif