#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <memory>

class TreeNode {
    int data;
    std::unique_ptr<TreeNode> left, right;

    friend class Tree;

    public:
        TreeNode(int data);

        auto recursiveSearch(int value) -> TreeNode *;

        auto iterativeMinSearch() -> TreeNode *;
        auto iterativeMaxSearch() -> TreeNode *;

        auto recursiveMinSearch() -> TreeNode *;
        auto recursiveMaxSearch() -> TreeNode *;

        auto getData() -> int { return data; }
        auto getRight() -> TreeNode * { return right.get(); }
        auto getLeft() -> TreeNode * { return left.get(); }

        auto preorder() -> void;
        auto inorder() -> void;
        auto postorder() -> void;

        auto leftistOrRightist() -> int; // Q1
        auto numberOfMeanNodes() -> int; // Q2
        auto changeChildOfSingleton() -> void; // Q3
        auto containsTwoSameNumbers() -> bool; // Q4
        auto divisbleByThree() -> int; // Q5
        auto numberOfNonLeafNodes() -> int; // Q6
        auto leftist() -> int; // Q7
        auto higherThanX(int x) -> int; // Q9
        auto numberOfDuplicates() -> int; // Q10
        auto sumOfTree(int x) -> int; // Q11 
};

#endif 
