// TreeData.h		Author: Sam Hoover
// contains the declarations for the TreeData class.
//
#ifndef TREEDATA_H
#define TREEDATA_H
#include <iostream>
using namespace std;

// TreeData
// a class containing a standard char. 
// Contains the following overloaded operators:
// operator==, operator!=, operator<, operator>, operator<=, operator>=,
// and operator<<
//
class TreeData {
	
	// output
	// prints m_data to the ostream.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	m_data printed to ostream
	//
	friend ostream& operator<<(ostream &sout, const TreeData &data);

public:
	// default constructor
	// creates a TreeData object with m_data equal to the space char
	// precondition:	none
	// postcondition:	creates a TreeData object with m_data = ' ' (sp)
	//
	TreeData();

	// constructor(char)
	// creates a TreeData object with m_data equal to data
	// precondition:	none
	// postcondition:	creates a TreeData object with m_data = data
	//
	TreeData(char data);

	// copy constructor
	// creates a TreeData object with m_data equal to data.m_data
	// precondition:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postcondition:	creates a TreeData object with m_data = data
	//
	TreeData(const TreeData &data);

	// getData
	// returns a char equal to m_data
	// preconditions:	this not equal to nullptr
	// postconditions:	returns char = m_data
	//
	char getData() const;

	// equality
	// Compares two TreeData objects. Uses standard char equality operator.
	// Returns true if m_data and data.m_data are equal, else false.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	Returns true if m_data = data.m_data, else false
	//
	bool operator==(const TreeData &data) const;

	// inequality
	// Compares two TreeData objects. Uses standard char inequality operator.
	// Returns true if m_data and data.m_data are not equal, else false.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	Returns true if m_data != data.m_data, else false
	//
	bool operator!=(const TreeData &data) const;

	// less-than
	// Compares two TreeData objects. Uses standard char less-than operator.
	// Returns true if m_data is less than data.m_data, else false.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	Returns true if m_data < data.m_data, else false
	//
	bool operator<(const TreeData &data) const;

	// greater-than
	// Compares two TreeData objects. Uses standard char greater-than operator.
	// Returns true if m_data is greater than data.m_data, else false.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	Returns true if m_data > data.m_data, else false
	//
	bool operator>(const TreeData &data) const;

	// less-than-equal
	// Compares two TreeData objects. Uses standard char less-than-equal 
	// operator. Returns true if m_data is less than or equal to data.m_data,
	// else false.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	Returns true if m_data <= data.m_data, else false
	//
	bool operator<=(const TreeData &data) const;

	// greater-than-equal
	// Compares two TreeData objects. Uses standard char greater-than-equal 
	// operator. Returns true if m_data is greater than or equal to data.m_data,
	// else false.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	Returns true if m_data >= data.m_data, else false
	//
	bool operator>=(const TreeData &data) const;

private:
	// m_data
	// a standard char
	//
	char m_data;
};

#endif