#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;
long getSum(int s, int e);
void setTree(int i);
void chagenVal(int index, long val);

int main()
{
	int N, M, K, Length, treeHeight = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	Length = N;

	while (Length != 0)
	{
		Length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize);

	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
	{
		cin >> tree[i];
	}
	setTree(treeSize - 1);

	for (int i = 0; i < M + K; i++)
	{
		long a, s, e;
		cin >> a >> s >> e;

		if (a == 1)
		{
			changeVal(leftNodeStartIndex + s, e);
		}
	}

	return 0;
}

long getSum(int s, int e)
{
	return 0;
}

void changeVal(int index, long val)
{
}

void setTree(int i)
{
}
