#ifndef _BOOK_NODE_H_
#define _BOOK_NODE_H_

#include "Book.h"
#include <iostream>


class BookNode
{
private:
	//instance variables of a binary tree node, they can have paths to right and left, in order to go back
	// they go to parent. Lastly the pointer to a book value, which will be the content of the node
	Book* _value;
	BookNode* _left;
	BookNode* _right;
	BookNode* _parent;
public:
	/*
		constructor, this will construct a node of a book pointer, which will be the only parameter
	*/
	BookNode(Book *value) {_value=value; _left=NULL; _right=NULL; _parent=NULL;}
	
	Book* value() const {return _value;}//Method used to return a pointer to the Book
	Book contents() const {return *_value;}//Method used to return the actual Book
	

	BookNode* left() const{return _left;}//Method that return what is in the left, this does not allow changes
	BookNode* &left() {return _left;}//Method that return what is in the left, this allows changes

	//Method that return what is in the right, this does not allow changes
	BookNode* right() const{return _right;}
	BookNode* &right() {return _right;}//Method that return what is in the right, this allows changes

	//Method that return what is in the parent node, this does not allow changes
	BookNode* parent() const {return _parent;}
	BookNode* &parent() {return _parent;}//Method that return what is in the parent node, this allows changes

	//This method is used to check if this node does not have any children
	bool isLeaf() const {return (!_left && !_right);}
	
	//Method used to print to the screen a BookNode
	friend std::ostream& operator<<(std::ostream &os, const BookNode &node);
};




#endif
