//Kattis Problem 1-D Frogger Hard
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> winPairs; //caching, for speed
vector<vector<int>> losePairs; //caching, for speed
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
		
		if(move < 0 || move > numSpaces || visited.count(move)) 
		{
			losePairs[start].push_back(magic);	//this (start,magic is a losing pair)
			return;
		}
		else
		{
			frog = move;
			visited.insert(move);
			winPairs[start].push_back(magic);	//this (start,magic is a winning pair)
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
		vector<int> middleVect;
		winPairs.push_back(middleVect);
		losePairs.push_back(middleVect);
	}
	
	//Traverse the board
	for(int i = 0; i < numSpaces; i++)	//start from each space
	{
		for(int j = 0; j < numSpaces; j++)	//use each possible magic number for that start
		{
			//if (j == i) continue;	//i is a position, j is a number
			if(find(winPairs[i].begin(), winPairs[i].end(), j) == winPairs[i].end())
				frogger(i, board[j]);
			else if(find(losePairs[i].begin(), losePairs[i].end(), j) == losePairs[i].end())
				continue;
			else total++;
		}
	}

	cout << total;
	return 0;
}
