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

static vector<int> parent;
void munion(int a, int b);
int find(int a);

int main()
{
	int node, edge, useEdge = 0, result = 0;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	parent.resize(node + 1);

	for (int i = 0; i <= node; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < edge; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge{ s, e, v });
	}

	while (useEdge < node - 1)
	{
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e))
		{
			munion(now.s, now.e);
			result = result + now.v;
			useEdge++;
		}
	}

	cout << result;
	cout.flush();
	return 0;
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
