//Kattis Problem 1-D Frogger Hard
//This version exceeded the time limit.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> board;
int numSpaces; 
int total = 0;

void frogger(int start, int magic)
{
	int frog = start;	//frog will be used to index board
	set<int> visited; //visited positions in board
	//cout << "Testing " << start << " and " << magic << endl;
	while(69)
	{
		if (board[frog] == magic)
		{
			total++;
			return;
		}
		int move = frog + board[frog];
		
		if(move < 0 || move > numSpaces) return;
		else if (visited.count(move)) return;
		//else if( std::find(visited.begin(), visited.end, move)) return;
		else
		{
			frog = move;
			visited.insert(move);
			//cout << "Inserting: " << move << endl;
		}
	}
}

int main() {
	cin >> numSpaces;
	//Read in the board
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
			//if (j == i) continue;	//i is a position, j is a number
			frogger(i, board[j]);
		}
	}

	cout << total;
	return 0;
}
