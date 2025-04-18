#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>
#include <memory>

#include "List/node.hpp"

class Stack {
    std::unique_ptr<Node> top;
public: 
    Stack();
    ~Stack();

    auto isEmpty() -> bool;
    auto push(int value) -> void;
    auto pop() -> std::unique_ptr<Node>;
    
    // bool isBalanced1(std::string const &s);
    // bool isBalanced2(std::string const &s);
    // bool palindrom(std::string const &s);
    // int multiply();
    // Node *removeBottom();
    // Stack copy();
    // void doubleStack();
    // void removeMiddle();
    // void removeBottom(int k);
    // void removeOddIndexed();
    // Node *pop(int k);
};

#endif