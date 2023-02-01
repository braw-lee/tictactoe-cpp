#include "board.h"
#include "handler.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cout<<string(6,'-')<<"This is a tictactoe game"<<string(6,'-')<<"\n\n\n";

	string choice = "y";
	while(choice == "y")
	{
		Handler h1;
		h1.runGame();
		cout<<"Enter 'y' to play again, 'n' to quit : ";
		cin>>choice;
	}
	cout<<"\nSession over!\n";

	return 0;
}
