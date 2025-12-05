#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

static int sNum;
static int dr[] = { -1, 0, 1, 0 };
static int dc[] = { 0, 1, 0, -1 };
static vector<int> parent;
static vector<vector<int>> map;
static vector<vector<bool>> visited;
static vector<pair<int, int>> mlist;
static vector<vector<pair<int, int>>> sumlist;
static priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int find(int a);
void BFS(int i, int j);
void munion(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, useEdge = 0, result = 0;
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	sNum = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0 && visited[i][j] != true)
			{
				BFS(i, j);
				sNum++;
				sumlist.push_back(mlist);
			}
		}
	}

	for (int i = 0; i < sumlist.size(); i++)
	{
		vector<pair<int, int>> now = sumlist[i];

		for (int j = 0; j < now.size(); j++)
		{
			int r = now[j].first;
			int c = now[j].second;
			int now_S = map[r][c];

			for (int d = 0; d < 4; d++)
			{
				int tempR = dr[d], tempC = dc[d], blength = 0;

				while (r + tempR >= 0 && r + tempR < n && c + tempC >= 0 && c + tempC < m)
				{
					if (map[r + tempR][c + tempC] == now_S) {
						break;
					}
					else if (map[r + tempR][c + tempC] != 0)
					{
						if (blength > 1)
						{
							pq.push(Edge{ now_S, map[r + tempR][c + tempC], blength });
						}
						break;
					}
					else
					{
						blength++;
					}

					if (tempR < 0)
					{
						tempR--;
					}
					else if (tempR > 0)
					{
						tempR++;
					}
					else if (tempC < 0)
					{
						tempC--;
					}
					else if (tempC > 0)
					{
						tempC++;
					}
				}
			}
		}
	}

	parent.resize(sNum);

	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e))
		{
			munion(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	if (useEdge == sNum - 2)
	{
		cout << result << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}

	cout.flush();

	return 0;
}

int find(int a)
{
	if (a == parent[a]) 
	{
		return a;
	}
	else
	{
		return parent[a] = find(parent[a]);
	}

}

void BFS(int i, int j)
{
	int n, m;
	n = map.size();
	m = map[0].size();
	queue<pair<int, int>> myqueue;
	mlist.clear();
	myqueue.push(make_pair(i, j));
	mlist.push_back(make_pair(i, j));
	visited[i][j] = true;
	map[i][j] = sNum;

	while (!myqueue.empty())
	{
		int r = myqueue.front().first;
		int c = myqueue.front().second;
		myqueue.pop();

		for (int d = 0; d < 4; d++)
		{
			int tempR = dr[d];
			int tempC = dc[d];

			while (r + tempR >= 0 && r + tempR < n && c + tempC >= 0 && c + tempC < m)
			{
				if (visited[r + tempR][c + tempC] == false && map[r + tempR][c + tempC] != 0)
				{
					int now_i = r + tempR;
					int now_j = c + tempC;
					map[now_i][now_j] = sNum;
					visited[now_i][now_j] = true;
					mlist.push_back(make_pair(now_i, now_j));
					myqueue.push(make_pair(now_i, now_j));
				}
				else
				{
					break;
				}

				if (tempR < 0)
				{
					tempR--;
				}
				else if (tempR > 0)
				{
					tempR++;
				}
				else if (tempC < 0)
				{
					tempC--;
				}
				else if (tempC > 0)
				{
					tempC++;
				}
			}
		}
	}
}

void munion(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		parent[b] = a;
	}
}
