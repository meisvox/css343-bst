// TreeData.cpp		Author: Sam Hoover
// contains the definitions for the TreeData class.
//
#ifndef TREEDATA_CPP
#define TREEDATA_CPP
#include "TreeData.h"

// default constructor
// creates a TreeData object with m_data equal to the space char
// precondition:	none
// postcondition:	creates a TreeData object with m_data = ' ' (sp)
//
TreeData::TreeData() : m_data(' ') {}

// constructor(char)
// creates a TreeData object with m_data equal to data
// precondition:	none
// postcondition:	creates a TreeData object with m_data = data
//
TreeData::TreeData(char data) : m_data(data) {}

// copy constructor
// creates a TreeData object with m_data equal to data.m_data
// precondition:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postcondition:	creates a TreeData object with m_data = data
//
TreeData::TreeData(const TreeData &data) : m_data(data.m_data) {}

// getData
// returns a char equal to m_data
// preconditions:	this not equal to nullptr
// postconditions:	returns char = m_data
//
char TreeData::getData() const {
	return(m_data);
}

// equality
// Compares two TreeData objects. Uses standard char equality operator.
// Returns true if m_data and data.m_data are equal, else false.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	Returns true if m_data = data.m_data, else false
//
bool TreeData::operator==(const TreeData &data) const {
	if(m_data == data.m_data) {
		return(true);
	}
	return(false);
}

// inequality
// Compares two TreeData objects. Uses standard char inequality operator.
// Returns true if m_data and data.m_data are not equal, else false.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	Returns true if m_data != data.m_data, else false
//
bool TreeData::operator!=(const TreeData &data) const {
	if(!(*this == data)) {
		return(true);
	}
	return(false);
}

// less-than
// Compares two TreeData objects. Uses standard char less-than operator.
// Returns true if m_data is less than data.m_data, else false.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	Returns true if m_data < data.m_data, else false
//
bool TreeData::operator<(const TreeData &data) const {
	if(m_data < data.m_data) {
		return(true);
	}
	return(false);
}

// greater-than
// Compares two TreeData objects. Uses standard char greater-than operator.
// Returns true if m_data is greater than data.m_data, else false.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	Returns true if m_data > data.m_data, else false
//
bool TreeData::operator>(const TreeData &data) const {
	if(m_data > data.m_data) {
		return(true);
	}
	return(false);
}

// less-than-equal
// Compares two TreeData objects. Uses standard char less-than-equal 
// operator. Returns true if m_data is less than or equal to data.m_data,
// else false.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	Returns true if m_data <= data.m_data, else false
//
bool TreeData::operator<=(const TreeData &data) const {
	if(m_data < data.m_data || m_data == data.m_data) {
		return(true);
	}
	return(false);
}

// greater-than-equal
// Compares two TreeData objects. Uses standard char greater-than-equal 
// operator. Returns true if m_data is greater than or equal to data.m_data,
// else false.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	Returns true if m_data >= data.m_data, else false
//
bool TreeData::operator>=(const TreeData &data) const {
	if(m_data > data.m_data || m_data == data.m_data) {
		return(true);
	}
	return(false);
}

// output
// prints m_data to the ostream.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr)
// postconditions:	m_data printed to ostream
//
ostream& operator<<(ostream &sout, const TreeData &data) {
	sout << data.getData();
	return(sout);
}

#endif