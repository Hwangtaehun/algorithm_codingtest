#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<int> parents;
static vector<bool> visited;
static vector<vector<int>> tree;

void DFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node;
	cin >> node;

	tree.resize(node + 1);
	parents.resize(node + 1);
	visited.assign(node + 1, false);

	for (int i = 1; i < node; i++)
	{
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	
	// 코딩 테스트 디버깅
	/*for (int i = 1; i <= node; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < tree[i].size(); j++)
		{
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}*/

	DFS(1);

	for (int i = 2; i < parents.size(); i++)
	{
		cout << parents[i] << "\n";
	}

	return 0;
}

void DFS(int num)
{
	visited[num] = true;

	for (int i = 0; i < tree[num].size(); i++)
	{
		int child = tree[num][i];
		
		if (!visited[child])
		{
			parents[child] = num;
			DFS(child);
		}
	}
}
