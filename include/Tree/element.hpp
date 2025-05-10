#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "tree_node.hpp"

class Element {
    TreeNode *data;
    
    friend class Stack;
    friend class Queue;

    public:
        Element(TreeNode *data);
        Element();    
};

#endif