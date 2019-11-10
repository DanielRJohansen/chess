#pragma once

#include <string>
#include <iostream>
#include "CHESSTREE.h"

using namespace std;

class NODE //: public ChessTree
{
public:
	NODE();
	bool createNode(int xpos, int ypos, int* cols, int* rows, int* goalx, int* goaly);
	bool leaf = true;
	bool isLegal(int x, int y, int* cols, int* rows);
	bool takeAction(int* cols, int* rows, int*goalx, int* goaly, int* explored[2500][2], int* exploredhead);
	void clearNode();

	~NODE();

protected:
	int position[2];
	NODE** children;
};