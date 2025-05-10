#include <string>
#include <iostream>

#include "heap.hpp"

int main() {
    Heap<MaxComparison> h{100};
    h.insert(3);
    h.printHeap();
    
    return 0;
}