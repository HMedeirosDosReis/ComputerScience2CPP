#include "Book.h"
#include "BookNode.h"
#include "BookTree.h" 
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	BookTree myTree;//constructs a tree that will be a data structure for this project
	string option;//creates a string variable that will be used to hold the user choice
	while(option!="q")//check if the user wants to quit the program
	{	
		if(option=="Q")//checks again to see if he entered a uppercase 
			return 0;
		//prints out a menu that will tell the options for the user
		cout<<"Select One of:"<<endl;
		cout<<"  (L)oad books from text file"<<endl;
		cout<<"  (P)rint entire library"<<endl;
		cout<<"  add a (N)ew book to the library"<<endl;
		cout<<"  (D)elete a book from the library"<<endl;
		cout<<"  (S)earch for a book with full key data"<<endl;
		cout<<"  (M)aximum search depth"<<endl;
		cout<<"  search for a book by (T)itle"<<endl;
		cout<<"  search for a book by (A)uthor"<<endl;
		cout<<"  (C)heckout a book"<<endl;
		cout<<"  (R)eturn a book"<<endl;
		cout<<"  (Q)uit"<<endl;
		cout<<"Enter choice: ";
		cin >> option;
		string blankspace;
		getline(cin, blankspace);
		
		if(option=="L" || option=="l")//if the user chose l or L
		{
			//read an file and create a tree based on the file
			ifstream fileReader;
			string fileName; //holds the name of the file in a string
	
			cout << "Please enter the name of the file: "; //print in the screen the message
			cin >> fileName; //store the name in the variable

			fileReader.open(fileName); //open the file	
			if (!fileReader) //make sure that the file exists before running the program
			{
				cerr << "Invalid input file!" << fileName << endl;
				return 1;
			}
			while (fileReader)//while there is stuff left in the file, keep going
			{
				string title, author,year;
				getline(fileReader, title);
				getline(fileReader, author);
				getline(fileReader, year);

				Book *newBook = new Book(title, author, year);//create a book out of those 3 strings
				BookNode *ptrBook = new BookNode(newBook);//create the node out of the book 
				myTree.addBook(ptrBook);//and finally add this node to the tree
			}
		}
		else if(option=="P" || option=="p")//if the user chose p or P
			cout<<myTree<<endl;//print the whole tree
		else if(option=="N" || option=="n")//if the user chose n or N
		{
			//get the information for creating a book out of the keyboard
			string title, author,year;
			cout<<"Enter title: ";
			getline(cin, title);
			cout<<"Enter author: ";
			getline(cin, author);
			cout<<"Enter year: ";
			getline(cin, year);

			Book *newBook = new Book(title, author, year);//create a book out of those informations
			BookNode *ptrBook = new BookNode(newBook);//create a node out of the book
			myTree.addBook(ptrBook);//and finally add this node to the tree
			
		}
		else if(option=="D" || option=="d")//if the use chose D or d
		{
			//get the information of the book that the user wants to delete out of the keyboard
			string title, author,year;
			cout<<"Enter title: ";
			getline(cin, title);
			cout<<"Enter author: ";
			getline(cin, author);
			cout<<"Enter year: ";
			getline(cin, year);

			Book *delBook = new Book(title, author, year);//create a book out of it
			BookNode* ptrBook = new BookNode(delBook);// create a node out of the book
			myTree.eraseBook(ptrBook);//and finally, delete the node with the same information from the tree
		}
		else if(option=="S" || option=="s")//id the user chose s or S
		{	
			//get the full information of the book that the user wants to find from the keybord
			string title, author,year;
			cout<<"Enter title: ";
			getline(cin, title);
			cout<<"Enter author: ";
			getline(cin, author);
			cout<<"Enter year: ";
			getline(cin, year);

			Book *searchingBook = new Book(title, author, year);//create a book out of it
			BookNode *ptrBook = new BookNode(searchingBook);// create a node out of the book
			BookNode* myBook = myTree.findBook(ptrBook);//try to find that book in the tree
			if(myBook!=NULL)//if the book is found
			{
				myBook->value()->upSearches();// increase the number of times the book was searched
				myBook->value()->printWholeBook(cout);//and show the information to the user
			}
			else
				cout<<"Book not found"<<endl;//tell the user it is not in tree, otherwise
		}
		else if(option=="M" || option=="m")//if the user chose m or M
			cout<< "Most Books to look up with full information: "<<
			myTree.findMaxBooks(myTree.root())<<endl;//tell the user how many steps will be needed
		else if(option=="T" || option=="t")//if the user chose t or T
		{
			string title;
			cout<<"Enter title: ";
			getline(cin, title);//get the title information out of the keybord
			myTree.findTitle(title);//find all books with the same title in the tree
		}
		else if(option=="A" || option=="a")//if the user chose A or a
		{
			string author;
			cout<<"Enter title: ";
			getline(cin, author);//get the author information out of the keybord
			myTree.findAuthor(author);//find all books with the same author in the tree
		}
		else if(option=="C" || option=="c")//if the user chose c or C
		{
			//get the full information of the book that the user wants to find from the keybord
			string title, author,year;
			cout<<"Enter title: ";
			getline(cin, title);
			cout<<"Enter author: ";
			getline(cin, author);
			cout<<"Enter year: ";
			getline(cin, year);
			Book *checkoutBook = new Book(title, author, year);//create a book out of that information 
			myTree.checkout(checkoutBook);//checkout the book
			//there is no need to check if the book exists, because the method will already do it
		}
		else if(option=="R" || option=="r")// if the user chose r or R
		{
			//get the full information of the book that the user wants to find from the keybord
			string title, author,year;
			cout<<"Enter title: ";
			getline(cin, title);
			cout<<"Enter author: ";
			getline(cin, author);
			cout<<"Enter year: ";
			getline(cin, year);
			Book *returnB = new Book(title, author, year);//create a book out of that information 
			myTree.returnBook(returnB);//return the book
			//there is no need to check if the book exists, because the method will already do it
		}
		else if(option=="Q" || option=="q")//if the user chose Q or q
			return 0;//quit the program
		else
			cout<<"Incorrect Entry! Try again!"<<endl;//if the user chose anything that was not an option
			//let the user know
		option="";//reset the option variable
	}

	return 0;
}
