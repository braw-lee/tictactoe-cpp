#ifndef HANDLER_H
#define HANDLER_H

#include "board.h"
#include <iostream>
using namespace std;

class Handler
{
public:
	void runGame();
	void inputFromPlayer();  //takes input from current player
	void changePlayer();  //turn switch to another player
	void displayWinner();  //prints result
private:
	int _currentPlayer;  //can be either X_MARK or O_MARK
	Board _board{5};
};

#endif
