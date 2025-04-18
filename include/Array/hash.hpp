#ifndef HASH_HPP
#define HASH_HPP

#include <memory>

#include "Array/element.hpp"

class Hash {
    std::unique_ptr<std::unique_ptr<Element>[]> table;
    std::unique_ptr<bool[]> deleted;
    int N;

    auto hashFunction(int value) -> int;

    public: 
        Hash(int N);
        auto search(int value) -> Element *;
        auto insertValue(int value) -> void;
        auto deleteValue(int value) -> void;

        static auto jollyJumper(int *sequence, int size) -> bool; // Q1
        auto numberOfEmptySlots() -> int; // Q2
        auto deleteAll(int x) -> void; // Q3
        auto hashFunctionItself(int value) -> void; // Q4    
        static auto anyDuplicate(int *array, int size) -> bool; // Q5
        static auto intersection(int *list1, int *list2, int size) -> int *;
};

#endif