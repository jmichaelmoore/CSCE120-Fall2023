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
    DynamicArray(size_t size, T val);
    DynamicArray(const DynamicArray& src);
    DynamicArray(DynamicArray&& src);
    ~DynamicArray();
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    T at(size_t index) const;
    T& at(size_t index);
    DynamicArray& operator=(const DynamicArray& src);
    DynamicArray& operator=(DynamicArray&& src);
    void push_back(T val);
    void swap(DynamicArray& src);
};

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& src) :
        ary(src.ary), size_(src.size_), capacity_(src.capacity_) {
    src.ary = nullptr;
    src.size_ = 0;
    src.capacity_ = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& src) {
    if (this != &src) {
        this->clear();
        this->ary = src.ary;
        this->size_ = src.size_;
        this->capacity_ = src.capacity_;
        src.ary = nullptr;
        src.size_ = 0;
        src.capacity_ = 0;
    }
    return *this;
}

template <typename T>
void DynamicArray<T>::swap(DynamicArray& src) {
    //DynamicArray<T> temp = *this;
    //*this = src;
    //src = temp;
    T* temp = this->ary;
    size_t size = this->size_;
    size_t capacity = this->capacity_;
    this->ary = src.ary;
    this->size_ = src.size_;
    this->capacity_ = src.capacity_;
    src.ary = temp;
    src.size_ = size;
    src.capacity_ = capacity;
}

template <typename T>
void DynamicArray<T>::copy(const DynamicArray& src) {
    for (size_t i=0; i<size_; ++i) {
        this->ary[i] = src.ary[i];
    }
}

template <typename T>
void DynamicArray<T>::clear() {
    delete [] ary;
    ary = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& src) {
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
        ary(new T[src.capacity_]), size_(src.size_), capacity_(src.capacity_) {
            copy(src);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete [] ary;
    ary = nullptr;
    size_ = 0;
    capacity_ = 0;
}

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