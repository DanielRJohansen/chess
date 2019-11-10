#include "ChessTree.h"
#include "NODE.H"


ChessTree::ChessTree() {}



int ChessTree::findRoute(int c, int r, int goalpos[2], int startpos[2])
{
	cols = c;
	rows = r;
	goal[0] = goalpos[0]; goal[1] = goalpos[1];
	start[0] = startpos[0]; start[1] = startpos[1];


	NODE root;
	bool goalreached = false;
	root.createNode(start[0], start[1], &cols, &rows, &goal[0], &goal[1]);
	int depth = 0;
	for (int i = 0; i < 50; i++)
	{
		exploredhead = 0;
		depth++;
		cout << "Exploring move " << depth << exploredhead<<endl;
		goalreached = root.takeAction(&cols, &rows, &goal[0], &goal[1], explored, exploredhead);
		if (goalreached)
			break;
	}
	cout << "Goal reached after " << depth << " steps" << endl;


	root.clearNode();

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
