#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>

class Book
{
private:
	std::string _title; // instance variable that will hold the title of this particular book
	std::string _author;// instance variable that will hold the author of this particular book
	std::string _year;// instance variable that will hold the year of release of this particular book
	bool _available;//instance variable that will tell if the book is available of this particular book
	int _searched;// instance variable that will hold how many times this book was searched
	int _rentedTimes;// instance variable that will hold how many times this book was rented
public:
//constructor that will only initiate a book, it is not going to do anything, it is only to avoid errors in the main program
	Book() {} 
	/* Constructor for a book, needs three parameters, a string for title, a string for author and a string for the year of release.
		Also, intialize _available to true, _searched and _rented times to 0. Since this is a new book
	*/
	Book(std::string title, std::string author, std::string year)
	{_title=title; _author=author; _year=year; _available=true; _searched=0; _rentedTimes=0;}
	
	std::string title() const {return _title;} // this method will simply return the title of the book
	std::string author() const {return _author;}// this method will simply return the author of the book
	std::string year() const {return _year;}// this method will simply return the year of release of the book
	
	/* this method will simply return the wheter the book is available or not*/
	bool available() const {return _available;}
	/* this method will simply return the number of times the book was searched*/
	int searched() const {return _searched;}
	/* this method will simply return the number of times the book was rented*/
	int rentedTimes() const{return _rentedTimes;}
	
	void rent() {_available = false;}//this method change the _available variable to false, the act of renting
	void retur(){_available = true;}//this method change the _available variable to true, the act of returning
	
	void upSearches() {_searched++;}// this method will increase the number of times a book was searched
	void upRented() {_rentedTimes++;}// this method will increase the number of times a book was rented
	
	//method used to check which book is bigger than the other, further explanations in the Book.cpp
	bool operator<(const Book &myBook) const; 
	//method used to check if the books are equal, further explanations in the Book.cpp
	bool operator==(const Book &myBook) const;
	
	//These two methods are used to print a book, but they will print them in different ways
	std::ostream& printWholeBook(std::ostream &os) const;
	friend std::ostream& operator<<(std::ostream &os, const Book &book);
};


#endif
