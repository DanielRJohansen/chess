#pragma once

#include <iostream>
#include <stack>
using namespace std;

class ChessTree
{
public:
	ChessTree();

	int findRoute(int cols, int rows, int goalpos[2], int startpos[2]);
	
	int getCols();
	int goal[2];

	int **explored;
	~ChessTree();


protected:
	
	int start[2];
	stack<int> route;

	//used by children only	
	int getRows();
private:

	void initExplored();
	void clearExplored();
	int cols = 4;
	int rows = 4;
};