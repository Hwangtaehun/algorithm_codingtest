#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> list;
static vector<int> visited, answer;
void bfs(int node);

int main()
{
	int city, road, dis, start;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> city >> road >> dis >> start;
	list.resize(city + 1);
	visited.assign(city + 1, -1);

	for (int i = 0; i < road; i++)
	{
		int s, e;
		cin >> s >> e;
		list[s].push_back(e);
	}

	bfs(start);

	for (int i = 0; i <= city; i++)
	{
		if (visited[i] == dis) {
			answer.push_back(i);
		}
	}

	if (answer.empty()) 
	{
		cout << "-1";
	}
	else
	{
		sort(answer.begin(), answer.end());

		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << ' ';
		}
	}
	
	cout.flush();

	return 0;
}

void bfs(int node)
{
	queue<int> queue;
	queue.push(node);
	visited[node]++;

	while (!queue.empty())
	{
		int now_node = queue.front();
		queue.pop();

		for (int i = 0; i < list[now_node].size(); i++)
		{
			int n = list[now_node][i];
			if (visited[n] == -1)
			{
				visited[n] = visited[now_node] + 1;
				queue.push(n);
			}
		}
	}
}
