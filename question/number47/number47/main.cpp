#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

long lcm;
vector<int> storage;
vector<bool> visited;
vector<vector<tuple<int, int, int>>> values;

int gcd(long a, long b);
void dfs(int node);

int main()
{
	int cnt;
	long mgcd;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	values.resize(cnt);
	storage.resize(cnt);
	visited.resize(cnt);
	lcm = 1;

	for (int i = 0; i < cnt - 1; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		values[a].push_back(make_tuple(b, p, q));
		values[b].push_back(make_tuple(a, p, q));

		lcm *= (p * q / gcd(p, q));
	}

	storage[0] = lcm;
	dfs(0);
	mgcd = storage[0];

	for (int i = 1; i < cnt; i++)
	{
		mgcd = gcd(mgcd, storage[i]);
	}

	for (int i = 0; i < cnt; i++)
	{
		cout << storage[i] / mgcd << " ";
	}
	cout.flush();

	return 0;
}

int gcd(long a, long b)
{
	if (b == 0) 
	{
		return a;
	}
	else
	{
		gcd(b, a % b);
	}
}

void dfs(int node)
{
	visited[node] = true;

	for (tuple<int, int, int> i : values[node])
	{
		int next = get<0>(i);
		
		if (!visited[next])
		{
			storage[next] = storage[node] * get<2>(i) / get<1>(i);
			dfs(next);
		}
	}
}
