#ifndef STACK_H
#define STACK_H

#include "node.hpp"

#include <string>
#include <iostream>

class Stack {
    Node *top;
public: 
    Stack();
    ~Stack();

    bool isEmpty();
    void push(Node *node);
    Node* pop();

    Node *getTop();
    
    bool isBalanced1(std::string const &s);
    bool isBalanced2(std::string const &s);
    bool palindrom(std::string const &s);
    int multiply();
    Node *removeBottom();
    Stack copy();
    void doubleStack();
    void removeMiddle();
    void removeBottom(int k);
    void removeOddIndexed();
    Node *pop(int k);
};

#endif