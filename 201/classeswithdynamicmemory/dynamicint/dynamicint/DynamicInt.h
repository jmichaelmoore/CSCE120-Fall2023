#ifndef DYNAMICINT_H
#define DYNAMICINT_H

#include<iostream>

class DynamicInt{
  int* val;
public:
  DynamicInt() : val(new int(0)) {}
  DynamicInt(int val) : val(new int(val)) {}
  DynamicInt& operator=(int val);
  int get() const { return *val; }
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