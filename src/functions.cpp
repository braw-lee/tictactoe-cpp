#include "functions.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


string nameOfPlayer(bool turnOfPlayer1, string player1,string player2)
{
	if(turnOfPlayer1)
	{
		return player1;
	}
	else
		return player2;
}

void displayBoard(vector<vector<string>> &boardPara, int row, int col)
{
	
	for(int i=0; i<row; i++)
	{
		cout<<string(col*3 + col+1,'-')<<endl;
		for(int j=0; j<col; j++)
		{
			cout<<"| "<<boardPara[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<string(col*3 + col+1,'-')<<endl;
}

void getRowCol(int *row, int *coloumn, string position)
{
	if(position=="1")
	{
		*row= 0;
		*coloumn= 0;
	}
	else if(position=="2")
	{
		*row= 0;
		*coloumn= 1;
	}
	else if(position=="3")
	{
		*row= 0;
		*coloumn= 2;
	}
	else if(position=="4")
	{
		*row= 1;
		*coloumn= 0;
	}
	else if(position=="5")
	{
		*row= 1;
		*coloumn= 1;
	}
	else if(position=="6")
	{
		*row= 1;
		*coloumn= 2;
	}
	else if(position=="7")
	{
		*row= 2;
		*coloumn= 0;
	}
	else if(position=="8")
	{
		*row= 2;
		*coloumn= 1;
	}
	else if(position=="9")
	{
		*row= 2;
		*coloumn= 2;
	}
	else  //invalid input
	{
		*row= -1;
		*coloumn= -1;
	}
}

void inputFromPlayer(vector<vector<string>> &board, bool turnOfPlayer1)
{
	while(1)
	{		
		cout<<"Enter the position you want to fill ";
		string pos;
		cin>>pos;

		int row,coloumn;
		getRowCol(&row, &coloumn, pos);
		if(row== -1)
		{
			cout<<"Invalid input, this position does not exist\n";
			cout<<"Try again!\n\n";
		}
		else
		{
			
				if(board[row][coloumn]=="O" ||board[row][coloumn]=="X")
				{
					cout<<"Invalid input, this position is already filled\n";
					cout<<"Try, again!\n\n";
				}
				else
				{
					if(turnOfPlayer1)
					{
						board[row][coloumn]= "O";
					}
					else
					{
						board[row][coloumn]= "X";
					}
					return; //objective completed, end the function
				}
		}
	}
}

int checkWin(vector<vector<string>> &board)
/*
return 0 : nobody won
return 1 : somebody won
*/
{
	for(int i=0; i<3; i++)
	{
		if((board[i][0]==board[i][1] && board[i][1]==board[i][2]) || (board[0][i]==board[1][i] && board[1][i]==board[2][i]))
			return 1;
		if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0]))
			return 1;
	}
	return 0;
}

vector<vector<string>> createBoard(int row, int col)
{
	vector<vector<string>> board;
	for(int i=0; i<row; i++)
	{
		vector<string> innerVector;
		for(int j=0; j<col; j++)
		{
			innerVector.push_back("-");
		}
		board.push_back(innerVector);
	}
	return board;
}
