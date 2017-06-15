#ifndef BOARD_H
#define BOARD_H
using namespace std;

class Board
{
public:
	Board();
	//These functions are not called by main function; but are called by
	//Player class and since we did not declare friend class we should make
	//these functions public.
	bool putPiece(char c, int x1, int y1);
	bool movePiece(int x1, int y1, int x2, int y2);
	char gameOver();
	void displayBoard() const;

	char gettingchar(int x, int y);  // helper function

private:
	char myBoard[4][4];
};
#endif
