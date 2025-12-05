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

int find(int a);
void munion(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, sum = 0, useEdge = 0, result = 0;
	cin >> N;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			char tempc = cin.get();

			if (tempc == '\n') {
				tempc = cin.get();
			}

			if (tempc >= 'a' && tempc <= 'z')
			{
				temp = tempc - 'a' + 1;
			}
			else if (tempc >= 'A' && tempc <= 'Z')
			{
				temp = tempc - 'A' + 27;
			}
			
			sum += temp;

			if (i != j && temp != 0)
			{
				pq.push(Edge{ i, j, temp });
			}
		}
	}

	parent.resize(N);

	for (int i = 0; i < N; i++)
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

	if (useEdge == N - 1)
	{
		cout << sum - result << "\n";
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

void munion(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}
