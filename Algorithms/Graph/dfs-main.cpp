#include<iostream>
#include<vector>
#include<queue>
#include"dfs-node.h"
using namespace std;

void printPath(node * node1, node* node2);
void DFS(vector<node *> nodeList);
void DFS_VISIT(node * _node);
static int time;
int main()
{
	vector<node *> nodeList;
	for (int i = 0; i < 10; i++)
	{
		node * z = new node();
		nodeList.push_back(z);
	}

	nodeList[0]->adjNodes.push_back(nodeList[1]);
	nodeList[0]->adjNodes.push_back(nodeList[2]);
	nodeList[0]->adjNodes.push_back(nodeList[3]);
	nodeList[1]->adjNodes.push_back(nodeList[4]);
	nodeList[1]->adjNodes.push_back(nodeList[5]);
	nodeList[1]->adjNodes.push_back(nodeList[6]);
	nodeList[2]->adjNodes.push_back(nodeList[6]);
	nodeList[2]->adjNodes.push_back(nodeList[7]);
	nodeList[3]->adjNodes.push_back(nodeList[5]);
	nodeList[3]->adjNodes.push_back(nodeList[9]);
	nodeList[4]->adjNodes.push_back(nodeList[5]);
	nodeList[5]->adjNodes.push_back(nodeList[4]);
	nodeList[5]->adjNodes.push_back(nodeList[8]);
	nodeList[6]->adjNodes.push_back(nodeList[9]);
	nodeList[7]->adjNodes.push_back(nodeList[8]);
	nodeList[8]->adjNodes.push_back(nodeList[4]);
	nodeList[9]->adjNodes.push_back(nodeList[8]);

	DFS(nodeList);
	for (int i = 1; i < nodeList.size(); i++)
	{
		printPath(nodeList[0], nodeList[i]);
		cout << endl;
	}

	return 0;
}

void DFS(vector<node *> nodes)
{
	time = 0;
	for (int i = 0; i < nodes.size(); i++)
		if (nodes[i]->shape == 1)
			DFS_VISIT( nodes[i]);
}

void DFS_VISIT( node * _node)
{
	vector<node*>::iterator i;
    _node->shape=0;
	time=time+1;
	_node->d_time=time;
	for(i=_node->adjNodes.begin();i!=_node->adjNodes.end();++i)
	{
		if((*i)->shape==1)
		{
			(*i)->prevNode=_node;
			DFS_VISIT(*i);
		}
	}
	_node->shape=-1;
	time=time+1;
	_node->f_time=time;
}

void printPath(node * node1, node* node2)
{
	if (node1 == node2)
		cout << node1->id;
	else
	{
		if (node2->prevNode == NULL)
			cout << "no path from" << node1->id << "to" << node2->id << "exist" << endl;
		else
		{
			printPath(node1, node2->prevNode);
			cout << node2->id;
		}

	}
}