#pragma once

#include <iostream>

using namespace std;

class ChessTree
{
public:
	ChessTree();

	int findRoute(int cols, int rows, int goalpos[2], int startpos[2]);
	
	int getCols();
	int goal[2];

	int* explored[2500][2] = { 0,0 };
	int* exploredhead;
	~ChessTree();


protected:
	int route[100];
	
	
	int start[2];
	int actions[8][2] = { {-1, 2}, {1, 2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2} };

	//used by children only
	
	int getRows();
private:
	int cols = 4;
	int rows = 4;
};