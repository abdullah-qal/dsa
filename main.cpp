#include <string>
#include <iostream>

 // #include "Array/stack.h"
// #include "List/stack.h"

// #include "Array/queue.h"
// #include "List/queue.h"

#include "tree.hpp"
#include "tree_node.hpp"

using namespace std;

int main() {
    Tree tree;
    tree.insertNode(10);
    tree.insertNode(10);
    tree.insertNode(3);
    tree.insertNode(5);
    tree.insertNode(9);

    cout << tree.depthOfNode(10);
    return 0;
}