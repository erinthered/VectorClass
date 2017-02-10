/**********************************************************************
Title:              Set.cpp
Author:             Erin Williams
Date Created:       2/4/17
Class:              Spring 2017, CSCI 235-04, Mon & Wed 7:00pm-8:15pm
Professor:          Aarsh Vora
Purpose:            Assignment #1
Description:        Implementation file for the Set class. See Set.h
                    for description of class functions and comments
                    below for details.
**********************************************************************/

#include "Set.h"
#include "Vector.h"

Set::Set() {
    vector_ = Vector(3);
}

Set::~Set() { }

unsigned int Set::size() const {
    return vector_.size();
}

bool Set::empty() const {
   return vector_.empty(); 
}

bool Set::contains(const int& data) const {
    bool contains_data = false;
    for (unsigned int i = 0; i < vector_.size(); ++i) {
        if (data == vector_[i]) {             //search Vector for data
            contains_data = true;             //if found, return true
            return contains_data;
        }
    } 
    return contains_data;
}

bool Set::insert(const int& data) {
    //If data does not already exist in Set, add data to Set.
    if (empty() || !(contains(data))) {
        vector_.push_back(data);
        return true;
    } 
    else                
        return false;
}

bool Set::remove(const int& data) {
    //If data does not exist, return false
    if (empty() || !(contains(data)))
        return false;
    else {
        vector_.remove(data);          //Remove data from Set
        return true;
    }
}

void Set::clear() {
    vector_.clear();
}
