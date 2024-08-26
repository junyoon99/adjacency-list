#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<vector<int>>& adjList, vector<bool>& visited) 
{
	visited[node] = true;

	for (const auto& neighbor : adjList[node]) 
	{
		if (!visited[neighbor]) 
		{
			DFS(neighbor, adjList, visited);
		}
	}
}

int CountComponents(int n, vector< vector<int> >& edges) 
{
	// adjacency list
	vector<vector<int>> adjList(n);
	for (auto& edge : edges) 
	{
		int u = edge[0];
		int v = edge[1];

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	vector<bool> visited(n, false);
	int count{};
	for (int i{}; i < n; i++) 
	{
		if (!visited[i]) 
		{
			DFS(i, adjList, visited);
			count++;
		}
	}

	return count;
}

int main() 
{
	vector<vector<int>> e1 = { {0,1}, {2,3}, {1,2}, {3,4} };
	cout << CountComponents(5, e1);
}