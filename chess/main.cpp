#include "CHESSTREE.h"
#include "NODE.H"
#include "rules.h"
#include <iostream>
#include <stack>
using namespace std;

void test(stack<int>* s)
{
	s->push(11);
}

int main()
{
	int cols = 3000;
	int rows = 3000;
	int start[2] = { 2,2 };
	int goal[2] = { 2070,2510 };
	
	stack <int> s;

	test(&s);


	
	ChessTree CT;
	CT.findRoute(cols, rows, goal, start);

	return 0;



}

