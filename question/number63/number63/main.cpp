#include <iostream>
#include <vector>
#include <limits>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;
static int node, cnt, scity, ecity;
static vector<edge> edges;
static vector<long> dis, income;

int main()
{
	int money = 0;
	bool bCircle = false;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> scity >> ecity >> cnt;

	income.resize(node);
	dis.assign(node, LONG_MIN);

	for (int i = 0; i < cnt; i++)
	{
		long s, e, m;
		cin >> s >> e >> m;
		edges.push_back(make_tuple(s, e, m));
	}

	for (int i = 0; i < node; i++)
	{
		long n;
		cin >> n;
		income[i] = n;
	}

	dis[0] = income[0];

	for (int i = 1; i <= node + 50; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			long s, e, c;
			edge data = edges[j];
			s = get<0>(data);
			e = get<1>(data);
			c = get<2>(data);

			if (dis[s] == LONG_MIN)
			{
				continue;
			}
			else if (dis[s] == LONG_MAX)
			{
				dis[e] = LONG_MAX;
			}
			else if (dis[e] < dis[s] + income[e] - c)
			{
				dis[e] = dis[s] + income[e] - c;

				if (i > node - 1)
				{
					dis[e] = LONG_MAX;
				}
			}
		}
	}

	if (dis[ecity] == LONG_MIN)
	{
		cout << "gg";
	}
	else if (dis[ecity] == LONG_MAX)
	{
		cout << "Gee";
	}
	else
	{
		cout << dis[ecity];
	}
	cout.flush();

	return 0;
}