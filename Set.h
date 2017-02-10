/**************************************************************
Title:          Set.h
Author:         Erin Williams
Date Created:   2/4/17
Class:          Spring 2017, CSCI 235-04, Mon & Wed 7:00pm-8:15pm
Professor:      Aarsh Vora
Purpose:        Assignment #1
Description:    Header file for Set Class. Set is a class that
                uses the Vector class to store data consisting
                of a set of unique integers. Public member 
                functions return the size of the set, return
                whether the set is empty or contains data and
                whether the set contains a particular integer,
                as well as functions that insert a new unique
                integer or remove an integer, or clear the 
                entire set.
*************************************************************/

#ifndef __CS235_SET_H_
#define __CS235_SET_H_

#include "Vector.h"

class Set {
public:
	Set();
        ~Set();
      
        //Return number of elements in the Set
        unsigned int size() const;
        //Return true if there are no elements in the Set, false otherwise
	bool empty() const;
	
        //Determines if a particular element, data, exists in the Set.
        //Returns true if a match for data is found, false if not found.
	bool contains(const int& data) const;
        //Determines if a particular element, data, exists in the Set.
        //If it does not already exist, data is added to the next position
        //in the Set and returns true, otherwise the element is not added and
        //returns false.		
	bool insert(const int& data);
        //If an element, data, is found in the Set, it is removed and returns
        //true, if data is not found, returns false.
	bool remove(const int& data);
        //Removes all elements from the Set.
	void clear();

private:
	Vector vector_;    //Stores Set data

};

#endif
