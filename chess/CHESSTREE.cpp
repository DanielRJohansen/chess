#include "ChessTree.h"
#include "NODE.H"


ChessTree::ChessTree() {}

void ChessTree::initExplored()
{
	explored = new int* [cols];
	for (int i = 0; i < cols; i++)
	{
		explored[i] = new int[rows];
		for (int j = 0; j < rows; j++)
		{
			explored[i][j] = 0;
		}
	}
}


void ChessTree::clearExplored()
{
	for (int i = 0; i < cols; i++)
	{
		delete[] explored[i];
	}
	delete[] explored;
}


int ChessTree::findRoute(int c, int r, int goalpos[2], int startpos[2])
{
	cols = c;
	rows = r;
	goal[0] = goalpos[0]; goal[1] = goalpos[1];
	start[0] = startpos[0]; start[1] = startpos[1];

	initExplored();

	NODE root;
	bool goalreached = false;
	root.createNode(start[0], start[1], &goal[0], &goal[1]);
	int depth = 0;


	cout << "Searching " << cols << " by " << rows << " chessboard for goal (" << goalpos[0]
		<< "," << goalpos[1] << ") from starting position (" << startpos[0] << "," << startpos[1] << ")" << endl;


	while (true)
	{
		depth++;
		cout << "Exploring move " << depth <<endl;

		goalreached = root.takeAction(&cols, &rows, &goal[0], &goal[1], explored, &route);
		if (goalreached)
			break;
	}
	cout << "Goal reached after " << depth << " steps" << endl << "Route: ";
	while (!(route.empty()))
	{
		cout << " (" << route.top() << ",";
		route.pop();
		cout << route.top() << ") ->";
		route.pop();
	}


	root.clearNode();
	clearExplored();
	return 0;
}

int ChessTree::getCols()
{
	return this->cols;
}
int ChessTree::getRows()
{
	return rows;
}





ChessTree::~ChessTree() {}
