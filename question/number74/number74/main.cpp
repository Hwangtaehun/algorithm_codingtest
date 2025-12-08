#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;
long getSum(int s, int e);
void setTree(int i);
void changeVal(int index, long val);

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
		else if (a == 2)
		{
			s += leftNodeStartIndex;
			e += leftNodeStartIndex;
			cout << getSum(s, e) << "\n";
		}
	}

	return 0;
}

long getSum(int s, int e)
{
	long partSum = 0;

	while (s <= e)
	{
		if (s % 2 == 1) {
			partSum += tree[s];
			s++;
		}

		if (e % 2 == 0) {
			partSum += tree[e];
			e--;
		}

		s /= 2;
		e /= 2;
	}
	return partSum;
}

void changeVal(int index, long val)
{
	long diff = val - tree[index];

	while (index > 0)
	{
		tree[index] += diff;
		index /= 2;
	}
}

void setTree(int i)
{
	while (i != 1)
	{
		tree[i / 2] += tree[i];
		i--;
	}
}
