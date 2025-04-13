#include "stack.h"
#include <limits.h>

Stack::Stack(int N) : N{N}, top{-1}, array{new Element[N]} {}
Stack::~Stack() { delete [] array; }

Element Stack::getTop() { return array[top]; }
int Stack::getSize() { return N; }

bool Stack::isFull() { return top == N - 1; }
bool Stack::isEmpty() { return top == -1; }

Element Stack::pop() { 
    if (!isEmpty()) return array[top--]; 
    return Element();
}
void Stack::push(Element e) { if (!isFull()) array[++top] = e; }

void Stack::enlarge() {
    Element *tmp = array;
    N *= 2;

    array = new Element[N];
    for (int i = 0; i < N; ++i) 
        array[i] = tmp[i];
    delete [] tmp;
}
// Q5
Element Stack::bottom() {
    Stack to_stack = Stack(top - 1);

    while (top)
        to_stack.push(pop());

    Element bottom = pop();
    push(bottom);

    while (!to_stack.isEmpty())
        push(to_stack.pop());
    return bottom;
}

int Stack::multiply() {
    if (N < 2) return INT_MIN;

    Stack to_stack = Stack(top - 2);
    while (top !=  1) 
        to_stack.array[to_stack.top++] = array[--top]; 

    Element bottom_last = array[--top];
    Element bottom = array[--top];
    array[top++] = bottom;
    array[top++] = bottom_last;

    while (!to_stack.isEmpty()) {
        array[top++] = to_stack.array[--to_stack.top];
    }
    return bottom.data * bottom_last.data;
}

Element Stack::pop(int k) {
    if (k < 1 || k > top) return Element(INT_MIN);

    Element popped = array[top - k + 1];
    for (int i = top - k + 1; i < top; ++i) 
        array[i] = array[i+1];
    top--;
    return popped;
}

void Stack::push(int k, int data) {
    if (k < 1 || top - k + 2 < 0) return;

    for (int i = 0; i < k - 1; ++i) 
        array[top - i + 1] = array[top - i];
    array[top++ - k + 2] = data;
}

void Stack::compress() {
    Stack to_stack = Stack(N);

    while (top > 0) {
        while (array[top].data == array[top - 1].data) 
            pop();
        to_stack.push(pop());
    }
    while (!to_stack.isEmpty()) 
        push(to_stack.pop());
}