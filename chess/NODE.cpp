#include "NODE.h"
namespace Rules
{
	int actions[8][2] = { {-1, 2}, {1, 2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2} };
}
using namespace Rules;

NODE::NODE() {}

bool NODE::createNode(int xpos, int ypos, int* goalx, int* goaly) 
{
	position[0] = xpos; position[1] = ypos;

	//cout << "Node born at position: " << position[0] << "," << position[1] << "    ";
	//cout << "leaf:" << leaf << ". Legal: " << legal << endl;

	if (xpos == *goalx && ypos == *goaly)
	{
		return true;
	}

	return false;
}


bool NODE::isLegal(int x,int y,int* cols,int* rows )
{
	return (x >= 0 && y >= 0 && x < *cols && y < *rows);
}
bool isNull(NODE* n)
{
	return n == NULL;
}

bool NODE::takeAction(int* cols, int* rows, int* goalx, int* goaly, int** explored, stack<int> *route)
{
	bool goalfound = false;

	if (leaf)
	{
		leaf = false;
		children = new NODE * [8];

		for (int i = 0; i < 8; i++)
		{
			int x_ = position[0] + actions[i][0];
			int y_ = position[1] + actions[i][1];

			if (isLegal(x_, y_, cols, rows))
			{
				bool match = false;
				if (explored[x_][y_] == 1)
				{
					match = true;
				}
				if (!match)
				{
					NODE* n;
					n = new NODE;
					bool g;
					explored[x_][y_] = 1;
					g = n->createNode(x_, y_, goalx, goaly);										
					children[i] = n;
					if (g)
					{
						goalfound = true;
						route->push(children[i]->position[1]);
						route->push(children[i]->position[0]);
					}
				}
				else
				{
					children[i] = NULL;
				}
			}
			else
				children[i] = NULL;
		}
		if (goalfound)		//Lowest parent
		{
			route->push(position[1]);	//Inverse order
			route->push(position[0]);
			return true;
		}			
	}
	else 
	{
		for (int i = 0; i < 8; i++)
			if (!isNull(children[i]))
			{
				goalfound = children[i]->takeAction(cols, rows, goalx, goaly, explored, route);
				if (goalfound)		//All parents, including root
				{
					route->push(position[1]);	//Inverse order
					route->push(position[0]);
					return true;
				}
					
			}				
		}
	}
	
	return false;
}


void NODE::clearNode()
{
	if (!leaf)	//Special case for start == goal
	{
		for (int i = 0; i < 8; i++)
		{
			if (isNull(children[i]))
			{
				if (children[i]->leaf)
				{
					delete children[i];
				}
				else
				{
					children[i]->clearNode();
				}
			}			
		}
	}
}



NODE::~NODE(){}