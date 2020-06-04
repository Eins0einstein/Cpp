#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define max_vexNum 26	
#define MAX_PATH_LENGTH 9999999
bool is_visited[max_vexNum];			
int path[MAX_PATH_LENGTH][max_vexNum];	
int path_num = 0, path_index = 0;
int bestLength = INT_MAX;
int graph[100][100];
double lenth[MAX_PATH_LENGTH];
void generate(int graph[100][100],int number);
void bruteforce(int graph[100][100],int number,int startcity,int root
);
int main()
{
	int number = 5;
	cout << "Please enter the number : " << endl;
	cin >> number;
	generate(graph, number);
	bruteforce(graph, number, 0, 0);
	for (int i = 0; i < number; i++)
	{
		for (int m = 0; m < number; m++)
		{
			cout << graph[m][i] << "  ";
		}
		cout << endl;
	}
	cout << "×î¶ÌÂ·³ÌbestLength = " << bestLength << endl;
	system("pause");
	return 0;
}
void generate(int graph[100][100], int number)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < number; i++)
	{
		for (int m = i ; m < number; m++)
		{
			if (i != m)
			{
				int RandomNumber;
				
				RandomNumber = rand() % 100 + 1;
				graph[i][m] = RandomNumber;
			  graph[m][i] = graph[i][m];
			}
			
		}
	}
}
void bruteforce(int graph[100][100], int number, int startcity,int root)
{
	if (path_index == number - 1 && graph[startcity][root] > 0)
	{
		path[path_num][path_index] = startcity;
		path[path_num][path_index + 1] = root;
		lenth[path_num] = 0;
		for (int i = 0; i < number; i++)
		{
			lenth[path_num] += graph[path[path_num][i]][path[path_num][i + 1]];
		}

		if (bestLength > lenth[path_num])
		{
			bestLength = lenth[path_num];
			for (int i = 0; i < number; i++)
			{
				cout << path[path_num][i]+1 << "->";
			}
			cout << endl;
		}
		path_num++;
		for (int i = 0; i < number; i++)
		{
			path[path_num][i] = path[path_num - 1][i];
		}
		return;
	}
	else
	{

		for (int i = 0; i < number; i++)
		{
			if (graph[startcity][i] > 0 && !is_visited[i])
			{
				path[path_num][path_index] =startcity;
				path_index++;
				is_visited[startcity] = true;
				bruteforce(graph, number, i, root);
				path_index--;
				is_visited[startcity] = false;
			}
		}
	}

}
