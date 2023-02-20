#include "hard.h"
#include "board.h"
#include "handler.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	/* debug
	Board b;
	b.createBoard();

	b.setVal(1,1,1);
	b.setVal(2,0,1);
	b.setVal(2,2,1);

	b.printBoard();
	
	Hard h;
	h.setMarker(2);
	h.playHardMove(b);
	b.printBoard();
	*/

	cout<<string(6,'-')<<"This is a tictactoe game"<<string(6,'-')<<"\n\n\n";

	string choice = "y";
	while(choice == "y" || choice =="Y")
	{
		Handler h1;
		h1.runGame();
		cout<<"Enter 'y' to play again, 'q' to quit : ";
		cin>>choice;
	}
	cout<<"\nSession over!\n";
	return 0;
}
