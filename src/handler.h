#ifndef HANDLER_H
#define HANDLER_H

#include "easy.h"
#include "board.h"
#include <iostream>
using namespace std;

enum class GameMode
{
	twoPlayer,
	singlePlayerEasy,
	singlePlayerHard,
};

class Handler
{
public:
	Handler();
	
	void inputGameMode();
	void setUpBoard();
	void runGame();
	void runTwoPlayerGame();
	void runSinglePlayerEasyGame();
	int inputBoardSize();  //takes boardSize as input and returns it
	int inputConsecutiveMarker();
	void inputFromPlayer();  //takes input from current player
	void changePlayer();  //turn switch to another player
	void displayWinner();  //prints result
private:
	int _currentPlayer;  //can be either X_MARK or O_MARK
	int _boardSize;
	Board _board;
	GameMode _mode;
	int _humanPlayer;  //denotes marker of human player
	int _easyPlayer;  //denotes marker of easy player
	Easy _easy;  //create instance of easy player
};

#endif
