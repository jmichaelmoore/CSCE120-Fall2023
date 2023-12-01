#include <iostream>
#include "StrLL.h"
#include "Node.h"

StrLL::StrLL(const char* src) : head(nullptr), tail(nullptr) {
  size_t index = 0;
  if (src[index] == '\0') { return; }
  Node* head = new Node(src[0]);
  tail = head;
  index++;
  while (src[index] != '\0') {
    Node* newNode = new Node(src[index]);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    index++;
  }
}

void StrLL::copy(const StrLL& src) {
  if (src.head == nullptr) { return; }
  head = new Node(src.head->letter);
  tail = head;
  Node* cur = src.head->next;
  while (cur != nullptr) {
    Node* newNode = new Node(cur->letter);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

StrLL& StrLL::operator=(const StrLL& src) {
  if (this != &src) {
    this->clear();
    this->copy(src);
  }
  return *this;
}

StrLL::StrLL(const StrLL& src) : head(nullptr), tail(nullptr) {
  copy(src);
}

void StrLL::clear() {  while (head != nullptr) {
    Node* delNode = head;
    head = head->next;
    delete delNode;
    delNode = nullptr;
  }
  tail = nullptr;
}

StrLL::~StrLL() {
  clear();
}

void StrLL::remove(char val) {
  // remove the first instance of val from the linked list
  // if the val does not exist, we could throw an exception, but we'll just do nothing
  if (head == nullptr) { // check for empty list
    return;
  }
  Node* cur = head;
  while (cur != nullptr && (cur->letter != val)) {
    // boolean short circuit in while conditional
    //   order is important! we must check for nullptr before derferencing cur
    cur = cur->next;
  }
  // exit the loop because either reached end of list or found node with val
  // check to see which reason
  if (cur != nullptr) {  // cur points to node to delete
    if (cur->next == nullptr) { // removing tail, so update tail
      tail = tail->prev; // prev will be nullptr when removing single node from list
    }
    else {
        cur->next->prev = cur->prev;
    }
    if (cur->prev == nullptr) { // could also check if head == cur
      // removing head, so update head
      head = head->next; // head will be nullptr when removing a single node from the list
    }
    else { // cur->prev points to a node
      cur->prev->next = cur->next;
    }
    delete cur;
  }
  // else did not find val so do nothing

}

void StrLL::insertAfter(char valToFind, char valToInsert) {
  // find the first instance of valToFind and insert valToInsert after it
  // if we don't find val, we will insert at the end of the list
  if (head == nullptr) { // check for empty list empty list
    insertFront(valToInsert);
    return;
  }
  Node* cur = head;
  while (cur != nullptr && (cur->letter != valToFind)) {
    // boolean short circuit in while conditional
    //   order is important! we must check for nullptr before derferencing cur
    cur = cur->next;
  }
  // exit the loop because either reached end of list or found node with val
  // check to see which reason 
  if (cur == nullptr || cur == tail) { // reached end of list without finding val or node is the tail
    insertBack(valToInsert); // take advantage of my existing function
  }
  else { // found node to insert after that is not the tail
    Node* newNode = new Node(valToInsert);
    newNode->next = cur->next;
    newNode->prev = cur;
    cur->next = newNode;
    newNode->next->prev = newNode;
    if (cur == tail) { // we have a new tail
      tail = newNode;
    }
  }
  // will never be a new head
}

void StrLL::insertBefore(char valToFind, char valToInsert) {
  // find the first instance of valToFind and insert valToInsert before it
  // if we don't find val, we will insert at the beginning of the list
  if (head == nullptr) { // check for empty list empty list
    insertFront(valToInsert);
    return;
  }
  Node* cur = head;
  while (cur != nullptr && (cur->letter != valToFind)) {
    // boolean short circuit in while conditional
    //   order is important! we must check for nullptr before derferencing cur
    cur = cur->next;
  }
  // exit the loop because either reached end of list or found node with val
  // check to see which reason 
  if (cur == nullptr || cur == head) { // new head
    // reached end of list without finding val OR val is the first item in the list
    insertFront(valToInsert); // take advantage of my existing function
  }
  else { // found node to insert before that is not the head
    Node* newNode = new Node(valToInsert);
    newNode->next = cur;
    newNode->prev = cur->prev;
    cur->prev = newNode;
    newNode->prev->next = newNode;
    if (head == cur) { // new head
        head = newNode;
    }
    // will never be a new tail
  }
}

bool StrLL::hasChar(char val) const { // T must support == operator
  return (nullptr != find(val));
}

Node* StrLL::find(char val) {
  // return nullptr if not found
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->letter == val) {
      return cur;
    }
    cur = cur->next;
  }
  // if we get out of the loop, we did not find val
  return nullptr;
}

const Node* StrLL::find(char val) const {
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->letter == val) {
      return cur;
    }
    cur = cur->next;
  }
  // if we get out of the loop, we did not find val
  return nullptr;
}

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
