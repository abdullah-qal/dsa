#ifndef STACK_HPP
#define STACK_HPP

#include <memory>

#include "element.hpp"
#include "tree_node.hpp"

class Stack {
    int N, top;
    std::unique_ptr<Element[]> array;

    public: 
        Stack(int N);

        Element getTop();
        int getSize();

        bool isFull();
        bool isEmpty();

        TreeNode *pop();
        void push(TreeNode *value);
};
#endif