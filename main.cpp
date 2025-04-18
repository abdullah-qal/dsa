#include <string>
#include <iostream>

#include "Array/hash.hpp"
// #include "List/hash.hpp"

int main() {

    Hash h{10};
    h.insertValue(3);
    h.insertValue(3);

    std::cout << h.numberOfEmptySlots() << "\n";
    h.deleteAll(5);
    std::cout << h.numberOfEmptySlots() << "\n";
    return 0;
}