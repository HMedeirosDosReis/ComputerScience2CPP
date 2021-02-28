#include "BookTree.h"
#include <iomanip>
#include <iostream>
using namespace std;

/*
	This methods adds a book to the tree in the correct place. Needs a BookNode pointer 
	as a parameter in order to do it
*/
void 
BookTree::addBook(BookNode* value)
{
	//checks to see if I am trying to add a empty node to the the tree, there is no book without a title
	if(value->value()->title()=="")
		return;// if so, I am done, dont need to do anything
	if (!_root)//check if the tree is empty
	{//if so
		_root = value;//my root is the value and i am done
		return;
	}
	//if i get here, the tree isnt empty
	BookNode *curr=_root;  // will hold location we are to place value
	BookNode *prev;        // will hold the parent of location we are trying place newNode

	while(curr!=NULL)
	{
		prev = curr; // update prev
		// update curr
		if (value->contents() < curr->contents())
			curr = curr->left();
		else // value > curr->value()
			curr = curr->right();
	}
	// when done with loop, prev holds the parent of the location we want to add. 
	if (value->contents() < prev->contents())// go to leaf from the left, in case the book i want to add is 
                                             //smaller
		prev->left() = value;
	else //we came from the right
		prev->right() = value;
	value->parent() = prev;// parent will hold the previous node 
}
/*
	This method will find a book in the tree when given a book. It needs a BookNode pointer as a paramenter and will also return one.
*/
BookNode* 
BookTree::findBook(BookNode* value) const
{
	BookNode *curr = _root;//start at the root
	while (curr!=NULL)//keep going until I am a node
	{
		if(curr->contents()==value->contents())//in case the contents of this node and the value are the same
			return curr;//i found and i am done, return this node
		else if (value->contents() < curr->contents()) //I am not the same, but i am smaller
			curr = curr->left();//go to the left
		else // not == or < , must be > 
			curr = curr->right();//go to the right
	}
	return NULL;//i went through the whole tree and didnt find it
}
/*
	Method used to delete a book. Needs a BookNode pointer, which will be the value that will be deleted and
	will return nothing.
*/
void
BookTree::eraseBook(BookNode* value)
{
	BookNode *toDel = findBook(value);//try to find what you want to delete in the tree
	if (!toDel)//toDel is null, the book doesnt exist in the tree, send a message to the user
	{
		cerr << "This book: " << value <<"does not exist in the library"<< endl;
		return;
	}
	//in case of deleting a leaf node 
	if (toDel->isLeaf())
	{
		if (toDel == _root)//i am a leaf, but also the root, the tree is now empty
			_root = NULL;
		else //I am not the root
		{
			BookNode *parent = toDel->parent();//find my parent and let them know they dont have 
			//this child anymore
			if (parent->left() == toDel)
				parent->left() = NULL;
			else // must be right child
				parent->right() = NULL;
		}
		toDel->parent() = NULL;
		delete toDel;//give the memory back to the program
	}
	//In case I have one child
	else if ( ( toDel->right()!=NULL && toDel->left()==NULL) || // we have only a right child
              ( toDel->left()!=NULL && toDel->right()==NULL)    // we have only a left child
             )
	{
		if (toDel == _root)//am i the root and i have one child?
		{//which child do I have?
			if (toDel->right() !=NULL)// the right child
			{
				_root = toDel->right();
				_root->parent() = NULL;
			}
			else//must be the left child
			{
				_root = toDel->left();
				_root->parent() = NULL;
			}
			toDel->left() = toDel->right() = toDel->parent() = NULL;//clean up extra pointers
			delete toDel;//give the storage back
			return;//i am done
		}
		// if I got here, toDel is not the root, but has 1 child. 
		BookNode *subTree;
		//which child do I have?
		if (toDel->left() != NULL)
			subTree = toDel->left();
		else // the child must be the right child
			subTree = toDel->right();
			
		BookNode *parent = toDel->parent();//set a space for the my parent 
		//update my parent based on which child i have
		if (parent->right()==toDel)
			parent->right() = subTree;
		else if (parent->left()==toDel)
			parent->left() = subTree;

		subTree->parent() = parent;
		toDel -> left() = toDel -> right() = toDel -> parent() = NULL; //clean up extra pointers
		delete toDel;// give the storage back
		//do not need to return here beacuse the next cause will only executes if this one doesnt
	}
	else // we have two children
	{
		BookNode *curr = toDel->right(); // goal: curr will hold the smallest node bigger than toDel
		//go one to the right and then as far as you can to the left
		while (curr->left()!=NULL)
			curr = curr->left();

		BookNode* smallestInRightSubTree = curr;//store the variable in a new place
		eraseBook(curr);//take care of this recursivelly
		toDel = smallestInRightSubTree;// update toDel
	}
	
}
/*
	Method used to find the maximum number of steps I can take in order to find a book with full data.
	It needs a BookNode pointer as a parameter
	Returns an int representing the number of steps
*/
int
BookTree::findMaxBooks(BookNode* myBook) const
{
	if(myBook ==NULL)//If i am the end of the tree, return 0 
		return 0;
	int maxLeft, maxRight;//declare two ints that will represent which side of the tree is bigger
	//take care of this recursivelly
	maxLeft = findMaxBooks(myBook->left());
	maxRight = findMaxBooks(myBook->right());
	if(maxLeft > maxRight)//which side is bigger?
		return maxLeft +1;//return the left side + 1, which is the level I started 
	return maxRight+1;//return the right side + 1, which is the level I started 
}
/*
	Method used to find all books with a determined title. 
	Needs a string, that is the title of the book we are searching, and a BookNode pointer that will be used
	to find the answer recursivelly
*/
void
BookTree::findTitle(const string value, BookNode *subtree)const 
{
	if(_root!=NULL)//if the tree isnt empty
	{
		if(subtree->left() !=NULL)//my left pointer is not empty?
			findTitle(value, subtree->left());//find the solution from the left side
		if (subtree->value()->title() == value)//in case we find a match for the title
		{//go ahead an update the number of searches and print the whole information for this book
			subtree->value()->upSearches();
			subtree->value()->printWholeBook(cout);
			cout<<endl;
		}
		if(subtree->right()!=NULL)//my left pointer is not empty?
			findTitle(value, subtree->right());	// find the solution from the right side
	}
}
/*
	Method used to find all books with a determined author. 
	Needs a string, that is the author of the book we are searching, and a BookNode pointer that will be used
	to find the answer recursivelly
*/
void
BookTree::findAuthor(const string value, BookNode *subtree)const 
{
	if(_root!=NULL)//if the tree isnt empty
	{
		if(subtree->left() !=NULL)//my left pointer is not empty?
			findAuthor(value, subtree->left());//find the solution from the left side
		if (subtree->value()->author() == value)//in case we find a match for the title
		{//go ahead an update the number of searches and print the whole information for this book
			subtree->value()->upSearches();
			subtree->value()->printWholeBook(cout);
			cout<<endl;
		}
		if(subtree->right()!=NULL)//my left pointer is not empty?
			findAuthor(value, subtree->right());	// find the solution from the right side
	}
}
/*
	Method used to checkout a book. Needs a Book*, which is the book you want to checkout
*/
void
BookTree::checkout(Book* value)
{
	BookNode *ptr = new BookNode(value);//Build a node out of this value
	BookNode *myBook = findBook(ptr);//try to find this in the tree
	if(!myBook)//if not found, let the user know
	{
		cout<<"Book not found"<<endl;
		return;
	}
	if(myBook->value()->available())// if the book was found and is available
	{// go ahead and rent it 
		myBook->value()->rent();
		myBook->value()->upRented();
		cout<<"****"<<endl;
		cout<<"**Successfully checked out."<<endl;//let the user know it worked
		cout<<"****"<<endl;
	}
}
/*
	Method used to return a book. Needs a Book*, which is the book you want to return
*/
void
BookTree::returnBook(Book* value)
{	
	BookNode *ptr = new BookNode(value);//Build a node out of this value
	BookNode *myBook = findBook(ptr);//try to find this in the tree
	if(!myBook)//if not found, let the user know
	{
		cout<<"Book not found"<<endl;
		return;
	}
	if(!myBook->value()->available())// if the book was found and it is not available
		myBook->value()->retur();//return the book 
}
/*
	Method used to print a whole tree recursively in ascending lexicograpycally order.
	Needs a BookNode pointer as a parameter, which will tell where to begin the recursion
*/
void 
BookTree::inOrderPrint(BookNode *subtree) const
{
	if(_root!=NULL)//if my tree is not empty	
	{
		if(subtree->left() !=NULL)// can i go to the left?
			inOrderPrint(subtree->left());//solve the problem from there
		cout<< subtree->contents();//when i get here for the first time i will be the smallest one
		//and from there it will be in order because of the recursion
		if(subtree->right()!=NULL)//can i go to the right?
			inOrderPrint(subtree->right());//solve the problem from there
	}
	else
		cout<<"The three is empty"<<endl;

}
/*
	This method will simply call the inOrderPrint method, and tell it to start from the root. 
	In addition it will print a line in the beggining and a line in the end.
	It needs a ostream parameter, which will tell where to print, and it will return one as well.
*/
ostream& 
BookTree::print(ostream &os) const
{
	os << "====================================================================" <<endl;
	inOrderPrint(_root);
	os << "====================================================================" << endl;
	return os;
}
	



