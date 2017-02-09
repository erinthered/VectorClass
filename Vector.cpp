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

//Initalize new empty vector with a capacity of 3
Vector::Vector(unsigned int capacity) : size_(0), capacity_(DEFAULT_CAPACITY) {
    arr_ = new int[capacity];
}

Vector::~Vector() {
    delete [] arr_;
}

Vector::Vector(const Vector& rhs) : size_(rhs.size_), capacity_(rhs.capacity_) {
    if (&arr_ != &rhs.arr_) {      //check for same array
        arr_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = rhs.arr_[i];           //copy data to new Vector
        }
    }
}

Vector& Vector::operator =(const Vector& rhs) {
   if (&arr_ == &rhs.arr_)         //check for same array
        return *this;
    else {
        delete [] arr_;
        arr_ = new int[rhs.capacity_];
        capacity_ = rhs.capacity_;
        size_ = rhs.size_;
        for (int i = 0; i < size_; ++i) {
            arr_[i] = rhs.arr_[i];
        }
        return *this;
    }
}

int Vector::operator [](unsigned int pos) const {
    //Terminates program with error output message if position does not contain data
    checkLegalPosition(pos);

    return arr_[pos];
}

int& Vector::operator [](unsigned int pos) {
    //Terminates program with error output message if position does not contain data
    checkLegalPosition(pos);
    
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
    if (size_ == capacity_) {     //check if new element will fit in current capacity of Vector
        int double_capacity = (capacity_ * 2);
        resize(double_capacity);  //double capacity of Vector
     }
    
    arr_[size_] = data;           //add data to end of array
    ++size_;
}

bool Vector::remove(const int& data) {
    int index_of_data = search(data);  //search for data in array
    if (index_of_data < 0)             //search function returns -1 if data not found
        return false;
    else {
        //remove data if found and move all elements after index of data forward one position
        for (int i = index_of_data; i <= (size_-1); ++i) {
            arr_[i] = arr_[i+1];      //current array index  contains data of next array index
        }
        --size_;
        return true;     
    }         
}

void Vector::clear() {
    delete [] arr_;                    //delete contents of old array
    arr_ = new int[DEFAULT_CAPACITY];  //new dynamic array of capacity 3
    size_ = 0;
    capacity_ = DEFAULT_CAPACITY;      
}

bool Vector::at(unsigned int pos, int& data) const {
    if (pos >= size_)                   //check for valid position
        return false;
    else {
        data = arr_[pos];               //insert data into pos if valid
        return true;
    }
}

void Vector::resize(unsigned int capacity) {
    //check for potential data loss
    checkLegalCapacity(capacity);     

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

void Vector::checkLegalCapacity(const unsigned int& capacity) {
    //checks that requested resizing is larger than current size of used array
    if (capacity < size_) {
        std::cout << "Resizing to smaller capacity would result in data loss. Program ending.\n";
        exit(1);
    }
}

void Vector::checkLegalPosition(unsigned int pos) {
    if (pos >= size_) {          //check that pos is a currently used element of array
        std::cout << "Attempting to access an illegal index, program ending.\n";
        std::exit(1);
    } 
}

void Vector::checkLegalPosition(unsigned int pos) const {
    if (pos >= size_) {          //check that pos is a currently used element of array
        std::cout << "Attempting to access an illegal index, program ending.\n";
        std::exit(1);
    } 
}

