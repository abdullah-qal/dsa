#include <iostream>

#include "List/queue.hpp"

Queue::Queue() : first{nullptr}, last{nullptr} { }

Queue::~Queue() {
    while (first) 
        first = std::move(first->next);
}

auto Queue::isEmpty() -> bool { return first == nullptr; } 

auto Queue::enqueue(int value) -> void {
    std::unique_ptr<Node> tmp = std::make_unique<Node>(value);

    if (!isEmpty()) { 
        last->next = std::move(tmp);
        last = last->next.get();
    } else {
        first = std::move(tmp);
        last = first.get();
    }
}

auto Queue::dequeue() -> std::unique_ptr<Node> {
    if (isEmpty()) return nullptr;

    std::unique_ptr<Node> result = std::move(first);

    first = std::move(result->next); 
    if (!first) last = nullptr;

    return result;
}

auto Queue::insertAfterKth(int k, int value) -> void{ 
    Node *tmp = first.get();
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);

    for (int i = 0; i < k && tmp; ++i) 
        tmp = tmp->next.get();
    newNode->next = std::move(tmp->next);
    tmp->next = std::move(newNode);   
}

auto Queue::minimum() -> int {
    int min = first->data;

    for (Node *tmp = first.get(); tmp; tmp = tmp->next.get()) 
        if (tmp->data < min) 
            min = tmp->data;
            
    return min;
}

auto Queue::dequeue2nd() -> std::unique_ptr<Node> {
    if (!first || !first->next)
        return nullptr;

    auto second = std::move(first->next);

    first->next = std::move(second->next);

    return second;
}
auto Queue::divideQueue() -> Queue {
    Queue q{};
    if (!first || !first->next) return q;

    auto current = first.get();

    for (int index = 1; current && current->next; ++index) {
        if ((index + 1) % 2 == 0) {  
            auto evenNode = std::move(current->next);
            current->next = std::move(evenNode->next);  

            q.enqueue(evenNode ->data);

        } else {
            current = current->next.get();
        }
    }
    return q;
}

auto Queue::removeAll(Queue *list, int size) -> void {
    Node *prev = nullptr;
    Node *node = first.get();
    
    while (node) {
        Node *next = node->next.get(); 
        bool shouldRemove = false;
    
        for (int q = 0; q < size && !shouldRemove; ++q) {
            for (Node *element = list[q].first.get(); element; element = element->next.get()) {
                if (element->data == node->data) {
                    shouldRemove = true;
                    break;
                }
            }
        }
    
        if (shouldRemove) {
            if (prev) {
                if (node == last) last = prev;
                prev->next = std::move(node->next);
            } else {
                first = std::move(node->next);
            }
        } else {
            prev = node;
        }
        node = next;
    }    
}

auto Queue::print() const -> void  {
    for (Node *tmp = first.get(); tmp; tmp = tmp->next.get()) 
        std::cout << tmp->data << "\n";
}

