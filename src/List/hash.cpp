#include "List/hash.hpp"

auto Hash::hashFunction(int value) -> int {
    return value % N;
}

Hash::Hash(int N) : table{std::make_unique<LinkedList[]>(N)}, N{N} { }

auto Hash::search(int value) -> Node * {
    int address = hashFunction(value);
    return table[address].search(value);
}

auto Hash::insertValue(int value) -> void {
    int address = hashFunction(value);
    table[address].insertLast(value);
}

auto Hash::deleteValue(int value) -> void {
    int address;
    if (search(value)){
        address = hashFunction(value);
        table[address].deleteValue(value);
    }
}

auto Hash::numberOfEmptySlots() -> int {
    int amount = 0;
    for (int i = 0; i < N; ++i) 
        if (!table[i].head) ++amount;
    return amount;
}

auto Hash::deleteAll(int X) -> void {
    while (search(X)) {
        int address = hashFunction(X);
        table[address].deleteValue(X);
    }
}