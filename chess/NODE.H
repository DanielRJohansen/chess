#pragma once

#include <string>
#include <iostream>
#include "CHESSTREE.h"
#include <stack>

using namespace std;

class NODE //: public ChessTree
{
public:
	NODE();
	bool createNode(int xpos, int ypos, int* goalx, int* goaly);
	
	bool takeAction(int* cols, int* rows, int*goalx, int* goaly, int** explored, stack<int> *route);
	void clearNode();

	~NODE();


protected:
	bool leaf = true;
	bool isLegal(int x, int y, int* cols, int* rows);
	int position[2];
	NODE** children;
};