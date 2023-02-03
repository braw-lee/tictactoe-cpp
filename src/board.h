#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
using namespace std;

const char MARKERS[3] = {'-','X','O'};
const int EMPTY = 0;
const int X_MARK = 1;
const int O_MARK = 2;

const int X_WON = 10;
const int O_WON = -10;
const int TIE = -1;
const int NOBODY_WON = 0;
const int CONSECUTIVE_MARKERS_REQUIRED = 3;

class Board
{
public:
	Board();  //default constructor
	Board(int size);  //create a board with custome size, here size>2
	void createBoard(); //creates a game board
	void clearBoard(); //clears the game board
	void printBoard(); //prints the game b0ard
	int getVal(int x, int y); //returns value at x-y cordinate of board
	void setVal(int x, int y, int state); //sets value to state at x-y cordinate
	int checkWin();  
	int getSize();  //returns the size of board
private:
	vector<vector<int>> _board;
	int _size;
};

#endif
