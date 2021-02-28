#include "DLNode.h"
#include <iostream>

/*
	Constructor for a node, constructs a node with the provided value, this node is not attached 
	to any node yet
	
	bigO linear, it will take only the same amout of steps every time 
*/
DLNode::DLNode(std::string initVal)
{
	_value = initVal;
	_next = _prev = NULL;
}
/*
	Method used to return the instance variable _value
	
	bigO(1)
*/
std::string&
DLNode::value()
{
	return _value;
}
/*
	Method used to return the instance variable _next
	
	bigO(1)
*/
DLNode* &
DLNode::next()
{
	return _next;
}
/*
	Method used to return the instance variable _prev
	
	bigO(1)
*/
DLNode* &
DLNode::prev()
{
	return _prev;
}
/*
	This method will print the value of this specific node
	
	bigO(1)
*/
std::ostream& 
DLNode::print(std::ostream &os) const
{
	os << _value;
	return os;
}
/*
	Simply calls the method print
	
	bigO(1)
*/
std::ostream& operator<< (std::ostream &os, const DLNode &node)
{
	return node.print(os);
}



