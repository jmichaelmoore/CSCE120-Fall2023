#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>
#include <sstream>

template <typename T>
class DynamicArray {
    T* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity(size_t size = 0);
    void clear();
    void copy(const DynamicArray& src);
public:
    DynamicArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicArray(size_t size, const T& val);
    DynamicArray(const DynamicArray& src);
    ~DynamicArray();
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    T at(size_t i) const;
    T& at(size_t i);
    T operator[](size_t i) const { return ary[i]; }
    T& operator[](size_t i) { return ary[i]; }
    DynamicArray& operator=(const DynamicArray& src);
    void push_back(T val);
};

template <typename T>
void DynamicArray<T>::copy(const DynamicArray& src) {
    for (size_t i=0; i<size_; ++i) {
        ary[i] = src.ary[i];
    }
}

template <typename T>
void DynamicArray<T>::clear() {
    delete [] ary;
    ary = nullptr; // I forgot this in class, but should set to nullptr
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& src) {
    // check for self assignment
    if (this != &src) {
        clear();
        capacity_ = src.capacity_;
        size_ = src.size_;
        ary = new T[capacity_];
        copy(src);
    }
    return *this;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& src) :
       ary(new T[src.capacity_]), size_(src.size_), 
       capacity_(src.capacity_) {
    // copy
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    clear();
}

template <typename T>
void DynamicArray<T>::push_back(T val) {
    if (size_ == capacity_) {
        increaseCapacity();
    }
    ary[size_] = val;
    size_++;
}


template <typename T>
T DynamicArray<T>::at(size_t i) const {
    if (i >= size_) {
        std::ostringstream oss;
        oss << "index out of bounds. index is " << i << " which is greater than or equal to size " << size_;
        throw std::out_of_range(oss.str());
    }
    return ary[i];
}

template <typename T>
T& DynamicArray<T>::at(size_t i) {
    if (i >= size_) {
        std::ostringstream oss;
        oss << "index out of bounds. index is " << i << " which is greater than or equal to size " << size_;
        throw std::out_of_range(oss.str());
    }
    return ary[i];
}

template <typename T>
DynamicArray<T>::DynamicArray(size_t size, const T& val) : 
    ary(new T[size]), size_(size), capacity_(size) {
    // now initialize
    for (size_t i=0; i<size_; ++i) {
        ary[i] = val;
    }
}

template <typename T>
void DynamicArray<T>::increaseCapacity(size_t size) {
    if (size == 0) {
        if (capacity_ == 0) {
            capacity_ = 1;
        }
        else {
            capacity_ *=2; 
        }
    }
    else {
        if (capacity_ < size) {
            capacity_ = size; 
        }
    }
    // allocate new memory
    T* tempAry = new T[capacity_];

    // copy
    for (size_t i = 0; i < size_ ; ++i) {
        tempAry[i] = ary[i];
    }

    // delete old memory
    delete [] ary;

    // clean up
    ary = tempAry;
    tempAry = nullptr;
}

#endif