#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

string nameOfPlayer(bool ,string , string );
void displayBoard(vector<vector<string>> &);
void getRowCol(int *,int *,string);
void inputFromPlayer(vector<vector<string>> &, bool);
int checkWin(vector<vector<string>> &);


#endif
