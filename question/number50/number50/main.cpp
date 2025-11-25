#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> list;
static vector<bool> visited;
static vector<int> answer;

void bfs(int node);

int main()
{
	int size, trust, m_max = 0;
	cin >> size >> trust;
	list.resize(size + 1);
	answer.resize(size + 1);
	visited.resize(size + 1);

	for (int i = 0; i < trust; i++)
	{
		int s, e;
		cin >> s >> e;
		list[s].push_back(e);
	}

	for (int i = 1; i <= size; i++)
	{
		fill(visited.begin(), visited.end(), false);
		bfs(i);
	}

	for (int i = 0; i <= size; i++)
	{
		m_max = max(m_max, answer[i]);
	}

	for (int i = 0; i <= size; i++)
	{
		if (answer[i] == m_max)
		{
			cout << i << ' ';
		}
	}
	cout.flush();

	return 0;
}

void bfs(int node)
{
	queue<int> queue;
	queue.push(node);
	visited[node] = true;

	while (!queue.empty())
	{
		int now_node = queue.front();
		queue.pop();

		for (int i : list[now_node])
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				queue.push(i);
				answer[i]++;
			}
		}
	}
}
