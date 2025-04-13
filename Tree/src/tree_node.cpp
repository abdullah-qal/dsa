#include <iostream>
#include <utility> 

#include "tree_node.hpp"
#include "queue.hpp"

TreeNode::TreeNode(int data) : data{data}, left{nullptr}, right{nullptr} {}

auto TreeNode::recursiveSearch(int value) -> TreeNode * {
    if (data == value) {
        return this;
    } 
    if (data > value) {
        if (left) return left->recursiveSearch(value);
    } else {
        if (right) return right->recursiveSearch(value);
    }
    return nullptr;
}

auto TreeNode::iterativeMinSearch() -> TreeNode * {
    TreeNode *result = this;
    
    while (result->left)
        result = result->left.get();

    return result;
}

auto TreeNode::iterativeMaxSearch() -> TreeNode * {
    TreeNode *result = this;
    
    while (result->right)
        result = result->right.get();

    return result;
}

auto TreeNode::recursiveMinSearch() -> TreeNode * {
    if (!left) return this; 
    return left->recursiveMinSearch();
}
auto TreeNode::recursiveMaxSearch() -> TreeNode * {
    if (!right) return this; 
    return right->recursiveMaxSearch();
}


auto TreeNode::preorder() -> void {
    std::cout << data << "\n";
    if (left) left->preorder();
    if (right) right->preorder();
}

auto TreeNode::inorder() -> void {
    if (left) left->inorder();
    std::cout << data << "\n";
    if (right) right->inorder();
}

auto TreeNode::postorder() -> void {
    if (left) left->postorder();
    if (right) right->postorder();
    std::cout << data << "\n";
}

auto TreeNode::leftistOrRightist() -> int {
    int count = 0;
    if (left && !right) count = 1;
    if (!left && right) count = -1;

    if (left) count += left->leftistOrRightist();
    if (right) count += right->leftistOrRightist();
    return count;
}

auto TreeNode::numberOfMeanNodes() -> int {
    int count = 0;
    if (left && right && data == (left->data + right->data) / 2) count++;

    if (left) count += left->numberOfMeanNodes();
    if (right) count += right->numberOfMeanNodes(); 
    return count;
}

auto TreeNode::changeChildOfSingleton() -> void {
    if (left && !right) 
        right = std::exchange(left, nullptr);
    if (!left && right)
        left = std::exchange(right, nullptr);

    if (left) left->changeChildOfSingleton();
    if (right) right->changeChildOfSingleton();
}

TreeNode *prev = nullptr;

auto TreeNode::containsTwoSameNumbers() -> bool {
    if (left && left->containsTwoSameNumbers()) return true; 
    if (prev && (prev->data == data)) return true;
    prev = this;
    if (right && right->containsTwoSameNumbers()) return true;

    return false;
}

auto TreeNode::divisbleByThree() -> int {
    int count = 0;
    if (data % 3 == 0) count++;

    if (left) count += left->divisbleByThree();
    if (right) count += right->divisbleByThree();

    return count;
}

auto TreeNode::numberOfNonLeafNodes() -> int {
    int count = 0;
    if (left || right) count++;

    if (left) count += left->numberOfNonLeafNodes();
    if (right) count += right->numberOfNonLeafNodes();

    return count;
}

auto TreeNode::leftist() -> int {
    Queue q{100};

    q.enqueue(this);
    int count = 0;

    while (!q.isEmpty()) {
        TreeNode *data = q.dequeue();
        if ((data->left && !data->right) || (data->left && data->right && data->left->data > data->right->data)) 
            count++;

        if (data->left)  q.enqueue(data->left.get());
        if (data->right) q.enqueue(data->right.get());
    }
    return count;
}

auto TreeNode::higherThanX(int x) -> int {
    if (data <= x)
        return right ? right->higherThanX(x) : 0;
    return 1 +
           (left  ? left->higherThanX(x)  : 0) +
           (right ? right->higherThanX(x) : 0);
}

auto TreeNode::numberOfDuplicates() -> int {
    int min_of_right = right ? right->recursiveMinSearch()->data : INT_MAX;

    return (min_of_right == data ? 1 : 0) +
           (right ? right->numberOfDuplicates() : 0) + 
           (left ? left->numberOfDuplicates() : 0);
}

auto TreeNode::sumOfTree(int x) -> int {
    if (data >= x)
        return left ? left->sumOfTree(x) : 0;
    return data                                + 
           (left  ? left->sumOfTree(x)  : 0) +
           (right ? right->sumOfTree(x) : 0);
}