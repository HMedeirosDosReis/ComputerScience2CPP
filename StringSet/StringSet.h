#ifndef _STRING_SET_
#define _STRING_SET_

#include <iostream>
#include <string>

#define MAX_SIZE 10
class StringSet
{
private:
	std::string *_data;
	int _currSize;
	int _userChoice;
public:
	StringSet();
	StringSet(int setSize);
	
	void clear();
	int size() const;
	void resize();
	bool contains(std::string value) const;
	
	std::string &operator[](int index) const;
	bool operator==(const StringSet &myStringSet);
	StringSet operator+(StringSet &myStringSet) const;
	StringSet operator/(StringSet &myStringSet) const;
	StringSet operator-(StringSet &myStringSet) const;
	void operator+=(const std::string value);
	void operator-=(const std::string value);
	StringSet& operator=(const StringSet &myStringSet);
	
	std::ostream& print(std::ostream &os) const;
	friend std::ostream& operator<<(std::ostream &os, const StringSet &myStringSet);
	
};

#endif
