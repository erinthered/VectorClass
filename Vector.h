#ifndef __CS235_VECTOR_H_
#define __CS235_VECTOR_H_

/********************************************************************
Title:           Vector.h
Author:          Erin Williams
Date Created:    2/4/2017
Class:           Spring 2017, CSCI 235-04, Mon & Wed 7:00pm-8:15pm
Professor:       Aarsh Vora
Purpose:         Assignment #1
Description:     Header file for Vector class. Contains a constructor
                 initializing a vector object to a default capacity of
                 three, a desructor, a copy constructor, an overloaded
                 = operator, public member functions that return 
                 the current capacity and size of a Vector object and
                 whether or not the Vector currently contains data, 
                 public member functions to add data to the end of the
                 vector, to remove a specific instance of data, to
                 remove all data from the vector, and to add data to a
                 valid position in the vector. The [] operator is also
                 overloaded in two versions (LHS version, RHS version).
                 The private member variables contain a pointer to a
                 dynamic array and integer values of the current size
                 and capacity of the array/Vector.
***********************************************************************/ 

class Vector {
public:
	Vector(unsigned int capacity = DEFAULT_CAPACITY);
	~Vector();
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);

	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;

	void push_back(const int& data);
	bool remove(const int& data);
	
	void clear();

	int& operator[](unsigned int pos);
        int operator[](unsigned int pos) const;
	bool at(unsigned int pos, int& data) const;


private:
	int* arr_;
	unsigned int size_;
	unsigned int capacity_;

	static const unsigned int DEFAULT_CAPACITY = 3;

	void resize(unsigned int capacity);

        //returns index of data if found and -1 if not found
        int search(const unsigned int& data);	
};

#endif
