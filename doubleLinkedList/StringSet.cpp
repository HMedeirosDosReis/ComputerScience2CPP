#include "StringSet.h"
#include <iostream>

using namespace std;

/*
	Constructor used to initialize the instance varibles, as the String set is empty 
	at this moment, the size will be 0 and both _head and _tail will hold no values
	
	bigO(1)
*/
StringSet::StringSet()
{
	_head = NULL;
	_tail = NULL;
	_currSize=0;
}
/*
	Method used to simply empty list,
	setting the _currSize to 0, _head and _tail to NULL
	
	bigO(1)
*/
void
StringSet::clear()
{
	_head = NULL;
	_tail = NULL;
	_currSize = 0;
}
/*
	Method used to find out how big the list is at this moment
	
	Returns an int that represents the size
	
	bigO(1)
*/
int
StringSet::size() const
{
	return _currSize;
}
/*
	Overloading operator+= that will be used in order to add data
	to the end of the list, in this case it will simply call the 
	addTo method.
	
	bigO(1)
*/
void
StringSet::operator+=(const string value)
{
	addTo(value);
}
/*
	Method used to check if the element in the parameter is in the
	list or not.
	
	return true if it is
	return false if it isnt 
	
	bigO(n), where n is the size of the list
*/
bool
StringSet::contains(std::string value) const
{
	DLNode *curr = _head;
	//if curr is null, we arrived to the end of the list
	// because _tail->next() will always be null
	while(curr!=NULL)
	{
		if(curr->value() == value)
		{
			return true;
		}
		curr = curr -> next();
	}
	//if I am here, I didnt find what I wanted
	return false;
}
/*
	Overloading the operator<< it will simply call another method, 
	which is print
	
	bigO(1)
*/
ostream& operator<<(ostream &os, const StringSet &myStringSet)
{
	return myStringSet.print(os);
}
/*
	Method used to print the list in the screen, it will print the list
	starting with ", then each element will be separated by a "," and 
	end the array with "
	
	bigO(n), where n will be the size of the list
*/
ostream& 
StringSet::print(ostream &os) const
{
	DLNode* currPtr = _head;//starts at the head
	os<<"\"";
	for(int index=0; index<_currSize; index++)//keep going until reaching the end
	{
		if(index != _currSize-1)
		{
			os << currPtr->value() << ",";
			currPtr = currPtr->next();
		}
		else
			os << currPtr->value();
	}
	os<<"\""<<endl;
	return os;	
}
/*
	Method used to update the LHS to what the RHS is at this moment.
	It will not refer to the same object, it will simply be a copy of it.
	
	bigO(n), where n will be the size of the RHS list
*/
StringSet
StringSet::operator=(const StringSet &myStringSet)
{	
	DLNode* ptr=myStringSet._head;
	while(ptr!=NULL)
	{
		this->addTo(ptr->value());
		ptr=ptr->next();
	}
	return *this;
}
/*
	Method that will be used  to add data to the end of the list,
	needed to be created in order to make possible the use of the
	operator=
	
	bigO(n), where n will be the size of the list
	in this case it will only be bigO(n) because of the contains 
	method, besides it, it would be bigO(linear)
*/
void
StringSet::addTo(const string value)
{
	if(!contains(value))
	{
		DLNode *nodeToAdd = new DLNode(value);

		if (_head==NULL) // list is empty
		{
			_head = nodeToAdd;
			_tail = _head;
			_currSize++;
			return;
		}
		nodeToAdd->next() = _tail->next();
	  	nodeToAdd->prev() = _tail;
	  	_tail->next() = nodeToAdd;
	  	_tail = nodeToAdd;
		_currSize++;
	}
}
/*
	Method used to delete an element from the list, it will delete,
	if present, the string passed as the parameter. in this case, it will
	only call a method that will delete the node
	
	bigO(n), where n will be the size of the list
	Also, it is only bigO of n because of the contains method
*/

void
StringSet::operator-=(const string value)
{
	if(contains(value))
	{
		DLNode *toDelete = find(value);
		remove(toDelete);
		_currSize--;
	}
}
/*
	Method that actually deletes the node from the list
	
	bigO(linear)
*/
void
StringSet::remove(DLNode *ptr)
{
	//is it the only item in the list? 
	if(_currSize==1)//yes? set head and tail to NULL and done
	{
		
		_head=NULL;
		_tail=NULL;
		return;
	}
	//I am not the only item in the list
	// create two nodes that will help to manage the deletion
	DLNode *prev = ptr->prev();
	DLNode *next = ptr->next();
	//if my previous is NULL, I am the head
	if(prev==NULL)
	{
		next->prev()=NULL;//the previous of head must always be NULL
		_head = next;//now the head is the next node
	}
	//I am not the head, I need to actualize my previous
	else
	{
		prev->next() = next;
		ptr = prev;
	}
	//if my next is NULL, i am the tail
	if(next ==NULL)
	{
		prev->next()=NULL;//what comes before me will be the tail, so its next must be NULL
		_tail=prev;//the tail is what comes before me
	}
	//i am in the middle of the list
	/*else
	{
		next->prev() = prev; //what comes after me needs to point to what comes before me
		ptr=next;
	}*/
	if(prev==NULL && next==NULL)//is the list empty now?
	{
		return;
	}
	else if(prev!=NULL && next !=NULL)// no, and I am in the middle of the list
	{
		prev->next() = next;//what comes before me needs to point to what comes after me
		next->prev() = prev;//what comes after me needs to point to what comes before me
		ptr=next;//now I will just be the next one
	}

}
/*
	Method used to the pointer to the value, so it can be treated as a node,
	not as a string
	
	bigO(n), where n will be the size of the list
*/
DLNode* 
StringSet::find(string value) const
{
	DLNode *curr = _head;

	while(curr!=NULL && curr->value()!=value)
	{
		curr = curr -> next();
	}

	return curr;
}
/*
	Overloading the operator==, it will compare the string set in the LHS
	and the set in the RHS.
	It will return true if they are equivalent, and false otherwise
	
	bigO(n^2), where n will be the size of the lists,
	however, if they are not of the same size, it is only bigO(linear)
*/
bool
StringSet::operator==(const StringSet &myStringSet)
{	
	DLNode* curr=_head;
	bool checker=false;
	if(_currSize!=myStringSet.size())
		return false;
	while(curr!=NULL)
	{	
		DLNode* curr2=myStringSet._head;
		while(curr2!=NULL)
		{
			if(curr->value()==curr2->value())
			{
				checker = true;
				curr2=curr2->next();
			}
			else
				curr2=curr2->next();
		}
		if(!checker)
			return false;
		else
			checker = false;
		curr=curr->next();
	}
	return true;
}
/*
	Overloading the operator+, it will calculate the union between
	the set on the LHS and the set on the RHS and return the result
	
	bigO(n), in this case it would be bigO(2n), which is only bigO(n)
	and the n will be the size of each list
*/
StringSet 
StringSet::operator+(StringSet &myStringSet) const
{
	StringSet newSet;
	DLNode* curr= _head;
	while(curr!=NULL)
	{
		newSet+=curr->value();
		curr=curr->next();
	}
	DLNode* curr2=myStringSet._head;
	while(curr2!=NULL)
	{
		newSet+=curr2->value();
		curr2=curr2->next();
	}
	
	return newSet;
}
/*
	Overloading the operator/, it will calculate the intersection between
	the set on the LHS and the set on the RHS and return the result
	
	bigO(n^2), where n will be the size of the lists
*/
StringSet 
StringSet::operator/(StringSet &myStringSet) const
{
	StringSet newSet;
	DLNode* curr=_head;
	while(curr!=NULL)
	{
		DLNode* curr2 = myStringSet._head;
		while(curr2!=NULL)
		{
			if(curr2->value()==curr->value())
				newSet+=curr->value();
			curr2=curr2->next();
		}
		curr=curr->next();
	}
	return newSet;
}
/*
	Overloading the operator-, it will calculate the difference between
	the set on the LHS and the set on the RHS and return the result.
	
	bigO(n^2), where n will be the size of the RHS list, and the number of times
	contains take
*/
StringSet 
StringSet::operator-(StringSet &myStringSet) const
{
	StringSet newSet;
	bool checker=false;
	DLNode* curr=myStringSet._head;
	while(curr!=NULL)
	{
		if(!contains(curr->value()))
			newSet+=curr->value();
		curr=curr->next();
	}
	return newSet;
}
