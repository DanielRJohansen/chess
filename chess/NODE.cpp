#include "NODE.h"
namespace Rules
{
	int actions[8][2] = { {-1, 2}, {1, 2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2} };
}
using namespace Rules;

NODE::NODE() {}

bool NODE::createNode(int xpos, int ypos, int* cols, int* rows, int* goalx, int* goaly) 
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

bool NODE::takeAction(int* cols, int* rows, int* goalx, int* goaly, int* explored[2500][2], int* exploredhead)
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
				for (int j = 0; j < *exploredhead; j++)
				{
					if (!(x_ == *explored[j][0] && y_ == *explored[j][1]))
					{
						NODE* n;
						n = new NODE;
						bool g;
						*explored[*exploredhead][0] = x_;
						*explored[*exploredhead][0] = y_;
						*exploredhead++;
						g = n->createNode(x_, y_, cols, rows, goalx, goaly);
						if (g == true)
							goalfound = true;
						children[i] = n;
					}
					else
						children[i] = NULL;
				}
			}
			else
			{
				children[i] = NULL;
			}
				
			//cout << children[i]->position[0] << endl;
		}
		if (goalfound)
			return true;
	}
	else 
	{
		for (int i = 0; i < 8; i++)
		{

			if (!isNull(children[i]))
			{
				goalfound = children[i]->takeAction(cols, rows, goalx, goaly, explored, exploredhead);
				if (goalfound)
					return true;
			}				
		}
	}
	
	return false;
}


void NODE::clearNode()
{
	if (!leaf)	//Special case for start== goal
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
	
	
	/*
	if (! leaf)
	{
		cout << "pre+del" << endl;
		delete[] * children;
		cout << "deleted";
	}
	*/
	//Technically the leafs have uninitialized children, so we delete this array for all nodes from bottom up.
	/*
	for (int i = 0; i < 8; i++)
	{
		delete children[i];
	}
	*/
}



NODE::~NODE(){}