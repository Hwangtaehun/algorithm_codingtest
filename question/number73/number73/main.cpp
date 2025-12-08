#include <iostream>
#include <vector>

using namespace std;

static int n;
static vector<string> result(3);
static vector<vector<int>> tree;

void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main()
{
	int cnt;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	tree.resize(cnt, vector<int>(2));

	for (int i = 0; i < cnt; i++)
	{
		int n;
		char p, l, r;
		cin >> p >> l >> r;

		n = p - 'A';
	
		if (l == '.') {
			tree[n][0] = -1;
		} else
		{
			tree[n][0] = l - 'A';
		}

		if (r == '.') {
			tree[n][1] = -1;
		} else {
			tree[n][1] = r - 'A';
		}
	}

	preOrder(0);
	inOrder(0);
	postOrder(0);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();
	return 0;
}

void preOrder(int now)
{
	if (now == -1) {
		return;
	}

	result[0] += (now + 'A');
	preOrder(tree[now][0]);
	preOrder(tree[now][1]);
}

void inOrder(int now)
{
	if (now == -1) {
		return;
	}

	inOrder(tree[now][0]);
	result[1] += (now + 'A');
	inOrder(tree[now][1]);
}

void postOrder(int now)
{
	if (now == -1) {
		return;
	}

	postOrder(tree[now][0]);
	postOrder(tree[now][1]);
	result[2] += (now + 'A');
}
