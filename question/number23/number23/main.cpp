#include <iostream>
#include <vector>

using namespace std;

static vector<bool> visited;
static vector<vector<int>> graph;

void BNF(int v);

int main()
{
	int node, edge, cnt = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge;

	graph.resize(node + 1);
	visited.assign(node + 1, false);

	for (int i = 0; i < edge; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i < graph.size(); i++) {
		if (!visited[i]) {
			BNF(i);
			cnt++;
		}
	}

	cout << cnt;
	cout.flush();

	return 0;
}

void BNF(int v)
{
	if (visited[v])
	{
		return;
	}

	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++)
	{
		if (!visited[graph[v][i]])
		{
			BNF(graph[v][i]);
		}
	}
}