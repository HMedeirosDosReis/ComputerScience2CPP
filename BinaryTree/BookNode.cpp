#include "BookNode.h"

#include <iostream>
using namespace std;

/*
	This method will call the operator<< to the value inside a node, which is a book,
	then it will print the book
*/
ostream& operator<<(ostream &os, const BookNode &node)
{
	os << node._value;
	return os;
}
