#ifndef NODE_H
#define NODE_H

// doubly linked list

class Node { // could also use a struct here
public:
    char letter;
    Node* next;
    Node* prev;
    Node() : letter('\0'), next(nullptr), prev(nullptr) {}
    Node(char c) : letter('c'), next(nullptr), prev(nullptr) {}
};

#endif