#include "easy.h"
#include "board.h"

void Easy::move(Board& board, int easyPlayer)
{
	int x{};
	int y{};
	int size = board.getSize();
	while(1)
	{
		srand(time(nullptr));
		x = rand() % size;  //generates random number from 0 to size-1
		y = rand() % size;

		if(board.getVal(x,y) == EMPTY)
		{
			board.setVal(x,y,easyPlayer);
			break;
		}
	}
}
