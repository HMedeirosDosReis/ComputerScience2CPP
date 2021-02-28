#ifndef _STRING_SET_
#define _STRING_SET_

#include "DLNode.h"
#include <iostream>

class StringSet
{
private:
	DLNode* _head;
	DLNode* _tail;
	int _currSize;
public:
	StringSet();
	
	void clear();
	int size() const;
	bool contains(std::string value) const;
	
	DLNode* operator[](int index) const;
	bool operator==(const StringSet &myStringSet);
	StringSet operator+(StringSet &myStringSet) const;
	StringSet operator/(StringSet &myStringSet) const;
	StringSet operator-(StringSet &myStringSet) const;
	void operator+=(const std::string value);
	void operator-=(const std::string value);
	DLNode* find(std::string value) const;
	void remove(DLNode *ptr);
	StringSet operator=(const StringSet &myStringSet);
	void addTo(const std::string value);
	
	std::ostream& print(std::ostream &os) const;
	friend std::ostream& operator<<(std::ostream &os, const StringSet &myStringSet);
	
};

#endif
