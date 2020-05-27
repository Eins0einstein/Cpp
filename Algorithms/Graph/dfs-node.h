#pragma once
#include<vector>
using namespace std;

class node
{
public:
	int id;		
	int shape;
	int d_time;
	int f_time;
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
	d_time = 0;
	f_time = 0;
	prevNode = NULL;

}

node::~node()
{
}