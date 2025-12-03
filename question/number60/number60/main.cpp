#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> edge;
static int city, bus;
static vector<int> dis;
static vector<bool> visited;
static vector<vector<edge>> list;

int dijkstra(int start, int end);

int main()
{
	int start, end, result;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> city >> bus;
	dis.assign(city + 1, INT_MAX);
	visited.assign(city + 1, false);
	list.resize(city + 1);

	for (int i = 0; i < bus; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		list[s].push_back(make_pair(e, v));
	}

	cin >> start >> end;
	result = dijkstra(start, end);
	cout << result;
	cout.flush();

	return 0;
}

int dijkstra(int start, int end)
{
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	pq.push(make_pair(0, start));
	dis[start] = 0;

	while (!pq.empty())
	{
		int now;
		now = pq.top().second;
		pq.pop();

		if (!visited[now])
		{
			visited[now] = true;

			for (int i = 0; i < list[now].size(); i++)
			{
				int next, value;
				next = list[now][i].first;
				value = list[now][i].second;

				if (dis[next] > dis[now] + value)
				{
					dis[next] = dis[now] + value;
					pq.push(make_pair(dis[next], next));
				}
			}
		}
	}

	return dis[end];
}
