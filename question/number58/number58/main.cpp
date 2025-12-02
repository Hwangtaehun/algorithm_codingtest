#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int citys, roads, start, end, cnt = 0;
	queue<int> myqueue;
	vector<bool> visited;
	vector<int> grade, result;
	vector<vector<pair<int, int>>> data, reverse;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> citys >> roads;
	data.resize(citys + 1);
	grade.resize(citys + 1);
	result.resize(citys + 1);
	reverse.resize(citys + 1);
	visited.resize(citys + 1);

	for (int i = 0; i < roads; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		data[s].push_back({ e, v });
		reverse[e].push_back({ s, v });
		grade[e]++;
	}

	cin >> start >> end;

	for (int i = 1; i <= citys; i++)
	{
		if (grade[i] == 0)
		{
			myqueue.push(i);
		}
	}

	while (!myqueue.empty())
	{
		int now = myqueue.front();
		myqueue.pop();

		for (int i = 0; i < data[now].size(); i++)
		{
			int next, value;
			next = data[now][i].first;
			value = data[now][i].second;
			grade[next]--;
			result[next] = max(result[next], result[now] + value);

			if (grade[next] == 0)
			{
				myqueue.push(next);
			}
		}
	}

	visited[end] = true;
	myqueue.push(end);

	while (!myqueue.empty())
	{
		int now = myqueue.front();
		myqueue.pop();

		for (int i = 0; i < reverse[now].size(); i++)
		{
			int next, value;
			next = reverse[now][i].first;
			value = reverse[now][i].second;

			if (result[next] + value == result[now])
			{
				cnt++;

				if (visited[next] == false)
				{
					visited[next] = true;
					myqueue.push(next);
				}
			}
		}
	}

	cout << result[end] << "\n";
	cout << cnt;
	cout.flush();

	return 0;
}