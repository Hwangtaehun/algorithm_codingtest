#include <iostream>
#include <vector>

using namespace std;

static vector<int> parent;
static vector<vector<int>> city;

int find(int n);
void unionfun(int a, int b);

int main()
{
	bool result = true;
	int cnt, trip, idx;
	vector<int> route;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt >> trip;
	parent.resize(cnt + 1);
	city.resize(cnt + 1, vector<int>(cnt + 1));
	route.resize(trip);

	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= cnt; j++)
		{
			cin >> city[i][j];
		}
		parent[i] = i;
	}

	for (int i = 0; i < trip; i++)
	{
		cin >> route[i];
	}

	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= cnt; j++)
		{
			if (city[i][j] == 1) {
				unionfun(i, j);
			}
		}
	}

	idx = find(route[0]);

	for (int i = 1; i < trip; i++)
	{
		if (idx != find(route[i])) {
			result = false;
		}
	}

	if (result)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout.flush();

	return 0;
}

int find(int n)
{
	if (parent[n] == n)
	{
		return n;
	}
	else
	{
		return parent[n] = find(parent[n]);
	}
}

void unionfun(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		parent[b] = a;
	}
}