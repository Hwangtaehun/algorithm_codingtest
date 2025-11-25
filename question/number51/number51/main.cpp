#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> list;
static vector<bool> visited, result;
static vector<int> check;
static bool iseven;
void dfs(int node);

int main()
{
	int tcase;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tcase;

	for (int i = 0; i < tcase; i++)
	{
		int v, e;
		cin >> v >> e;
		list.resize(v + 1);
		visited.assign(v + 1, false);
		check.resize(v + 1);
		iseven = true;

		for (int i = 0; i < e; i++)
		{
			int start, end;
			cin >> start >> end;
			list[start].push_back(end);
			list[end].push_back(start);
		}

		for (int i = 0; i <= v; i++)
		{
			if (iseven)
			{
				dfs(i);
			}
			else
			{
				break;
			}
		}

		result.push_back(iseven);

		for (int i = 0; i <= v; i++)
		{
			list[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	cout.flush();

	return 0;
}

void dfs(int node)
{
	visited[node] = true;

	for (int i : list[node])
	{
		if (!visited[i])
		{
			check[i] = (check[node] + 1) % 2;
			dfs(i);
		}
		else if (check[node] == check[i])
		{
			iseven = true;
		}
	}
}
