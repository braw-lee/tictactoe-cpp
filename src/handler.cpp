#include "handler.h"
#include "board.h"
using namespace std;

Handler::Handler()
{
}

void Handler::setUpBoard()
{
	_board.setSize(inputBoardSize());
	_board.setConsecutiveMarker(inputConsecutiveMarker());
	_board.createBoard();
}

void Handler::runGame()
{
	_currentPlayer = O_MARK;  //game starts with O
	
	setUpBoard();
	for(int i=0; i< _board.getSize() * _board.getSize(); i++)
	{	
		_board.printBoard();
		cout<<MARKERS[_currentPlayer]<<"'s turn : ";
		inputFromPlayer();
		
		int checkWinResult = _board.checkWin();

		if(checkWinResult == NOBODY_WON)
		{}
		else
		{
			_board.printBoard();
			if(checkWinResult == TIE)
			{
				cout<<"This game is a TIE!\n";
			}
			else if(checkWinResult == X_WON || checkWinResult == O_WON)
			{
				displayWinner();
			}
			cout<<"GAME OVER!\n\n";
			return;
		}

		changePlayer(); 
	}
}

int Handler::inputBoardSize()
{
	cout<<"\nEnter board size : ";
	int size{};
	cin>>size;
	return size;
}


int Handler::inputConsecutiveMarker()
{
	cout<<"\nEnter consecutive markers required to win : ";
	int n{};
	cin>>n;
	return n;
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

void Handler::displayWinner()
{
	cout<<MARKERS[_currentPlayer]<<" won the game\n";
}
