#include <iostream>
#include "StrLL.h"
#include "Node.h"

void StrLL::print(std::ostream& os) {
    Node* cur = head;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->next;
    }
}

void StrLL::printReverse(std::ostream& os) {
    Node* cur = tail;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->prev;
    }
}

void StrLL::insertFront(char c) {
    Node* newNode = new Node(c);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void StrLL::insertBack(char c) {
    Node* newNode = new Node(c);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

}
