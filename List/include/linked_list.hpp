#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class LinkedList {
    Node *head;
    Node *tail;
public:
    LinkedList();
    ~LinkedList();

    Node *popFront();
    void pushBack(Node *node);

    void insertFirst(Node *node);
    void insertLast(Node *node);

    void print();
    void printReverse();
    void printOddNodes();
    
    void addAfterEachNode(Node *newNode);
    void deleteBetween(int p, int q);

    void remove(LinkedList const &l1);
};

#endif