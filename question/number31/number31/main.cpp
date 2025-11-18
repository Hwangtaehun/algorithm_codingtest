#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<pair<int, int>>> graph;
static vector<bool> visited;
static vector<int> value;

void bfs(int node);

int main()
{
	int node, max = 1;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node;
	graph.resize(node + 1);
	value.assign(node + 1, 0);
	visited.assign(node + 1, false);
	visited[0] = true;

	for (int i = 0; i < node; i++)
	{
		int s;
		cin >> s;

		while (true)
		{
			int n, p;
			cin >> n;

			if (n == -1)
			{
				break;
			}

			cin >> p;

			graph[s].push_back({ n, p });
		}
	}

	bfs(1);
	for (int i = 2; i <= node; i++)
	{
		if (value[max] < value[i])
		{
			max = i;
		}
	}

	fill(value.begin(), value.end(), 0);
	fill(visited.begin(), visited.end(), false);

	bfs(max);
	sort(value.begin(), value.end());

	cout << value[node];
	cout.flush();

	return 0;
}

void bfs(int node)
{
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;

	while (!myqueue.empty()) {
		int start = myqueue.front();
		myqueue.pop();

		for (int i = 0; i < graph[start].size(); i++)
		{
			int goal = graph[start][i].first;
			if (!visited[goal]) {
				visited[goal] = true;
				myqueue.push(goal);
				value[goal] = value[start] + graph[start][i].second;
			}
		}
	}
}
