#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;
vector<bool> result;

void unionfuc(int a, int b);
void check(int a, int b);
int find(int n);

int main()
{
	int cnt, aws;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt >> aws;
	graph.resize(cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		graph[i] = i;
	}

	for (int i = 0; i < aws; i++)
	{
		int a, s, e;
		cin >> a >> s >> e;

		if (a == 0)
		{
			unionfuc(s, e);
		}
		else
		{
			check(s, e);
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

void unionfuc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		graph[b] = a;
	}
}

void check(int a, int b)
{
	if (find(a) == find(b))
	{
		result.push_back(true);
	}
	else
	{
		result.push_back(false);
	}
}

int find(int n)
{
	if (graph[n] == n) 
	{
		return n;
	}
	else
	{
		return graph[n] = find(graph[n]);
	}
}
