#ifndef _BOOK_TREE_
#define _BOOK_TREE_
#include "BookNode.h"
#include <iostream>
class BookTree
{
private:
	BookNode* _root; //In the beggining of a tree, it will only have a root, which will also be empty 
public:
	BookTree() :  _root(NULL) {} //Constructor for a BookTree, simply sets the root as NULL
	
	//Method to return the root of my tree, will be used to tell where the root is
	BookNode* root() {return _root;}
	//Method used to add a node to the tree, needs a BookNode Pointer as parameter
	void addBook(BookNode* value);
	//Method used to delete a node to the tree, needs a BookNode Pointer as parameter
	void eraseBook(BookNode* value);

	//Method used to find a book in the tree, needs a BookNode Pointer as parameter, and will return one too
	BookNode* findBook(BookNode* value) const;
	
	//Method used to find a book searching by title
	void findTitle(const std::string value, BookNode *subtree) const;
	//this method will just call the findTitle from the _root
	void findTitle(const std::string value) const {findTitle(value, _root);}
	//Method used to find a book searching by author
	void findAuthor(const std::string value, BookNode *subtree) const;
	//this method will just call the findAuthor from the _root
	void findAuthor(const std::string value) const {findAuthor(value, _root);}
	
	//This method checks how many steps I will need to take in order to find a book with full data
	int findMaxBooks(BookNode* myBook) const;
	void checkout(Book* value);//Method used to simply check out a book
	void returnBook(Book* value);//Method used to simply return a book to the library
		
	void inOrderPrint(BookNode *subtree) const;//Method used to print the tree in ascending order
	
   //This method will call the inOrderPrint method from the _root and separate the beggining and end by a line
	std::ostream& print(std::ostream &os) const;
	
	//This method simply call the print method from the os variable
	friend std::ostream& operator<<(std::ostream &os, const BookTree &tree){return tree.print(os);}
};
#endif
