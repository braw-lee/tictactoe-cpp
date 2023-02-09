#ifndef HANDLER_H
#define HANDLER_H

#include "board.h"
#include <iostream>
using namespace std;

class Handler
{
public:
	Handler();
	void setUpBoard();
	void runGame();
	int inputBoardSize();  //takes boardSize as input and returns it
	int inputConsecutiveMarker();
	void inputFromPlayer();  //takes input from current player
	void changePlayer();  //turn switch to another player
	void displayWinner();  //prints result
private:
	int _currentPlayer;  //can be either X_MARK or O_MARK
	int _boardSize;
	Board _board;
};

#endif
