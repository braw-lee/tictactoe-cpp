#include "handler.h"
#include "board.h"
using namespace std;

Handler::Handler()
{
}

void Handler::inputGameMode()
{
	cout<<"\nChoose a game mode";
	cout<<"\n\t1 Two player\n\t2 Single player easy\n\t3 Single player hard";
	bool done{false};
	while(!done)
	{
		cout<<"\nEnter 1 , 2 or 3 : ";
		int x;
		cin>>x;

		switch(x)
		{
			case 1: 
				_mode = GameMode::twoPlayer;
				done = true;
				break;
			case 2:
				_mode = GameMode::singlePlayerEasy;
				done = true;
				break;
			case 3:
				_mode = GameMode::singlePlayerHard;
				done = true;
				break;
			default:
				cout<<"\nINVALID CHOICE\nTRY AGAIN!";
				break;
		}
	}
}

void Handler::setUpBoard()
{
	_board.setSize(inputBoardSize());
	_board.setConsecutiveMarker(inputConsecutiveMarker());
	_board.createBoard();
}

void Handler::runGame()
{
	inputGameMode();
	if(_mode == GameMode::twoPlayer)
		runTwoPlayerGame();
	else if(_mode == GameMode::singlePlayerEasy)
		runSinglePlayerEasyGame();
	else if(_mode == GameMode::singlePlayerHard)
		runSinglePlayerHardGame();
}

void Handler::runTwoPlayerGame()
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

void Handler::runSinglePlayerEasyGame()
{
	_currentPlayer = O_MARK; //Game starts with O

	setUpBoard();

	while(1)
	{	
		cout<<"Enter 1 for 'X' or 2 for 'O', 'O' starts the game : ";
		int c;
		cin>>c;

		if(c == 1)
		{
			_humanPlayer = X_MARK;
			_easyPlayer = O_MARK;
			break;
		}
		else if(c == 2)
		{
			_humanPlayer = O_MARK;
			_easyPlayer = X_MARK;
			break;
		}
		else
			cout<<"\nINVALID CHOICE!\nTRY AGAIN!";
	}

	//setup easy player
	Easy easy;
	for(int i=0; i< _board.getSize() * _board.getSize(); i++)
	{
		_board.printBoard();
		cout<<MARKERS[_currentPlayer]<<"'s turn : ";
		if(_currentPlayer == _easyPlayer)
			easy.move(_board, _easyPlayer);
		else if(_currentPlayer == _humanPlayer)
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

void Handler::runSinglePlayerHardGame()
{
	_currentPlayer = O_MARK; //Game starts with O
	
	setUpBoard();
	
	while(1)
	{	
		cout<<"Enter 1 for 'X' or 2 for 'O', 'O' starts the game : ";
		int c;
		cin>>c;

		if(c == 1)
		{
			_humanPlayer = X_MARK;
			_hardPlayer = O_MARK;
			break;
		}
		else if(c == 2)
		{
			_humanPlayer = O_MARK;
			_hardPlayer = X_MARK;
			break;
		}
		else
			cout<<"\nINVALID CHOICE!\nTRY AGAIN!";
	}

	//setup _hard
	Hard hard;
	hard.setMarker(_hardPlayer);
	for(int i=0; i< _board.getSize() * _board.getSize(); i++)
	{
		_board.printBoard();
		cout<<MARKERS[_currentPlayer]<<"'s turn : ";
		if(_currentPlayer == _hardPlayer)
			hard.playHardMove(_board);
		else if(_currentPlayer == _humanPlayer)
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
