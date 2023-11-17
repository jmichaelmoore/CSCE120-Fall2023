#ifndef LL_H
#define LL_H

#include <iostream>

using std::cout, std::endl;

template <typename T>
struct Node {
  T data;
  Node* next;
  Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LL {
  Node<T>* head;
  Node<T>* tail;
  
  Node<T>* find(const T&) const; // T must support == operator

public:
  // constructors
  LL(); // default constructor
  LL(T data);
  LL(const LL&); // copy constructor
  LL(LL&&); // move constructor

  //~LL(); // destructor  // uncomment when ready to implement

  LL& operator=(const LL&); // copy assignment
  LL& operator=(LL&&); // move assignment

  // setters and getters
  void insertFront(const T&);
  void insertBack(const T&);
  void insertAfter(const T&);
  void insertBefore(const T&);

  void remove(const T&);

  void clear();

  bool hasValue(const T&) const; // T must support == operator

  void print(std::ostream& = std::cout) const; // T must support << operator
};

#endif