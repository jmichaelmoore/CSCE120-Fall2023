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
  LL() : head(nullptr), tail(nullptr) {} // default constructor
  LL(const T& data);
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

template <typename T>
void LL<T>::print(std::ostream& os) const {
  Node<T>* cur = head;
  if (cur == nullptr) {
    os << "Empty List!" << endl;
  }
  while (cur != nullptr) {
    os << cur->data << endl;
    cur = cur->next;
  }
}

template <typename T>
void LL<T>::insertFront(const T& data) {
  Node<T>* newNode = new Node<T>(data);
  newNode->next = head;
  head = newNode;
  if (tail == nullptr) {
    tail = newNode;
  }
}

template <typename T>
void LL<T>::insertBack(const T& data) {
  Node<T>* newNode = new Node<T>(data);
  if (tail == nullptr) { // empty list
    head = newNode;
    tail = newNode;
    return;
  }
  tail->next = newNode;
  tail = newNode;
}


template <typename T>
LL<T>::LL(const T& data) : head(nullptr), tail(nullptr) {
  Node<T>* newNode = new Node<T>(data);
  head = newNode;
  tail = newNode;
}

#endif