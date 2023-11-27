#ifndef LL_H
#define LL_H

#include <iostream>

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
  void copy(const LL& src);

public:
  // constructors
  LL() : head(nullptr), tail(nullptr) {} // default constructor
  LL(const T& data);
  LL(const LL&); // copy constructor
  LL(LL&&); // move constructor

  ~LL(); // destructor  // uncomment when ready to implement

  LL& operator=(const LL&); // copy assignment
  LL& operator=(LL&&); // move assignment

  // setters and getters
  void insertFront(const T&);
  void insertBack(const T&);
  void insertAfter(const T& valToFind, const T& valToInsert);
  void insertBefore(const T& valToFind, const T& valToInsert);

  void remove(const T&);

  void clear();

  bool hasValue(const T&) const; // T must support == operator

  void print(std::ostream& = std::cout) const; // T must support << operator
};

template <typename T>
LL<T>& LL<T>::operator=(LL&& src) {
  if (this != &src) {
    this->clear();
    this->head = src.head;
    this->tail = src.tail;
    src.head = nullptr;
    src.tail = nullptr;
  }
  return *this;
}

template <typename T>
LL<T>::LL(LL&& src) {
  this->head = src.head;
  this->tail = src.tail;
  src.head = nullptr;
  src.tail = nullptr;
}

template <typename T>
void LL<T>::copy(const LL& src) {
  if (src.head == nullptr) { return; }
  this->head = new Node(src.head->data);
  this->tail = head;
  Node<T>* cur = src.head->next;
  while (cur != nullptr) {
    Node<T>* newNode = new Node<T>(cur->data);
    this->tail->next = newNode;
    this->tail = newNode;
    cur = cur->next;
  }
}

template <typename T>
LL<T>& LL<T>::operator=(const LL& src) { // copy assignment
  if (this != &src) {
    clear();
    copy(src);
  }
  return *this;
}

template <typename T>
LL<T>::LL(const LL& src) : head(nullptr), tail(nullptr) {
  copy(src);
}

template <typename T>
void LL<T>::clear() {
  while (head != nullptr) {
    Node<T>* delNode = head;
    head = head->next;
    delete delNode;
    delNode = nullptr;
  }
  tail = nullptr;
}

template <typename T>
LL<T>::~LL() {
  clear();
}

template <typename T>
void LL<T>::remove(const T& val) {
  // remove the first instance of val from the linked list
  // if the val does not exist, we could throw an exception, but we'll just do nothing
  if (head == nullptr) { // check for empty list
    return;
  }
  Node<T>* cur = head;
  Node<T>* prev = nullptr; // initialize to nullptr
  // when we find val, cur has no way to get to the previous node. 
  //   So we keep an additional pointer for prev
  while (cur != nullptr && (cur->data != val)) {
    // boolean short circuit in while conditional
    //   order is important! we must check for nullptr before derferencing cur
    prev = cur;
    cur = cur->next;
  }
  // exit the loop because either reached end of list or found node with val
  // check to see which reason
  if (cur != nullptr) {  // cur points to node to delete
    if (tail == cur) { // removing tail, so update tail
      tail = prev; // prev will be nullptr when removing single node from list
    }
    if (prev == nullptr) { // could also check if head == cur
      // removing head, so update head
      head = head->next; // head will be nullptr when removing a single node from the list
    }
    else { // prev points to a node
      prev->next = cur->next;
    }
    delete cur;
  }
  // else did not find val so do nothing

}

template <typename T>
void LL<T>::insertAfter(const T& valToFind, const T& valToInsert) {
  // find the first instance of valToFind and insert valToInsert after it
  // if we don't find val, we will insert at the end of the list
  if (head == nullptr) { // check for empty list empty list
    insertFront(valToInsert);
    return;
  }
  Node<T>* cur = head;
  while (cur != nullptr && (cur->data != valToFind)) {
    // boolean short circuit in while conditional
    //   order is important! we must check for nullptr before derferencing cur
    cur = cur->next;
  }
  // exit the loop because either reached end of list or found node with val
  // check to see which reason 
  if (cur == nullptr) { // reached end of list without finding val
    insertBack(valToInsert); // take advantage of my existing function
  }
  else { // found node to insert after
    Node<T>* newNode = new Node<T>(valToInsert);
    newNode->next = cur->next;
    cur->next = newNode;
    if (cur == tail) { // check if we have a new tail
      tail = newNode;
    }
  }
}

template <typename T>
void LL<T>::insertBefore(const T& valToFind, const T& valToInsert) {
  // find the first instance of valToFind and insert valToInsert before it
  // if we don't find val, we will insert at the beginning of the list
  if (head == nullptr) { // check for empty list empty list
    insertFront(valToInsert);
    return;
  }
  Node<T>* cur = head;
  Node<T>* prev = nullptr; // initialize to nullptr to check if new head
  // when we find val, cur has no way to get to the previous node. 
  //   So we keep an additional pointer for prev
  while (cur != nullptr && (cur->data != valToFind)) {
    // boolean short circuit in while conditional
    //   order is important! we must check for nullptr before derferencing cur
    prev = cur;
    cur = cur->next;
  }
  // exit the loop because either reached end of list or found node with val
  // check to see which reason 
  if (cur == nullptr || prev == nullptr) { // new head
    // reached end of list without finding val OR val is the first item in the list
    insertFront(valToInsert); // take advantage of my existing function
  }
  else { // found node to insert before
    Node<T>* newNode = new Node<T>(valToInsert);
    newNode->next = cur;
    prev->next = newNode;
    // will never be a new tail
  }
}

template <typename T>
bool LL<T>::hasValue(const T& val) const { // T must support == operator
  return (nullptr != find(val));
}

template <typename T>
Node<T>* LL<T>::find(const T& val) const {
  // return nullptr if not found
  Node<T>* cur = head;
  while (cur != nullptr) {
    if (cur->data == val) {
      return cur;
    }
    cur = cur->next;
  }
  // if we get out of the loop, we did not find val
  return nullptr;
}

template <typename T> 
 LL<T>::LL(const T& data) : head(nullptr), tail(nullptr) {
  Node<T>* newNode = new Node<T>(data);
  head = newNode;
  tail = newNode;
 }

template <typename T>
void LL<T>::insertFront(const T& data) {
  Node<T>* newNode = new Node<T>(data);
  newNode->next = head;
  head = newNode;
  if (tail==nullptr) {
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
  // tail is nollptr
  tail->next = newNode; 
  tail = newNode;
}

template <typename T>
void LL<T>::print(std::ostream& os) const {
  // traversal
  Node<T>* cur = head;
  if (cur == nullptr) {
    os << "Empty List!" << std::endl;
  }
  while (cur != nullptr) {
    os << cur->data << std::endl;
    cur = cur->next;
  }
}

#endif