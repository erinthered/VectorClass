#include "Vector.h"

Vector::Vector(unsigned int capacity) : size_(0), capacity_(capacity) {
    arr_ = new int[capacity];
}

Vector::~Vector() {
    delete [] arr_;
}

Vector::Vector(const Vector& rhs) : size_(rhs.size_), capacity_(rhs.capacity) {
    arr_ = new int[capacity];
    for (int i = 0; i < size_; ++i)
        arr_[i] = rhs.arr_[i];
}

Vector& Vector::operator =(const Vector& rhs) {
   if (capacity_ != rhs.capacity_) {
        delete [] arr_;
        arr = new int [rhs.arr_];
    }
   
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
}


