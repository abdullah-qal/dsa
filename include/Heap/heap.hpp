#ifndef HEAP_H
#define HEAP_H

#include <memory>
#include "heap_node.hpp"

class MinComparison {
    static auto should_go_down(int a, int b) -> bool { return a >= b; }
};

class MaxComparison {
    static auto should_go_down(int a, int b) -> bool { return a < b; }
};

template <typename Comparison>
class Heap : Comparison {
    private:
        int count = 0;  
        std::unique_ptr<HeapNode[]> array;

    public:
        Heap(int N) : array{std::make_unique<HeapNode[]>(N)}, count{0} { }

        auto isEmpty() const -> bool { return count == 0; }

        auto swapNode(int index1, int index2) -> void {
            HeapNode tmp = array[index1];
            array[index1] = array[index2];
            array[index2] = tmp;
        }

        auto percolateDown(int i) -> void {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            while ((left < count && Comparison::should_go_down(array[i].data, array[left].data)) 
                || (right < count && Comparison::should_go_down(array[i].data, array[right].data))) {
                
                if (right >= count || Comparison::should_go_down(array[right].data, array[left].data)) {
                    swapNode(i, left);
                    i = left;
                } else {
                    swapNode(i, right);
                    i = right;
                }

                left = 2 * i + 1;
                right = 2 * i + 2;
            }
        }

        auto percolateUp(int i) -> void {
            int parent = (i - 1) / 2;

            while (parent >= 0 && Comparison::should_go_down(array[parent].data, array[i].data)) {
                swapNode(parent, i);
                i = parent;
                parent = (i - 1) / 2;
            }
        }

        auto insert(int i) -> void {
            HeapNode n{i, i};
            array[++count - 1] = n;
            percolateUp(count - 1);
        }

        auto printHeap() const -> void {
            for (int i = 0; i < count; ++i) {
                if (i > 0 && ((i + 1) & i) == 0) 
                    std::cout << "\n";
                std::cout << array[i].data << " ";
            }
        }
};

#endif
