#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

static vector<vector<long>> dis;

int main()
{
	int city, notion;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> city >> notion;
	
	dis.assign(city + 1, vector<long>(city + 1, MAX));

	for (int i = 1; i <= city; i++)
	{
		dis[i][i] = 0;
	}

	for (int i = 0; i < notion; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;

		if (dis[s][e] > t) {
			dis[s][e] = t;
		}
	}

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
			{
				if (dis[j][k] > dis[j][i] + dis[i][k])
				{
					dis[j][k] = dis[j][i] + dis[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			if (dis[i][j] == MAX)
			{
				cout << "0 ";
			}
			else
			{
				cout << dis[i][j] << " ";
			}
		}
		cout << "\n";
	}

	cout.flush();
	return 0;
}