#ifndef StrLL_H
#define StrLL_H

#include <string>
#include <iostream>
#include "Node.h"

class StrLL { 
    Node* head;
    Node* tail;
public:
    // constructors
    StrLL(); // default constructor
    StrLL(std::string);
    StrLL(char*); // c-string
    StrLL(char);
    StrLL(const StrLL&); // copy constructor
    StrLL(StrLL&&); // move constructor

    //~StrLL(); // destructor // uncomment when ready to implement

    StrLL& operator=(const StrLL&); // copy assignment
    StrLL& operator=(StrLL&&); // move assignment

    // setters and getters
    void insertFront(char);
    void insertBack(char);
    void insertAfter(char, char);
    void insertBefore(char, char);

    void remove(char);

    void clear();

    bool hasChar(char) const;

    void print(std::ostream& = std::cout);
    void printReverse(std::ostream& = std::cout);
private:
    Node* find(char);
};

#endif