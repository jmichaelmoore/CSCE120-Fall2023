#ifndef DYNAMICINT_H
#define DYNAMICINT_H

#include <iostream>

class DynamicInt{
  int* val;
public:
  DynamicInt() : val(nullptr) {};
  DynamicInt(int val) : val(new int(val)) {}
  int get() const { return *val; }
  DynamicInt& operator=(int val);
};

DynamicInt& DynamicInt::operator=(int val) { 
  *(this->val) = val;
  return *this; 
}

std::ostream& operator<<(std::ostream& os, const DynamicInt& src) {
  os << src.get();
  return os;
}

#endif