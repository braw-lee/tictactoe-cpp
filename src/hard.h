#ifndef HARD_H
#define HARD_H

#include "board.h"

struct Move
{
	/*
	We initialize x and y as invalid cordinate because we set x and y
	ourselves and use the result value only when the function is called
	*/
	int x{-1};  //x cordinate on board
	int y{-1};  //y cordinate
	int result;  //resulting score of the move
};

class Hard
{
public:
	void setMarker(int hardPlayer);

	//gets best move for 'current player' i.e hardPlayer or humanPlayer
	Move getHardMove(Board& board, int currentPlayer);
	void playHardMove(Board& board);
private:
	int _hardPlayer;
	int _hardPlayerWon;  //to compare result of checkWin()

	int _humanPlayer;
	int _humanPlayerWon;
};

#endif
