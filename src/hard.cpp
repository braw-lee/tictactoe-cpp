#include <iostream>
#include "hard.h"
using namespace std;

void Hard::setMarker(int hardPlayer)
{
	if(hardPlayer == O_MARK)
	{
		_hardPlayer = O_MARK;
		_hardPlayerWon = O_WON;

		_humanPlayer = X_MARK;
		_humanPlayerWon = X_WON;
	}
	else //hardPlayer == X_MARK
	{
		_hardPlayer = X_MARK;
		_hardPlayerWon = X_WON;

		_humanPlayer = O_MARK;
		_humanPlayerWon = O_WON;
	}
}

Move Hard::getHardMove(Board& board, int currentPlayer)
{
	/*
	base case, if somebody won(or tie), return appropriate result
	If nobody won, get next best move for other player
	*/
	int checkWinResult = board.checkWin();
	if(checkWinResult != NOBODY_WON)
	{
		if(checkWinResult == _hardPlayerWon)
		{
			return {-1,-1,10};
			/*
			When we return {x,y,z}, c++ implicitly converts
			this into :
				return (Move m{-1,-1,10});
			because the function returns a Move type.

			Returning invalid cordinates i.e '-1' because we use this
			() to get Move.result , we already set x and y before
			*/
		}
		else if(checkWinResult == _humanPlayerWon)
		{
			return {-1,-1,-10};
		}
		else if(checkWinResult == TIE)
		{
			return {-1,-1,0};
		}
	}

	/*
	Instead of making a vector of all moves and then checking for
	best move, we will initialize a Move object 'bestMove'.
	
	If currentPlayer == _hardPlayer , we want to maximize the score
	as checkWinResult == _hardPlayer returns +10
	so we initialize bestMove with a low result , this ensures we update
	bestMove atleast once

	If currentPlayer == _humanPlayer , we want to minimize the score
	as checkWinResult == _humanPlayer returns -10
	so we initialize bestMove with a high result , this ensures we update
	bestMove atleast once
	*/

	Move bestMove;
	if(currentPlayer == _hardPlayer)
		bestMove.result = -10000;
	else //currentPlayer == _humanPlayer
		bestMove.result = 10000;

	for(int i=0; i<board.getSize(); i++)
	{
		for(int j=0; j<board.getSize(); j++)
		{
			if(board.getVal(i,j) == EMPTY)
			{
				Move tempMove;
				tempMove.x = i;
				tempMove.y = j;

				//this () just gets the hard move,
				//so we must undo this setVal() later
				//we undo it in line #98
				board.setVal(i,j,currentPlayer);

				if(currentPlayer == _hardPlayer)
					tempMove.result = getHardMove(board, _humanPlayer).result;
				else //currentPlayer == _humanPlayer
					tempMove.result = getHardMove(board, _hardPlayer).result;

				board.setVal(i,j,EMPTY);
				
				//update best move
				if(currentPlayer == _hardPlayer)
				{
					//update only if we have a better move
					if(bestMove.result < tempMove.result)
					{
						bestMove = tempMove;
					}
				}
				else //currentPlayer == _humanPlayer
				{
					//update only if we have a better move
					if(bestMove.result > tempMove.result)
					{
						bestMove = tempMove;
					}
				}
			}
		}
	}
	return bestMove;
}

void Hard::playHardMove(Board& board)
{
	Move bestMove = getHardMove(board, _hardPlayer);
	board.setVal(bestMove.x, bestMove.y, _hardPlayer);
}
