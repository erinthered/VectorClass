/**********************************************************************
Title:          Vector.cpp
Author:         Erin Williams
Date Created:   2/4/2016
Class:          Spring 2017, CSCI 235-04, Mon & Wed 7:00pm-6:50pm
Professor:      Aarsh Vora
Purpose:        Assignment #1
Description:    Implementation file for Vector Class. See Description
                in Vector.h for member function and variable descriptions
                and comments below for details.
***********************************************************************/

#include <iostream>
#include <cstdlib>

#include "Vector.h"

Vector::Vector(unsigned int capacity) : size_(0), capacity_(DEFAULT_CAPACITY) {
    arr_ = new int[capacity];
}

Vector::~Vector() {
    delete [] arr_;
}

Vector::Vector(const Vector& rhs) : size_(rhs.size_), capacity_(rhs.capacity_) {
    arr_ = new int[capacity_];
    for (int i = 0; i < size_; ++i) {
        arr_[i] = rhs.arr_[i];
    }
}

Vector& Vector::operator =(const Vector& rhs) {
   if (capacity_ != rhs.capacity_) {
        delete [] arr_;
        arr_ = new int[rhs.capacity_];
    }
   
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    for (int i = 0; i < size_; ++i) {
        arr_[i] = rhs.arr_[i];
    }

    return *this;
}

int Vector::operator [](unsigned int pos) const {
    if (pos >= size_) {
        std::cout << "Attempting to access an illegal index, program ending.\n";
        exit(1);
    }

    return arr_[pos];
}

int& Vector::operator [](unsigned int pos) {
    if (pos >= size_) {
        std::cout << "Attempting to access an illegal index, program ending.\n";
        exit(1);
    }
    
    return arr_[pos];
}

unsigned int Vector::capacity() const {
    return capacity_;
}

unsigned int Vector::size() const {
    return size_;
}

bool Vector::empty() const {
    return (size_ == 0);
}

void Vector::push_back(const int& data) {
    if (size_ == capacity_) {
        int double_capacity = (capacity_ * 2);
        resize(double_capacity);
     }
    
    arr_[size_] = data;
    ++size_;
}

bool Vector::remove(const int& data) {
    int index_of_data = search(data); 
    if (index_of_data < 0)
        return false;
    else {
        for (int i = index_of_data; i <= (size_-1); ++i) {
            arr_[i] = arr_[i+1];
        }
        --size_;
        return true;     
    }         
}

void Vector::clear() {
    delete [] arr_;
    arr_ = new int[DEFAULT_CAPACITY];
    size_ = 0;
    capacity_ = DEFAULT_CAPACITY;    
}

bool Vector::at(unsigned int pos, int& data) const {
    if (pos >= size_)
        return false;
    else {
        data = arr_[pos];
        return true;
    }
}

void Vector::resize(unsigned int capacity) {
    //Check for legal resizing
    if (capacity < size_) {
        std::cout << "Resizing to smaller capacity would result in data loss. Program ending.\n";
        exit(1);
    }

    int* temp_arr = new int[capacity];
    // copy information to new array with greater capacity and reassign pointer to new array
    for (int i = 0; i < size_; ++i) {
        temp_arr[i] = arr_[i];
    }
    delete [] arr_;
    arr_ = temp_arr;
    temp_arr = NULL;
    
    capacity_ = capacity;
}

int Vector::search(const unsigned int& data) {
    for (int index = 0; index < size_; ++index)
        if (arr_[index] == data)
            return index;
    return -1;
}

