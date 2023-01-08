#include "functions.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cout<<"This is a tictactoe game\n\n\n";

	vector<vector<string>> board= {
					{"1","2","3"},
					{"4","5","6"},
					{"7","8","9"}
				};
	
	string player1,player2;
	cout<<"Enter name of first player ";
	cin>>player1;
	cout<<"Enter name of second player ";
	cin>>player2;

	cout<<player1<<"'s sign is 'O'\n";
	cout<<player2<<"'s sign is 'X'\n";

	displayBoard(board);
	bool turnOfPlayer1= true;  //player1 i.e with sign 'O' start the game
	for(int i=0; i<9; i++)
	{
		cout<<'\n'<<nameOfPlayer(turnOfPlayer1,player1,player2)<<"'s turn\n";
		inputFromPlayer(board,turnOfPlayer1);
		displayBoard(board);
		if(checkWin(board))
		//if somebody won, declare the correct winner
		{
			string winner;
			if(turnOfPlayer1)
			{
				winner= player1;
			}
			else
			{
				winner= player2;
			}
			cout<<winner<<" won the match\n";
			return 0;
		}
		turnOfPlayer1= !turnOfPlayer1;
	}
	//if nobody won after all inputs are filled, declare the match a tie
	cout<<"Its a tie\n";
	return 0;
}
