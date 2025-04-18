#include <iostream>

#include "Array/hash.hpp"

auto Hash::hashFunction(int value) -> int {
    return value % N;
}

Hash::Hash(int N) : table{std::make_unique<std::unique_ptr<Element>[]>(N)}, deleted{std::make_unique<bool[]>(N)}, N{N} { }

auto Hash::search(int value) -> Element *{
    int address = hashFunction(value);

    for (; table[address]; address = (address + 1) % N)
        if (!deleted[address] && table[address]->data == value)
            break;
    
    return table[address].get();
}


auto Hash::insertValue(int value) -> void {
    int address = hashFunction(value);

    while (table[address] && !deleted[address]) 
        address = (address + 1) % N;

    table[address] = std::make_unique<Element>(value);

    deleted[address] = false;
}

auto Hash::deleteValue(int value) -> void {
    int address = hashFunction(value);

    for (; table[address]; address = (address + 1) % N)
        if (!deleted[address] && table[address]->data == value)
            break;

    deleted[address] = true;
}

auto Hash::jollyJumper(int *sequence, int size) -> bool {
    if (size <= 1) return true;

    Hash hashTable{size - 1};

    for (int i = 0; i < size - 1; ++i) {
        int diff = abs(sequence[i + 1] - sequence[i]);

        if (diff < 1 || diff >= size) 
            return false;
        hashTable.insertValue(diff);
    }


    for (int i = 1; i < size; ++i) 
        if (!hashTable.search(i)) 
            return false;

    return true;
}

auto Hash::numberOfEmptySlots() -> int {
    int amount = 0; 
    for (int i = 0; i < N; ++i) 
        if (!table[i] || deleted[i]) ++amount;
    return amount;
}

auto Hash::deleteAll(int X) -> void {
    int address = hashFunction(X);
    int start = address;

    while (table[address]) {
        if (!deleted[address] && table[address]->data == X)
            deleted[address] = true;
        address = (address + 1) % N;
        if (start == address) break;
    }
}

auto Hash::hashFunctionItself(int value) -> void {
    int sum = 0;
    for (int i = 0; i < N; ++i)
        if (table[i] && !deleted[i]) 
            sum += table[i]->data;
    int addr = hashFunction(sum + value);

    while (table[addr] && !deleted[addr]) 
        addr = (addr+ 1) % N;

    table[addr] = std::make_unique<Element>(value);
}

auto Hash::intersection(int *list1, int *list2, int size) -> int * {
    Hash h{size};

    int index = 0;
    for (int i = 0; i < size; ++i) 
        h.insertValue(list1[i]);
    for (int j = 0; j < size; ++j)
        if (h.search(list2[j]))    
            index++;
    
    std::unique_ptr<int[]> result = std::make_unique<int[]>(index);

    index = 0;
    for (int i = 0; i < size; ++i)
        if (h.search(list2[i]))
            result[index++] = list2[i];
    return result.get(); 
}