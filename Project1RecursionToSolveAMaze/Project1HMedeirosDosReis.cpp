#include <iostream>
#include <fstream>
using namespace std;
#define MAX_DIM 200

char myBoard[MAX_DIM][MAX_DIM];
int rows, columns, endR, endC, startR, startC;
ifstream fileReader; //creates the object that can open the file

void printBoard()
{	
	for(int row=0; row<rows; row++)
	{
		for(int col=0; col<columns; col++)
		{
			cout << myBoard[row][col];
		}
		cout << endl;
	}
}

void initBoard()
{

	for(int row=0; row<rows; row++)	
	{
		for(int col=0; col<columns; col++)
		{
			fileReader >> myBoard[row][col];
		}	
	}
}

bool solveBoard(int fromR, int fromC)
{
	myBoard[fromR][fromC]= '*';
	//check to see if the location is a part of the maze
	if(fromR>=rows || fromC>=columns || fromR <0 || fromC <0)
		myBoard[fromR][fromC] = 'B';//not ready
	/*if(myBoard[fromR][fromC + 1] != '+')
	{
		myBoard[fromR][fromC+1] = 'B';
		solveBoard(fromR, fromC);
	}*/

	//check to see if the location is a potential part of the solution
	if(myBoard[fromR][fromC + 1] == '+')
		solveBoard(fromR, fromC + 1);
	else if(myBoard[fromR][fromC -1] == '+')
		solveBoard(fromR, fromC - 1);
	else if(myBoard[fromR +1][fromC] == '+')
		solveBoard(fromR +1, fromC);
	else if(myBoard[fromR-1][fromC] == '+')
		solveBoard(fromR-1, fromC);
	
	
	/*//if we are off edge of board, it worked!
	if(startR == endR && startC == endC)
		return true;
	//try each row of the current column, and see if it works
	for(int row = 0; row < size; row++)
	{
		//can we place a queen at row, col based on all queens
		// already in previous columns
		if(canPlace(row, fromCol))
		{
			//place a queen at that row, col position
			theBoard[row][fromCol] = 'Q';
			//solve the rest of the board
			if (solveBoard(fromCol+1))
				return true;
			//if we get here, solving with the current position
			// didnt work
			theBoard[row][fromCol] = ' ';
		}
	}
	
	//tried all rows in current column, and none worked...*/
	return false;
}

bool solveBoard()
{
	if(startR == endR && startC == endC)
		return true;
	return solveBoard(startR, startC);
}

int main()
{
	
	string fileName; //holds the name of the file in a string
	
	cout << "Please enter the name of the file: "; 
	cin >> fileName; //store the name in the variable
	
	fileReader.open(fileName); //open the file	
	if (!fileReader) //make sure that the file exists before running the program
	{
		cerr << "Invalid input file!" << fileName << endl;
		return 1;
	}
	
	
	fileReader >> rows;
	fileReader >> columns;
	fileReader >> startR;
	fileReader >> startC;
	fileReader >> endR;
	fileReader >> endC;
	cout << endl;

	initBoard();
	printBoard();
	cout << endl;cout << endl;
	
	solveBoard();
	cout << "The solved version is: "  << endl;
	printBoard();
	
	
	fileReader.close();

	return 0;
}
