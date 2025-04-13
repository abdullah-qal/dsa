#ifndef ELEMENT_H
#define ELEMENT_H

class Element {
    int data;
    friend class Stack;

    public:
        Element(int data);
        Element();    

        int getData();
};

#endif