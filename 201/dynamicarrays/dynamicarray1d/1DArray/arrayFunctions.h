// header guards
#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

//const unsigned int CAPACITY = 100; // make largest size we will ever need

// functions to add
// loadRandom
// insert
// remove at index
// remove first of
// getMax // linear search
// getMin 
// count val
// print

void print(const int ary[], int size);
void loadRandom(int*& ary, int size, int& capacity);
void insert(int val, int index, 
          int ary[], int& size, int capacity);
void removeAtIndex(int index, 
          int ary[], int& size);
void removeFirstOf(int val, 
          int ary[], int size);
int getMax(const int ary[], int size);
int getMin(const int ary[], int size);
int countVal(int val, const int ary[], int size);

#endif