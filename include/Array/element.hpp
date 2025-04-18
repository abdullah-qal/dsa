#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Element {
    int data;
    
    friend class Stack;
    friend class Queue;
    friend class Hash;

    public:
        Element(int data);
        Element();    

        int getData();
};

#endif