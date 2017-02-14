**************************************************************************************
Title:              README.txt
Author:             Erin Williams
Date Created:       2/11/2017
Class:              Spring 2017, CSCI 235-04, Mon & Wed 7:00pm-8:15pm
Professor:          Aarsh Vora
Purpose:            Assignment #1
Description:        Readme file for first project
***************************************************************************************

The makefile for this project compiles an executable, Project1, using the g++ compiler,
from the files Set.cpp, Vector.cpp, and Main.cpp. The make clean command is available.

All parts of this project are completed, nothing is incomplete.

There are no known bugs, and hopefully no unknown bugs.

Two classes are included in this project: a Vector class and a Set class. The Vector
class is a data structure to store integer values, which doubles it's capacity when
a user attempts to add additional data to a Vector that has reached capacity. A user can
add one integer value at a time to a Vector and remove existing data one integer at a time.
The Set class uses the Vector class as its underlying data structure to create a collection 
of unique integer values. Like the Vector class, data can be added and removed one integer
at a time. Both classes have the ability to remove all data and reset to a default empty
Vector with a capacity of three.

Notable algorithms in Vector Class:
~ Copy Constructor: Create a new dynamic array and copy each integer from index 0
  through index N-1, where N = the size of the used elements of the array.
~ Overloaded = operator: Check that the LHS array capacity is not the same as the RHS.
  If they are not the same, free the memory used by the LHS array and create a new
  dynamic array with the same capacity as the RHS array. Copy all member variables from
  RHS array to LHS array and copy each integer from RHS array from index 0 through index
  N-1, where N = the size of the used elements of the RHS array. Return pointer to LHS array.
~ Push back function: If the available capacity of the current vector is the same as the 
  currently used size, double the value of the capacity using resize function. Add integer
  value to the next element in array and increase size.
~ Resize function: Use checkLegalCapacity to make sure that the requested resizing is not 
  larger than current size of array to prevent data loss. End program if checkLegalCapacity 
  fails, else use swap function to move all data from old array to new array of resized capacity.
~ Swap function: Create new dynamic array of requested capacity size, copy data from existing
  array to new array, free memory from old array, reassign old array pointer to new array, set
  new array pointer to NULL.
~ Remove function: Use search function to determine if array contains the requested data. If 
  not found, return false. If found, move all one position forward in the array, from the position
  after the found data to the last used position in the array. Decrement size, return true.
~ Search function: search each used position in array sequentially until first instance of requested
  data is found, then return the position of the found data. If entire array is searched and
  data is not found, return -1.

Notable algorithms in Set Class:
~ Contains function: Set flag to false, search Vector sequentially for requested data, from 
  index 0 through index N-1, where N = the size of the last used element f the array. If the 
  data is found, set flag to true. Return the value of the flag.
~ Insert function: Check if the Vector contains the data. If the Vector contains the data, return
  false, else add data to the next available position at the end of the vector using push_back
  function from Vector class.
~ Remove function: Check if the vector contains the data. If the vector does not contain the 
  data return false, else remove the found data using the remove function from the Vector class.
   
