#pragma once
#include<vector>
using namespace std;

class node
{
public:
	int id;
	int shape;
	int distance;
	node * prevNode;
	vector<node *> adjNodes;

	static int countId;

	node();
	~node();

};

int node::countId = 0;

node::node()
{
	id = countId++; 
	shape = 1;
	distance = 99999999;
	prevNode = NULL;

}

node::~node()
{
}

