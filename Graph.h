#pragma once
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
void GraphTraversal()
{
	const int V = 6;
	int arr[][2] = { {1, 2},
						{2, 7},
						{2, 5},
						{2, 6},
						{3, 4},
						{1, 3}
	};

	//create adjacency list from any given format
	vector<int>adj[8];
	for (int i = 0; i < 6; i++)
	{
		adj[arr[i][0]].push_back(arr[i][1]);
	}

	//BFS Traversal
	cout << "BFS Traversal : ";
	vector<bool> visited(8, false);
	int s = 1;
	queue<int> _queue;
	visited[s] = true;
	_queue.push(s);
	while (false == _queue.empty())
	{
		s = _queue.front();
		cout << _queue.front();
		_queue.pop();
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				_queue.push(*i);
			}
		}
	}

	cout << "\nDFS Traversal : ";
	visited.clear();
	visited.resize(8, false);
	stack<int> store;
	s = 1;
	store.push(s);
	while (false == store.empty())
	{
		s = store.top();
		cout << s;
		store.pop();
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				store.push(*i);
			}
		}
	}
	cout << endl;
}

// MST Findings
void Prim()
{

}

void Kruksal()
{

}

//Single Source shortest path
void Dijkstra()
{

}

int dleft[4] = {0,1,0,-1};
int dright[4] = {-1,0,1,0};
bool IsValid(int row, int col)
{
	if (row < 0 || row >= 4)
		return false;
	if (col < 0 || col >= 4)
		return false;
	return true;
}

//BFS of 2d Array
void MatrixBFS()
{
	cout << "BFS Traversal of matrix : " << endl;
	int grid[][4] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };

	queue<pair<int, int>> store;
	vector<vector<bool>> visited(4,vector<bool>(4,false));

	store.push(pair<int, int> (0, 0));
	visited[0][0] = true;

	while (!store.empty())
	{
		auto x = store.front();
		int lrow = x.first;
		int lcol = x.second;
		cout << grid[lrow][lcol] << " ";
		store.pop();
		for (int i = 0; i < 4; i++)
		{
			int newx = lrow + dleft[i];
			int newy = lcol + dright[i];
			if (false != IsValid(newx, newy))
			{
				if (false == visited[newx][newy])
				{
					store.push(pair<int, int>(newx, newy));
					visited[newx][newy] = true;
				}
			}
		}
	}
}

//DFS of 2d Array
void MatrixDFS()
{
	cout << "\nDFS Traversal of matrix : " << endl;
	int grid[][4] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };


	stack<pair<int, int>> store;
	vector<vector<bool>> visited(4, vector<bool>(4, false));
	store.push(pair<int, int>(0, 0));

	while (!store.empty())
	{
		auto x = store.top();
		int lrow = x.first;
		int lcol = x.second;
		store.pop();

		if (true == IsValid(lrow,lcol) && visited[lrow][lcol] == false)
		{
			cout << grid[lrow][lcol] << " " ;
			visited[lrow][lcol] = true;
		}
		else
			continue;

		for (int i = 0; i < 4; i++)
		{
			int newx = lrow + dleft[i];
			int newy = lcol + dright[i];
			store.push(pair<int, int>(newx, newy));
		}
	}
}

/*//to create a vector<vector<int>> of uniform format
vector<vector<int>> graph;
for (int i = 0; i < V; i++)
{
	vector<int> temp;
	for (int j = 0; j < 2; j++)
	{
		temp.push_back(arr[i][j]);
	}
	graph.push_back(temp);
}*/