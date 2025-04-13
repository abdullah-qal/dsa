#ifndef STACK_H
#define STACK_H

#include "element.h"

class Stack {
    Element *array;
    int top;
    int N;

    public: 
        Stack(int N);
        ~Stack();

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