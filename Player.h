#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include<iostream>
using namespace std;

class Player
{
	public:
		Player();
		Player::Player(char c, Board &myboard)
		:playerChar(c) , board(myboard)
		{ }

		bool put (int x1, int y1);
		bool move (int x1, int y1, int x2, int y2);
		bool isWinner ();
		char getSymbol();


	private:
		//Referenced variable (shared object between two players)
		Board &board;
		char playerChar;
};

#endif
