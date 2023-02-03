#include "board.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Board::Board()
{
	_size = 3;  //default board is 3X3
	createBoard();
}

Board::Board(int size)
{
	if(size<3)
	{
		perror("INVALID SIZE\n");
	}
	_size = size;
	createBoard();
}

void Board::createBoard()
{
	for(int i=0; i< _size; i++)
	{
		vector<int> innerVector;
		for(int j=0; j<_size; j++)
		{
			innerVector.push_back(EMPTY);
		}
		_board.push_back(innerVector);
	}
}

void Board::clearBoard()
{
	for(int i=0; i< _size; i++)
	{
		for(int j=0; j< _size; j++)
		{
			_board[i][j]= EMPTY;
		}
	}
}

void Board::printBoard()
{
	int row,col; //for future use
	row= _size;
	col= _size;

	cout<<"   ";
	for(int k=0; k<col; k++)
	{		
		cout<<"| "<<k<<" ";
	}
	cout<<"|"<<endl;
	
	for(int i=0; i<row; i++)
	{
		cout<<"   "<<string(col*3 + col+1,'-')<<endl;
		cout<<" "<<i<<" ";
		for(int j=0; j<col; j++)
		{
			cout<<"| "<< MARKERS[getVal(i,j)]<<" ";
		}
		cout<<"| "<<endl;
	}
	cout<<"   "<<string(col*3 + col+1,'-')<<endl;

}

int Board::getVal(int x, int y)
{
	return _board[x][y];
}

void Board::setVal(int x, int y, int state)
{
	_board[x][y] = state;
}

int Board::checkWin()
{
	int counter=1;

	//check rows
	for(int i=0; i< _size; i++)
	{
		counter = 1;
		for(int j=0; j< _size-1; j++)
		{
			if(getVal(i,j)!=EMPTY && getVal(i,j)==getVal(i,j+1))
			{
				counter+=1;
				if(counter == CONSECUTIVE_MARKERS_REQUIRED)
				{
					if(getVal(i,j) == X_MARK)
						return X_WON;
					else
						return O_WON;
				}
			}
			else
			{
				counter= 1;
			}

		}
	}

	//check coloumns
	for(int i=0; i< _size; i++)
	{
		counter = 1;
		for(int j=0; j< _size-1; j++)
		{
			if(getVal(j,i)!=EMPTY && getVal(j,i)==getVal(j+1,i))
			{
				counter+=1;
				if(counter == CONSECUTIVE_MARKERS_REQUIRED)
				{
					if(getVal(j,i) == X_MARK)
						return X_WON;
					else
						return O_WON;
				}
			}
			else
			{
				counter= 1;
			}

		}
	}

	//check left to right diagonals
	for(int i=0; i< _size-CONSECUTIVE_MARKERS_REQUIRED+1; i++)
	{
		counter = 1;
		for(int j=0; j< _size-i-1; j++)
		{
			if(getVal(j,i+j) != EMPTY && getVal(j,i+j) == getVal(j+1,i+j+1))
			{
				counter+=1;
				if(counter == CONSECUTIVE_MARKERS_REQUIRED)
				{
					if(getVal(j,i+j) == X_MARK)
						return X_WON;
					else
						return O_WON;
				}
			}
			else
			{
				counter = 1;
			}
		}
	}	
	for(int i=0; i< _size-CONSECUTIVE_MARKERS_REQUIRED+1; i++)
	{
		counter = 1;
		for(int j=0; j< _size-i-1; j++)
		{
			if(getVal(i+j,j) != EMPTY && getVal(i+j,j) == getVal(i+j+1,j+1))
			{
				counter+=1;
				if(counter == CONSECUTIVE_MARKERS_REQUIRED)
				{
					if(getVal(i+j,j) == X_MARK)
						return X_WON;
					else
						return O_WON;
				}
			}
			else
			{
				counter = 1;
			}
		}
	}

	//check right to left diagonals
	for(int i=0; i< _size-CONSECUTIVE_MARKERS_REQUIRED+1; i++)
	{
		counter = 1;
		for(int j=0; j< _size-i-1; j++)
		{
			if(getVal(_size-1-j,i+j) != EMPTY && getVal(_size-1-j,i+j) == getVal(_size-1-j-1,i+j+1))
			{
				counter+=1;
				if(counter == CONSECUTIVE_MARKERS_REQUIRED)
				{
					if(getVal(_size-1-j,i+j) == X_MARK)
						return X_WON;
					else
						return O_WON;
				}
			}
			else
			{
				counter = 1;
			}
		}
	}	
	for(int i=0; i< _size-CONSECUTIVE_MARKERS_REQUIRED+1; i++)
	{
		counter = 1;
		for(int j=0; j< _size-i-1; j++)
		{
			if(getVal(_size-1-i-j,j) != EMPTY && getVal(_size-1-i-j,j) == getVal(_size-1-i-j-1,j+1))
			{
				counter+=1;
				if(counter == CONSECUTIVE_MARKERS_REQUIRED)
				{
					if(getVal(_size-1-i-j,j) == X_MARK)
						return X_WON;
					else
						return O_WON;
				}
			}
			else
			{
				counter = 1;
			}
		}
	}

	//check for tie
	for(int i=0; i< _size; i++)
	{
		for(int j=0; j< _size; j++)
		{
			if(getVal(i,j) == EMPTY)
				return NOBODY_WON;
		}
	}

	//if all places are filled but nobody has won, then it is a tie game 
	return TIE;
}

int Board::getSize()
{
	return _size;
}
