#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include "tree_node.hpp"

class Tree {
    std::unique_ptr<TreeNode> root;
    
    public:
        Tree();
        auto iterativeSearch(int value) -> TreeNode *;

        auto insertNode(int value) -> void;
        auto deleteNode(int value) -> void;

        auto getParent(int value) -> TreeNode *;
        auto getRoot() -> TreeNode * { return root.get(); }

        auto nodeCountWithStack() -> int;
        
        auto depthOfNode(int x) -> int; // Q12
    };

#endif