#ifndef STACK_HPP
#define STACK_HPP

#include <memory>

#include "element.hpp"

class Stack {
    std::unique_ptr<Element[]> array;
    int top, N;

    public: 
        Stack(int N);

        Element getTop();
        int getSize();

        bool isFull();
        bool isEmpty();

        Element pop();
        void push(Element e);

        void enlarge();
        Element bottom();
        int multiply();
        Element pop(int k);
        void push(int k, int data);
        void compress();
};
#endif