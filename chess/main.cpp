#include "CHESSTREE.h"
#include "NODE.H"
#include "rules.h"
#include <iostream>
#include <stack>
using namespace std;



int main()
{
	int cols = 300;
	int rows = 300;
	int start[2] = { 2,2 };
	int goal[2] = { 270,251 };
	



	
	ChessTree CT;
	CT.findRoute(cols, rows, goal, start);

	return 0;



}

