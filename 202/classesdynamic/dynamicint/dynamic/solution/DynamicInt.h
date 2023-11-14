#ifndef DYNAMICINT_H
#define DYNAMICINT_H

#include <iostream>

class DynamicInt{
  int* val;
public:
  DynamicInt() : val(new int(0)) {}
  DynamicInt(int val) : val(new int(val)) {}
  DynamicInt(const DynamicInt& src);            // copy constructor
  DynamicInt(DynamicInt&& src);                 // move constructor
  ~DynamicInt();                                // destructor
  int get() const { return *val; }
  DynamicInt& operator=(int val);
  DynamicInt& operator=(const DynamicInt& src); // copy assignment
  DynamicInt& operator=(DynamicInt&& src);      // move assignment
};

// copy constructor
DynamicInt::DynamicInt(const DynamicInt& src) : val(nullptr) {
  *val = src.get();
}

// move constructor
DynamicInt::DynamicInt(DynamicInt&& src) : val(src.val) {
  src.val = nullptr;
}

// destructor
DynamicInt::~DynamicInt() {
  delete val;
  val = nullptr;
}

// a copy assignment
DynamicInt& DynamicInt::operator=(int val) {
  *(this->val) = val;
  return *this; 
}

// the copy assignment
DynamicInt& DynamicInt::operator=(const DynamicInt& src) {
  delete this->val;
  this->val = new int(src.get());
  return *this;
}

// move assignment
DynamicInt& DynamicInt::operator=(DynamicInt&& src) {
  this->val = src.val;
  src.val = nullptr;
  return *this;
}

// overloaded output operator
std::ostream& operator<<(std::ostream& os, const DynamicInt& src) {
  os << src.get();
  return os;
}

#endif