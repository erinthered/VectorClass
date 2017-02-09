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
	Vector(const Vector& rhs);             //Copy constructor
	Vector& operator=(const Vector& rhs);

        //Returns the size of the space currently allocated for the Vector
	unsigned int capacity() const;
        //Returns the current number of elements in the Vector from arr_[0] to arr_[size-1]
	unsigned int size() const;
        //Returns true if there are no elements in the Vector, false otherwise
	bool empty() const;

        //Add one element to the next available location at the end of
        //of the Vector. If the Vector's size has reached capacity, double 
        //allocated before adding the new element.
        //Postcondition: Vector contains one more element, size is incremented
	void push_back(const int& data);
        //Consecutively search the Vector for an integer, data. If a match is found, 
        //removes the first match found and returns true. Returns false otherwise. 
        //Postcondition: If data is removed from Vector, all elements after removed
        //element have shifted one element forward.
	bool remove(const int& data);

        //Empties the Vector of all elements and resets the capacity to 3.
        //Postcondition: size_ is 0, capacity_ is 3.	
	void clear();

        //Overloaded "index of" operator for Vector Class.
        //Can be used on the LHS of a statment, can't be used with const functions.
	int& operator[](unsigned int pos);
        //Overloaded "index of" operator for Vector Class.
        //Can't be used on the RHS of a statement, can be used with const functions.
        int operator[](unsigned int pos) const;
        //Checks that pos is a valid position in the Vector. If pos is valid, sets the 
        //integer data to Vector[pos] and returns true. If pos is not valid, returns false.
	bool at(unsigned int pos, int& data) const;


private:
	int* arr_;                   //dynamic array pointer
	unsigned int size_;          //number of elements in arr_
	unsigned int capacity_;      //current capacity of arr_

	static const unsigned int DEFAULT_CAPACITY = 3;

        //Resize array to double current capacity
        //Postcondition: capacity of array is doubled
	void resize(unsigned int capacity);
        //returns index of data if found and -1 if not found
        int search(const unsigned int& data);
        //Check that requested resizing is within legal bounds
        //Terminates program with error message if current number of elements in array > capacity
        void checkLegalCapacity(const unsigned int& capacity);
        //Check that requested position in array contains user entered data
        //Terminates program with error message to output stream if position is not valid
        void checkLegalPosition(unsigned int pos);
        //Overloaded function with const to be used in overloaded [] const function
        void checkLegalPosition(unsigned int pos) const;
        //Swap function for Vectors, used by resize
        void swap(unsigned int capacity);        
};

#endif
