#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node *tmp = head;
    while (tmp) {
        Node *next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

void LinkedList::insertFirst(Node *node) {
    if (!tail) {
        tail = node;
    } 
    node->next = head;
    head = node;
}
void LinkedList::insertLast(Node *node) {
    if (!head) {
        head = node;
    } else { 
        tail->next = node;
    }
    tail = node;
}

void LinkedList::print() {
    using namespace std;

    if (!head) return;

    for (Node *current = head; current; current = current->next) {
        std::cout << current->data << " ";
    }
}
void LinkedList::printReverse() {
    using namespace std;

	if (!head || !head->next) return;
	
	LinkedList output;
	for (Node *node = head; node; node = node->next) {
        Node *tmp = new Node(node->data);
		output.insertFirst(tmp);
	}
	for (Node *node = output.head; node; node = node->next) {
		std::cout << node->data << " ";
	}
}

void LinkedList::addAfterEachNode(Node *newNode) {
	if (!head) return;
	
	for (Node *current = head; current; current = current->next->next) {
		Node *tmp = new Node(newNode->data);
		
		if (!current->next) tail = tmp;
		
		tmp->next = current->next;
		current->next = tmp;
	}
}

void LinkedList::printOddNodes() {
	using namespace std;
	
	if (!head | !head->next) return;
	
	for (Node * node = head; node->next; node = node->next->next)
		cout << node->next->data << " ";
}

void LinkedList::deleteBetween(int p, int q) {
	if (!head || !head->next) return;

	int size = 0;
    for (Node *node = head; node; node = node->next) 
        size++;
    if (p < 0 || q > size - 1 || p > q) return;    

    Node *node = head, *beforeFirst = nullptr, *afterLast = nullptr;
	for (int index = 0; index < size; ++index) {
		Node *tmp = node->next;
		
		if (index == q + 1) afterLast = node;
		if (index == p - 1) beforeFirst = node;

		if (index >= p && index <= q) {
			bool includesHead = (node == head), includesTail = (node == tail);

			delete node;

            if (includesTail) tail = beforeFirst;
            if (includesHead) head = afterLast;
		}
		node = tmp;
	}
    if (beforeFirst) beforeFirst->next = afterLast;
}
// we assume the list is not empty, otherwise theres nothing to pop in the first place
Node *LinkedList::popFront() {
    // if the list is of length 1
    if (head == tail) {
        Node *node = head;
        head = nullptr;
        tail = nullptr;
        return node;
    }

    // otherwise the list is of length > 1, so no fucky tail updates
    Node *node = head;
    head = head->next;
    return node;
}
void LinkedList::pushBack(Node *node) {
    if (!head) {
        head = node;
        tail = node;
        return;
    }
    tail->next = node;
    tail = node;
}
void LinkedList::remove(LinkedList const &list2) {
    if (!head) return;  

    for (Node *l2node = list2.head; l2node; l2node = l2node->next) {
        Node *prev = nullptr;
        Node *l1node = head;

        while (l1node) {
            Node *tmp = l1node->next;  
            if (l1node->data == l2node->data) {
                if (l1node == head) {
                    head = head->next;  
                    if (!head) { 
                        tail = nullptr;
                    }
                } 
                else if (l1node == tail) {
                    tail = prev;
                    if (prev) {
                        prev->next = nullptr;
                    }
                } 
                else {
                    if (prev) {
                        prev->next = l1node->next;
                    }
                }
                delete l1node;  
            } 
            else {
                prev = l1node;  
            }
            l1node = tmp;  
        }
    }
}


