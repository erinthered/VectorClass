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
        unsigned int size() const;
	bool empty() const;
	
	bool contains(const int& data) const;
		
	bool insert(const int& data);
	bool remove(const int& data);

	void clear();

private:
	Vector vector_;

};

#endif
