#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> line;
static int node, edge, start;
static vector<int> dis;
static vector<bool> visited;
static vector<vector<line>> graph;
static priority_queue<line, vector<line>, greater<line>> myqueue;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge >> start;
	dis.assign(node + 1, INT_MAX);
	visited.assign(node + 1, false);
	graph.resize(node + 1);

	for (int i = 0; i < edge; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		graph[s].push_back(make_pair(e, v));
	}

	myqueue.push(make_pair(0, start));
	dis[start] = 0;

	while (!myqueue.empty())
	{
		int now;
		line cur = myqueue.top();
		
		myqueue.pop();
		now = cur.second;

		if (visited[now])
		{
			continue;
		}

		visited[now] = true;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next, value;
			line temp = graph[now][i];
			next = temp.first;
			value = temp.second;

			if (dis[next] > dis[now] + value)
			{
				dis[next] = value + dis[now];
				myqueue.push(make_pair(dis[next], next));
			}
		}
	}

	for (int i = 1; i <= node; i++)
	{
		if (visited[i])
		{
			cout << dis[i] << "\n";
		}
		else
		{
			cout << "INF\n";
		}
	}
	cout.flush();

	return 0;
}