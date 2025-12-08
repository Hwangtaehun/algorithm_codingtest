#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007

using namespace std;

static vector<long> tree;

long getMul(int s, int e);
void setTree(int i);
void changeVal(int index, long val);

int main()
{
	vector<long> result;
	int N, M, K, Length, treeSize, leftNodeStartIndex, treeHeight = 0;

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

	treeSize = int(pow(2, treeHeight + 1));
	leftNodeStartIndex = treeSize / 2 - 1;
	tree.assign(treeSize, 1);

	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
	{
		cin >> tree[i];
	}
	setTree(treeSize - 1);

	for (int i = 0; i < M + K; i++)
	{
		long a, s, e;
		cin >> a >> s >> e;

		if (a == 1) {
			changeVal(leftNodeStartIndex + s, e);
		}
		else if (a == 2) {
			s += leftNodeStartIndex;
			e += leftNodeStartIndex;
			result.push_back(getMul(s, e));
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();
	return 0;
}

long getMul(int s, int e)
{
	long partMul = 1;

	while (s <= e)
	{
		if (s % 2 == 1) 
		{
			partMul = partMul * tree[s] % MOD;
			s++;
		}

		if (e % 2 == 0)
		{
			partMul = partMul * tree[e] % MOD;
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return partMul;
}

void changeVal(int index, long val)
{
	tree[index] = val;

	while (index > 1)
	{
		index /= 2;
		tree[index] = tree[index * 2] % MOD * tree[index * 2 + 1] % MOD;
	}
}

void setTree(int i)
{
	while (i != 1)
	{
		tree[i / 2] *= tree[i] % MOD;
		i--;
	}
}
