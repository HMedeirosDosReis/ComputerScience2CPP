#include "Book.h"

#include <iostream>
using namespace std;

/*
	This method is used in order to print the whole information of a book.
	It will simply print the information and check if the book is available 
*/
ostream& 
Book::printWholeBook(ostream &os) const
{	
	os<<"========================================"<<endl;
	os << "Title: "<<_title<<endl;
	os << "Author: "<<_author<<endl;
	os << "Year: "<<_year<<endl;
	if(_available)
		os<<"Available"<<endl;
	else
		os<<"NOT Available"<<endl;
	os << "Searches: " <<_searched<<endl;
	os << "Checkouts: " <<_rentedTimes<<endl;
	os<<"========================================"<<endl;
	return os;	
}
/*
	Also used to print a book, but not with full information, only the ones that
	were used in the constructor
*/
ostream& operator<<(ostream &os, const Book &book)
{
	os << book._title<< "||"<< book._author<<"("<<book._year<<")"<<endl;
	return os;
}
/*
	Method used to compare which book will be smaller than the other.
	A book will be smaller if 
	1st the title is lexicographically smaller than the other
	2nd the author is lexicographically smaller than the other
	3rd the year is the last step, and follow the same path
*/
bool
Book::operator<(const Book &myBook) const
{
	//check the title of the book, is it bigger os smaller?
	if(_title < myBook._title)
		return true;
	if(_title > myBook._title)
		return false;
	//if I get here, the title must be equal
	if(_author < myBook._author)
		return true;
	if(_author > myBook._author)
		return false;
	//if I get here, the author and the title are equal
	if(_year < myBook._year)
		return true;
	//finally, if my year is bigger at this point, the whole book is bigger
	return false;
}
/*
	Method used to check if a book is exactly the same as the other one.
	1st compare the title
	2nd compare the author
	3rd compare the year
*/
bool
Book::operator==(const Book &myBook) const
{
	if(_title!=myBook._title)
		return false;//if the title isnt equal, the book inst equal
	if(_author!=myBook._author)
		return false;//if the author isnt equal, the book inst equal
	if(_year!=myBook._year)
		return false;//if the year isnt equal, the book inst equal
	return true;//if I get here, the books are equal
}
