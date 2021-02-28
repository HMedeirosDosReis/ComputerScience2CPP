#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <list>
#include <iostream>
//header file for the templated HashTable class
template <class T>
class HashTable
{
private:
	int _N; //instance variable _N that will hold the maximum size of the array from the table
	int _n; //instance variable _n that will hold the current number of elements in the table 
	typename std::list<T> *_table;//instance variable for a pointer that will point to an array of lists of the
	//type that the templated class will be
public:
	/*
		Constructor for the HashTable class. Needs an integer as a parameter, which will be the maximum size of
		the array of lists. It will set the _N variable to the size declared by the user, _n to 0, since there 
		is no elements in the list at this moment, and initialiaze the pointer to points to an array of lists
	*/
	HashTable(int N){_N=N; _n=0; _table = new std::list<T>[N];
	//initialize every element in the array to an empty list 
	for(int i =0; i<N;i++) _table[i]=std::list<T>();     }
	
	T* insert(T &newValue);//Method used to add an element to the table, 
						   //it will return a pointer to the item inserted
	bool remove(T &value);//Method used to remove an element from the table, 
						 //it will return true if removed, and false otherwise
	T* find(T &value) const;//method used to find an element in the table, if not found, return NULL.
							// If found return the element
	
	int isEmpty() const;//Method used to check how many indices are empty in the array
	int maxChain() const;//Method used to check the maximum number of collisions handed in the table
	int compress(int value) const;//method used to compress an integer that will come from the hash function
								  // into an integer in the range of the array size
	
	std::ostream& print(std::ostream& os) const;//method used to print the table
	
};



#endif
