#include "StringSet.h"
#include <iostream>

using namespace std;

/*
	Constructor used to initialize the instance varibles
	
	_data to a array of size defined in the .h file
	_userChoice to 10, since the user didnt choose anything
	_currSize to 0, since the array is currently empty
*/
StringSet::StringSet()
{
	_data = new string[MAX_SIZE];
	_userChoice = 10;
	_currSize = 0;
}
/*
	Constructor used to initialize the instance varibles
	Take one parameter (maxSize), which will the the size that the user will choose
	
	_data to a array of size defined by the parameter
	_userChoice to the size defined by the user
	_currSize to 0, since the array is currently empty
*/
StringSet::StringSet(int maxSize)
{
	_data = new string[maxSize];
	_userChoice = maxSize;
	_currSize = 0;
}
/*
	Method used to simply empty the whole array,
	setting the _currSize to 0
*/
void
StringSet::clear()
{
	
	_currSize = 0;
}
/*
	Method used to find out how big the array is at this moment
	
	Returns an int that represents the size
*/
int
StringSet::size() const
{
	return _currSize;
}
/*
	Method used to double the size of the array in case it is needed.
	
	As we cannot change the size of an array, create a new array and 
	change the pointer of the old array to this new array. Make sure to copy 
	everysingle data inside of the old array to the new array.
*/
void
StringSet::resize()
{	
	string *safer = new string[_userChoice*2];
	for(int index=0; index<_currSize;index++)
	{
		safer[index]=_data[index];
	}
	_userChoice=_userChoice*2;
	_data = safer;
}
/*
	Overloading operator[] used to return the value inside a cell of the array, it 
	returns the value selected by the user, which was passed in the 
	parameter.
*/
string &
StringSet::operator[](int index) const
{
	return _data[index];
}
/*
	Overloading operator+= that will be used in order to add data
	to the array.
	Checks to see if the array is capable of holding the new element,
	if not, make it bigger.
	If the array is capable of holding it, add and update the _currSize.
	
*/
void
StringSet::operator+=(const string value)
{
	if(_currSize>=_userChoice)
	{
		resize();
		_data[_currSize]=value;
	}
	if(_currSize==0)
	{
		_data[_currSize]=value;
		_currSize++;
	}
	else
	{
		_data[_currSize] = value;
		_currSize++;
	}
}
/*
	Method used to check if the element in the parameter is in the
	array or not.
	return true if it is
	return false if it isnt 
*/
bool
StringSet::contains(std::string value) const
{
	for(int index=0; index < _currSize; index++)
	{
		if(_data[index] == value)
		{
			return true;
		}
	}
	return false;
}
/*
	Overloading the operator<< it will simply call another method, 
	which is print
*/
ostream& operator<<(ostream &os, const StringSet &myStringSet)
{
	return myStringSet.print(os);
}
/*
	Method used to print the array in the screen, it will print the array
	starting with "{", then each element will be separated by a "," and 
	end the array with "}"
*/
ostream& 
StringSet::print(ostream &os) const
{
	os<<"{";
	for(int index=0; index<_currSize; index++)
	{
		if(index != _currSize-1)
		{
			os << _data[index] << ",";
		}
		else
			os << _data[index];
	}
	os<<"}"<<endl;
	return os;
	
}
/*
	Method used to update the LHS to what the RHS is at this moment.
	It will not refer to the same object, it will simply be a copy of it.
*/
StringSet&
StringSet::operator=(const StringSet &myStringSet)
{	
	string *newSet = new string[myStringSet.size()];
	for(int index=0; index<myStringSet.size();index++)
	{
		newSet[index]=myStringSet[index];
	}
	_currSize=myStringSet.size();
	_data = newSet;
	return *this;
}
/*
	Method used to delete an element from the array, it will delete,
	if present, the string passed as the parameter.
*/
void
StringSet::operator-=(const string value)
{
	for(int index=0; index<_currSize; index++)
	{
		if(_data[index] == value)
		{
			for(int index2 = index; index2<_currSize-1; index2++)
				_data[index2] = _data[index2+1];
			_currSize--;
		}
	}
}
/*
	Overloading the operator-, it will calculate the difference between
	the set on the LHS and the set on the RHS and return the result.
*/

StringSet 
StringSet::operator-(StringSet &myStringSet) const
{
	StringSet newSet;
	bool checker=false;
	for(int index=0;index<_currSize;index++)
	{
		for(int index2=0;index2<myStringSet.size();index2++)
		{	
			if(_data[index]==myStringSet[index2])
				checker=true;
		}
		if(!checker)
			newSet+=_data[index];
		checker=false;
	}
	return newSet;
}
/*
	Overloading the operator/, it will calculate the intersection between
	the set on the LHS and the set on the RHS and return the result
*/
StringSet 
StringSet::operator/(StringSet &myStringSet) const
{
	StringSet newSet;
	for(int index=0; index<_currSize;index++)
	{	
		for(int index2=0;index2<myStringSet.size();index2++)
		{
			if(_data[index]==myStringSet[index2])
				newSet+=_data[index];
		}
	}
	return newSet;
}
/*
	Overloading the operator+, it will calculate the union between
	the set on the LHS and the set on the RHS and return the result
*/
StringSet 
StringSet::operator+(StringSet &myStringSet) const
{
	StringSet newSet(_currSize+myStringSet.size());
	for(int index=0;index<_currSize;index++)
	{
		newSet+=_data[index];
	}
	for(int index=0;index<myStringSet.size();index++)
	{
		newSet+=myStringSet[index];
	}
	
	return newSet;
}
/*
	Overloading the operator==, it will compare the string set in the LHS
	and the set in the RHS.
	It will return true if they are equivalent, and false otherwise
*/
bool
StringSet::operator==(const StringSet &myStringSet)
{	
	bool checker=false;
	if(_currSize!=myStringSet.size())
		return false;
	for(int index=0;index<_currSize;index++)
	{
		for(int index1=0;index<_currSize;index++)
		{
			if(_data[index]==myStringSet[index1])
				checker = true;
		}
		if(!checker)
			return false;
		else
			checker = false;
	}
	return true;
}



