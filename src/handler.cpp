#include "handler.h"
#include "board.h"
using namespace std;

void Handler::runGame()
{
	_currentPlayer = O_MARK;  //game starts with O

	for(int i=0; i< _board.getSize() * _board.getSize(); i++)
	{	
		_board.printBoard();
		cout<<MARKERS[_currentPlayer]<<"'s turn : ";
		inputFromPlayer();
		
		int checkWinResult = _board.checkWin();
		if(checkWinResult == X_WON)
		{
			cout<<"X won the game!\n\n";
			return;  //game is over so end here
		}
		else if(checkWinResult == O_WON)
		{
			cout<<"O won the game!\n\n";
			return;
		}
		else if(checkWinResult == TIE)
		{
			cout<<"This game is a TIE!\n\n";
			return;
		}
		else if(checkWinResult == NOBODY_WON)
		{
			//do nothing
		}
		changePlayer(); 
	}
}

void Handler::inputFromPlayer()
{
	while(1)
	{
			
		int x,y;
		cout<<"\nEnter x cordinate : ";
		cin>>x;
		cout<<"Enter y cordinate : ";
		cin>>y;

		if(x>=0 && x< _board.getSize() && y>=0 && y< _board.getSize() )
		{
			if(_board.getVal(x,y) == EMPTY)
			{
				_board.setVal(x,y, _currentPlayer);
				return;
			}
			else
			{
				cout<<"POSITION ALREADY FILLED, TRY AGAIN\n\n";
			}
		}
		else
		{
			cout<<"INVALID CORDINATE, TRY AGAIN\n\n";
		}
	}
}

void Handler::changePlayer()
{
	if(_currentPlayer == O_MARK)
	{
		_currentPlayer = X_MARK;
	}
	else
	{
		_currentPlayer = O_MARK;
	}
}

void Handler::displayResult()
{
	cout<<MARKERS[_currentPlayer]<<"won the game\n";
	cout<<"GAME OVER!\n";
}
