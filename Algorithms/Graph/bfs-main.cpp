#include<iostream>
#include<vector>
#include<queue>
#include"bfs-node.h"
using namespace std;

void printPath(node * node1, node* node2);
void BFS(vector<node *> nodeList);
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
	nodeList[2]->adjNodes.push_back(nodeList[1]);
	nodeList[2]->adjNodes.push_back(nodeList[5]);
	nodeList[3]->adjNodes.push_back(nodeList[5]);
	nodeList[3]->adjNodes.push_back(nodeList[6]);
	nodeList[4]->adjNodes.push_back(nodeList[7]);
	nodeList[5]->adjNodes.push_back(nodeList[4]);
	nodeList[5]->adjNodes.push_back(nodeList[8]);
	nodeList[6]->adjNodes.push_back(nodeList[8]);
	nodeList[6]->adjNodes.push_back(nodeList[9]);
	nodeList[7]->adjNodes.push_back(nodeList[8]);
	nodeList[8]->adjNodes.push_back(nodeList[4]);
	nodeList[9]->adjNodes.push_back(nodeList[8]);

	BFS(nodeList);
	for (int i = 1; i < nodeList.size(); i++)
	{
		printPath(nodeList[0], nodeList[i]);
		cout << endl;
	}
	return 0;
}

void BFS(vector<node *> nodeList)
{
	queue<node *>	Q;
	nodeList[0]->shape = 0;
	nodeList[0]->distance = 0;
	Q.push(nodeList[0]);

	vector<node*>::iterator i;

	while (!Q.empty())
	{
		node* s=Q.front();
		Q.pop();

		for(i=s->adjNodes.begin();i!=s->adjNodes.end();++i)
		{
			if ((*i)->shape==1)
			{
				(*i)->shape=0;
				(*i)->distance=s->distance+1;
				(*i)->prevNode=s;
				Q.push(*i);
			}
			
		}
	}
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
			cout << node2->id<<" "<<node2->distance;
		}

	}
}