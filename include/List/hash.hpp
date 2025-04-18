#ifndef HASH_HPP
#define HASH_HPP

#include "List/linked_list.hpp"

class Hash {
    std::unique_ptr<LinkedList[]> table;
    int N;
    auto hashFunction(int value) -> int;

    public:
        Hash(int N);

        auto search(int value) -> Node *;
        auto insertValue(int value) -> void;
        auto deleteValue(int value) -> void;

        auto numberOfEmptySlots() -> int; // Q2
        auto deleteAll(int x) -> void; // Q3
};


#endif