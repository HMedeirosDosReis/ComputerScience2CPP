#ifndef _DLNODE_H_
#define _DLNODE_H_

#include <iostream>

class DLNode
{
private:
	std::string _value;
	DLNode *_next;
	DLNode *_prev;
public:
	DLNode(std::string initVal);

	std::string& value();
	DLNode* &  next();
	DLNode* &  prev();

	std::ostream& print(std::ostream &os) const;
	friend std::ostream& operator<< (std::ostream &os, const DLNode &node);
};


#endif
