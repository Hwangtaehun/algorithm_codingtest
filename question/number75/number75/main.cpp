#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

static vector<long> tree;
static vector<long> result;

void setTree(int i);
long getMin(int s, int e);

int main()
{
	int N, M, Length, treeSize, leftNodeStartIndex, treeHeight = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	Length = N;

	while (Length != 0)
	{
		Length /= 2;
		treeHeight++;
	}

	treeSize = int(pow(2, treeHeight + 1));
	leftNodeStartIndex = treeSize / 2 - 1;

	tree.assign(treeSize, LONG_MAX);

	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
	{
		cin >> tree[i];
	}

	setTree(treeSize - 1);

	for (int i = 0; i < M; i++)
	{
		long s, e;
		cin >> s >> e;
		s += leftNodeStartIndex;
		e += leftNodeStartIndex;
		result.push_back(getMin(s, e));
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();

	return 0;
}

void setTree(int i)
{
	while (i != 1)
	{
		if (tree[i / 2] > tree[i])
		{
			tree[i / 2] = tree[i];
		}
		i--;
	}
}

long getMin(int s, int e)
{
	long Min = LONG_MAX;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			Min = min(Min, tree[s]);
			s++;
		}
		s /= 2;

		if (e % 2 == 0)
		{
			Min = min(Min, tree[e]);
			e--;
		}
		e /= 2;
	}

	return Min;
}
