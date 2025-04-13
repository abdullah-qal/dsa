#include "stack.h"
#include <limits.h>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    Node *tmp;
    tmp = top; 

    while (tmp) {
        Node *next = tmp->next;
        delete tmp; 
        tmp = next;
    }
}

bool Stack::isEmpty() {
    return top == nullptr;
}

Node *Stack::getTop() { return top; }

Node *Stack::pop() {
    Node *tmp = top;
    if (!isEmpty()) top = top->next;
    return tmp;
}

void Stack::push(Node *node) {
    node->next = top;
    top = node;
}

// Q1
bool Stack::isBalanced1(std::string const &s) {
    for (char c : s) {
        if (c == '(') { 
            push(new Node(0));
        } else if (c == ')') {
            if (isEmpty()) return false;
            pop();
        } else {
            std::cout << "only () broski" << "\n";
            return false;
        }
    }
    return isEmpty();
}

// Q2
// [()]
bool Stack::isBalanced2(std::string const &s) {
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            push(new Node(c));
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty()) return false;
            if (!(top->data == c - 1 || top->data == c - 2)) return false;
            pop();
        } else {
            std::cout << "only () broski" << "\n";
            return false;
        }
    }
    return isEmpty();
}

// Q4
bool Stack::palindrom(std::string const &s) {
    for (char c : s) 
        push(new Node(c));
    for (char c : s) 
        if (c != pop()->data) return false;
    return true;
}

// Q6
int Stack::multiply() {
    if (!top || !top->next) return INT_MIN;

    Stack to_stack;
    
    while (top->next->next) {
        Node *tmp = top->next;
        
        top->next = to_stack.top;
        to_stack.top = top;
        top = tmp;
    }

    Node *bottom_last = top;
    Node *bottom = top->next;
    while (!to_stack.isEmpty()) {
        Node *tmp = to_stack.top->next;

        to_stack.top->next = top;
        top = to_stack.top;
        to_stack.top = tmp;
    }
    return bottom->getData() * bottom_last->getData();
}

// Q7
Node *Stack::removeBottom() {
    if (!top) return new Node(INT_MIN);
    Stack to_stack;
    while (top->next) 
        to_stack.push(pop());

    Node *bottom = pop();

    while (!to_stack.isEmpty()) 
        push(to_stack.pop());
    return bottom;
}

// Q8
Stack Stack::copy() {
    Stack to_stack;
    Stack aux_stack;

    while (!isEmpty()) {
        Node *tmp = top->next;

        top->next = aux_stack.top;
        aux_stack.top = top;

        top = tmp;
    }

    while (!aux_stack.isEmpty()) {
        Node *newCopy = new Node(aux_stack.top->data);
        Node *tmp = aux_stack.top->next;
        
        newCopy->next = to_stack.top;
        aux_stack.top->next = top;

        to_stack.top = newCopy;
        top = aux_stack.top;

        aux_stack.top = tmp;
    }
    return to_stack;
}

// Q9
void Stack::doubleStack() {
    Stack aux_stack;

    while (!isEmpty()) {
        Node *popped = pop();

        Node *popped1 = new Node(popped->data);
        Node *popped2 = new Node(popped->data);

        aux_stack.push(popped1);
        aux_stack.push(popped2);

        delete popped;
    }
    while (!aux_stack.isEmpty()) {
        push(aux_stack.pop());
        push(aux_stack.pop());
    }
}

// Q10
void Stack::removeMiddle() {
    Stack aux_stack;

    int size = 0;

    for (size  = 0; top; ++size) 
        aux_stack.push(pop());

    for (int index = 0; index != size / 2; ++index) 
        push(aux_stack.pop());

    delete aux_stack.pop();

    while (!aux_stack.isEmpty()) 
        push(aux_stack.pop());
}

// Q11
void Stack::removeBottom(int k) {
    Stack aux_stack; 

    while (!isEmpty())
        aux_stack.push(pop());
    for (int i = 0; i != k && aux_stack.top; ++i) 
        delete aux_stack.pop();
    while (!aux_stack.isEmpty()) 
        push(aux_stack.pop());
}

void Stack::removeOddIndexed() {
    Stack aux_stack;

    while (!isEmpty()) 
        aux_stack.push(pop());
    
    bool isOdd = true;
    while (!aux_stack.isEmpty()) {
        if(isOdd) {
            delete aux_stack.pop();
        } else {
            push(aux_stack.pop());
        }
        isOdd = !isOdd;
    }
}

Node *Stack::pop(int k) {
    if (isEmpty() || k < 1) return new Node(INT_MIN);

    Node *kthNode = top;
    Node *prev = nullptr;
    for (int i = 1; kthNode && i < k; ++i) {
        prev = kthNode;
        kthNode = kthNode->next;
    }
    if (k == 1) top = top->next;

    if (!kthNode) return new Node(INT_MIN); 

    if (prev) prev->next = kthNode->next;

    return kthNode;
}