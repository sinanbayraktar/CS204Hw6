#include "Board.h"
#include <iostream>

using namespace std;


Board::Board() // default constructor
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			myBoard[i][j] = '-';
		}
	}
}

void Board::displayBoard()const // dislpays the matrix 
{
	cout << "Board: " << endl;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout << myBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


bool Board::putPiece(char c, int x1, int y1)  // putting a piece into board
{
	if(myBoard[x1][y1] == '-')  // cell is empty
	{
		myBoard[x1][y1] = c;  // putting the char of the player
		return true;
	}
	cout<<"Cell isn't empty! Choose a different one."<<endl;  // FULL
	return false;
}

bool Board::movePiece(int x1, int y1, int x2, int y2)  // after putting the 3 pieces, changing place funtion
{
	if(myBoard[x2][y2] != '-')  // cell is not empty
	{
		cout<<"Cell isn't empty! Choose a different one."<<endl;  // FULL
		return false;
	}

	if (abs(x1-x2) > 1 || abs(y1-y2) > 1 || (abs(x1-x2) == 1 && abs(y1-y2) == 1))
	{
		cout<<"Source and destination cells are not adjacent! Try again!"<<endl;  // move is not to adjacent cell
		return false;
	}
	myBoard[x2][y2] = gettingchar(x1, y1);  // swapping the elements
    myBoard[x1][y1] = '-';
	return true;
}

char Board::gameOver() // checks is there a winner and returns its symbol
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (myBoard[i][j] == myBoard[i][j+1] && myBoard[i][j+1] == myBoard[i][j+2] && myBoard[i][j] != '-')
				return myBoard[i][j];
		}
	}

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (myBoard[i][j] == myBoard[i+1][j] && myBoard[i+1][j] == myBoard[i+2][j] && myBoard[i][j] != '-')
				return myBoard[i][j];
		}
	}
	return '-';
}

char Board::gettingchar(int x, int y)  // helper funtion to access the symbol of a given element in the board
{
	return myBoard [x][y];
}
