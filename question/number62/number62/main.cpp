#include <iostream>
#include <limits>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;
static int n, e;
static vector<long> dis;
static vector<edge> edges;

int main()
{
	bool circle = false;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> e;
	dis.assign(n + 1, LONG_MAX);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}

	dis[1] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < e; j++)
		{
			edge data = edges[j];
			int s, f, t;
			s = get<0>(data);
			f = get<1>(data);
			t = get<2>(data);

			if (dis[s] != LONG_MAX && dis[f] > dis[s] + t)
			{
				dis[f] = dis[s] + t;
			}
		}
	}

	for (int i = 0; i < e; i++)
	{
		edge data = edges[i];
		int s, f, t;
		s = get<0>(data);
		f = get<1>(data);
		t = get<2>(data);

		if (dis[s] != LONG_MAX && dis[f] > dis[s] + t)
		{
			circle = true;
		}
	}

	if (circle)
	{
		cout << "-1";
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dis[i] == LONG_MAX)
			{
				cout << "-1\n";
			}
			else
			{
				cout << dis[i] << "\n";
			}
		}
	}

	cout.flush();
	return 0;
}