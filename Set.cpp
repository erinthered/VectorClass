#include "set.h"
#include "vector.h"

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
    for (int i = 0; i < vector_.size(); ++i) {
        if (data == vector_[i])
            contains_data = true;
            break;
    } 
    return contains_data;
}

bool Set::insert(const int& data) {
    if (empty() || !(contains(data))) {
        vector_.push_back(data);
        return true;
    } 
    else
        return false;
}

bool Set::remove(const int& data) {
    if (empty() || !(contains(data)))
        return false;
    else {
        vector_.remove(data);
        return true;
    }
}

void Set::clear() {
    vector_.clear();
}
