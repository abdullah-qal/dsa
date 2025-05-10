#include <cassert>

#include "tree.hpp"
#include "stack.hpp"
#include "queue.hpp"

Tree::Tree() : root(nullptr) {}

auto Tree::iterativeSearch(int value) -> TreeNode * {
    TreeNode *result = root.get(); 

    while (result) {
        if (result->data == value) {
            return result;
        } 
        if (result->data > value) {
            result = result->left.get();
        } else {
            result = result->right.get();
        }
    }
    return nullptr; 
}

auto Tree::insertNode(int value) -> void {
    if (!root) {
        root = std::make_unique<TreeNode>(value);
        return;
    }

    TreeNode *x = root.get(), *y = x;

    while (x) {
        y = x;
        if (value < x->data) {
            x = x->left.get();
        } else {
            x = x->right.get();
        }
    }
    
    if (value < y->data) {
        y->left = std::make_unique<TreeNode>(value);
    } else {
        y->right = std::make_unique<TreeNode>(value);
    }
}

auto Tree::deleteNode(int value) -> void {   
    TreeNode *parent = getParent(value);  // parent = 5
    if (!parent) {
        root = nullptr;
        return;
    }
    
    TreeNode *x = value > parent->data ? parent->right.get() : parent->left.get(); // child = 9

    for (TreeNode *y;; x->data = y->data, x = y) { 
        if (x->left) {
            y = x->left->recursiveMaxSearch(); // replacement = 6
            parent = getParent(y->data); // parent = 9
        } else if (x->right) {
            y = x->right->recursiveMinSearch();
            parent = getParent(y->data);
        } else {
            if (parent->left.get() == x) {
                parent->left = nullptr;
            }  else {
                parent->right = nullptr;
            }
            break;
        }
    }
}

auto Tree::getParent(int value) -> TreeNode * {
    TreeNode *child = root.get(), *parent = nullptr;

    while (child && child->data != value) {
        parent = child;
        child = value > child->data ? child->right.get() : child->left.get();
    }

    return parent;
}

// Preorder DFS
// auto Tree::nodeCountWithStack() -> int {
//     TreeNode *d = root.get(); 
//     Stack s = Stack(10);

//     if (d) s.push(d); 

//     int count = 0;
//     while (!s.isEmpty()) {
//         d = s.pop();
//         count++;
//         if (d->right) s.push(d->right.get());
//         if (d->left) s.push(d->left.get());
//     }
//     return count;
// }   


// // Inorder DFS
// auto Tree::nodeCountWithStack() -> int {
//     TreeNode *d = root.get();
//     Stack s = Stack(10);

//     int count = 0;
//     for (; d || !s.isEmpty(); d = d->right.get()) {
//         for (; d; d = d->left.get()) s.push(d);
//         d = s.pop();
//         count++;
//     }
// }

// Postorder DFS
auto Tree::nodeCountWithStack() -> int {
    int count = 0;
    Stack s1{10};
    Stack s2{10};
    
    s1.push(root.get());

    while (!s1.isEmpty()) {
        TreeNode *data = s1.pop();
        s2.push(data);

        if (data->right) s1.push(data->right.get());
        if (data->left) s1.push(data->left.get());
    }

    for (; !s2.isEmpty(); ++count) 
        s2.pop(); 
    return count;
}

auto Tree::depthOfNode(int x) -> int {
    TreeNode *node = root.get(); 
    int count = 1;
    for (; node->data != x; ++count) 
        node = x > node->data ? node->right.get() : node->left.get(); 
    return count;
}