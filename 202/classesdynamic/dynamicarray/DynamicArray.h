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
public:
    DynamicArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicArray(size_t size, T val);
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    T at(size_t index) const;
    T& at(size_t index);
    void push_back(T val);
};

template <typename T>
void DynamicArray<T>::increaseCapacity(size_t size) {
    if (size == 0) {
        if (capacity_ == 0) {
            capacity_ = 1;
        }
        else {
            capacity_ *= 2;
        }
    }
    else {
        if (size >= capacity_) {
            capacity_ = size;
        }
    }

    // create new array
    T* tempAry = new T[capacity_];

    // copy values
    for (size_t i = 0; i<size_; ++i) {
        tempAry[i] = ary[i];
    }

    // delete old memory
    delete [] ary;

    // clean up
    ary = tempAry;
    tempAry = nullptr;
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
T DynamicArray<T>::at(size_t index) const {
    if (index >= size_) {
        std::ostringstream oss;
        oss << "index out of bounds. index " << index << " is greater than or equal to size " << size_;
        throw std::out_of_range(oss.str());
    }
    return ary[index];
}

template <typename T>
T& DynamicArray<T>::at(size_t index) {
    if (index >= size_) {
        std::ostringstream oss;
        oss << "index out of bounds. index " << index << " is greater than or equal to size " << size_;
        throw std::out_of_range(oss.str());
    }
    return ary[index];
}

template <typename T>
DynamicArray<T>::DynamicArray(size_t size, T val) :
    ary(new T[size]), size_(size), capacity_(size) {
    for (size_t i=0; i<size_; ++i) {
        ary[i] = val;
    }
}

#endif