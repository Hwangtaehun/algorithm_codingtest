#include <iostream>
#include <vector>

using namespace std;

static int del, answer = 0, deleteNode = 0;
static vector<bool> visited;
static vector<vector<int>> tree;

void DFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node, root = 0;

	cin >> node;
	tree.resize(node);
	visited.assign(node, false);

	for (int i = 0; i < node; i++)
	{
		int num;
		cin >> num;

		if (num == -1)
		{
			root = i;
		}
		else
		{
			tree[i].push_back(num);
			tree[num].push_back(i);
		}
	}

	cin >> deleteNode;

	if (deleteNode == root) {
		cout << "0";
	}
	else
	{
		DFS(root);
		cout << answer;
	}
	cout.flush();
	
	return 0;
}

void DFS(int num)
{
	int cNode = 0;
	visited[num] = true;

	for (int i = 0; i < tree[num].size(); i++)
	{
		int child = tree[num][i];
		if (visited[child] == false && child != deleteNode) {
			cNode++;
			DFS(child);
		}
	}

	if (cNode == 0) {
		answer++;
	}
}
