#include <iostream>
#include <vector>

using namespace std;

static bool arrive;
static vector<bool> visited;
static vector<vector<int>> graph;
void dfs(int now, int dept);

int main()
{
	int node, edge;
	arrive = false;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge;
	graph.resize(node);
	visited.assign(node, false);

	for (int i = 0; i < edge; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i < node; i++) {
		dfs(i, 1);

		if (arrive) {
			break;
		}
	}

	if (arrive)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	cout.flush();

	return 0;
}

void dfs(int now, int dept)
{
	if (dept == 5 || arrive) {
		arrive = true;
		return;
	}

	visited[now] = true;

	for (int i = 0; i < graph[now].size(); i++)
	{
		if (!visited[graph[now][i]]) {
			dfs(graph[now][i], dept + 1);
		}
	}

	visited[now] = false;
}
