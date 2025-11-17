#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int node, edge, start;
static vector<bool> visited;
static vector<int> dfs, bfs;
static vector<vector<int>> graph;

void Dfs(int start);
void Bfs(int start);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge >> start;

	graph.resize(node + 1);
	visited.assign(node, false);

	for (int i = 0; i < edge; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i <= node; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	Dfs(start);
	visited.assign(node, false);
	Bfs(start);

	for (int i = 0; i < dfs.size(); i++)
	{
		cout << dfs[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < bfs.size(); i++)
	{
		cout << bfs[i] << " ";
	}
	cout.flush();

	return 0;
}

void Dfs(int start)
{
	visited[start - 1] = true;
	dfs.push_back(start);

	for (int i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i] - 1]) 
		{
			Dfs(graph[start][i]);
		}
	}
}

void Bfs(int start)
{
	queue<int> data;

	data.push(start);
	visited[start - 1] = true;
	bfs.push_back(start);

	while (!data.empty())
	{
		int root = data.front();
		data.pop();

		for (int i = 0; i < graph[root].size(); i++)
		{
			if (!visited[graph[root][i] - 1]) 
			{
				data.push(graph[root][i]);
				visited[graph[root][i] - 1] = true;
				bfs.push_back(graph[root][i]);
			}
		}
	}
}
