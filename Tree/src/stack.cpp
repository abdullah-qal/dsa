#include "stack.hpp"

Stack::Stack(int N) : N{N}, top{-1}, array{new Element[N]} {}

Element Stack::getTop() { return array[top]; }
int Stack::getSize() { return N; }

bool Stack::isFull() { return top == N - 1; }
bool Stack::isEmpty() { return top == -1; }

TreeNode *Stack::pop() { 
    if (!isEmpty()) return array[top--].data; 
    return nullptr;
}

void Stack::push(TreeNode *value) { 
    Element e = Element(value);
    if (!isFull()) array[++top] = e; 
}