#include "Player.h"
#include "Board.h"
#include<iostream>

using namespace std;


bool Player::put (int x1, int y1)
{
	return board.putPiece(this->playerChar, x1, y1);
}

bool Player::move (int x1, int y1, int x2, int y2)
{
	if (board.gettingchar(x1, y1) == '-')  // checks cell is empty
	{
		cout<<"The source cell is empty! Try again!"<<endl;
		return false;
	}

	if (board.gettingchar(x1, y1) != playerChar)  // checks the chosen element belongs to that player
	{
		cout<<"The game piece at source coordinates isn't yours! Try again!"<<endl;
		return false;
	}

		return board.movePiece (x1, y1, x2, y2);
}

bool Player::isWinner ()
{
	if (board.gameOver() == playerChar)
	return true;

	return false;
}

char Player::getSymbol()
{
	return playerChar;
}
