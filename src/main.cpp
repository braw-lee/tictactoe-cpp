#include <iostream>
#include <vector>
using namespace std;

void displayBoard(vector<vector<int>> &boardPara)
{
	cout<<" "<<boardPara[0][0]<<" | "<<boardPara[0][1]<<" | "<<boardPara[0][2]<<" \n";
	cout<<"___|___|___\n";
	cout<<" "<<boardPara[1][0]<<" | "<<boardPara[1][1]<<" | "<<boardPara[1][2]<<" \n";
	cout<<"___|___|___\n";	
	cout<<" "<<boardPara[2][0]<<" | "<<boardPara[2][1]<<" | "<<boardPara[2][2]<<" \n";
	cout<<"   |   |   \n";
}
int main()
{
	cout<<"This is a tictactoe game\n";

	vector<vector<int>> board= {{1,2,3},{4,5,6},{7,8,9}};
	displayBoard(board);
	
}
