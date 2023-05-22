#include <iostream>
#include <vector>
using namespace std;

vector<int> board;
int numSpaces; 
int total = 0;

void frogger(int start; int magic)
{
	int frog = start;	//frog will be used to index board
	vector<int> visited; 
	while(69)
	{
		if (board[frog] == magic)
		{
			total++;
			return;
		}
		int move = frog + board[frog];
		
		if(move < 0 || move > numSpaces)
	}
	
	//if winning pair
	total++;
}

int main() {
	cin >> numSpaces;
	for(int i = 0; i < numSpaces; i++)
	{
		int middleMan;
		cin >> middleMan;
		board.push_back(middleMan);
	}
	
	//Traverse the board
	for(int i = 0; i < numSpaces; i++)	//start from each space
	{
		for(int j = 0; j < numSpaces; j++)	//use each possible magic number for that start
		{
			if (j == i) continue;
			frogger(i, j);
		}
	}
	return 0;
}
