#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int node, edge;
	queue<int> seq;
	vector<int> grade, result;
	vector<vector<int>> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> node >> edge;
	data.resize(node + 1);
	grade.assign(node + 1, 0);

	for (int i = 0; i < edge; i++)
	{
		int n, m;
		cin >> n >> m;
		data[n].push_back(m);
		grade[m]++;
	}

	for (int i = 1; i <= node; i++)
	{
		if (grade[i] == 0)
		{
			seq.push(i);
		}
	}

	while (!seq.empty())
	{
		int n = seq.front();
		seq.pop();
		result.push_back(n);

		for (int i = 0; i < data[n].size(); i++)
		{
			grade[data[n][i]]--;
			if (grade[data[n][i]] == 0)
			{
				seq.push(data[n][i]);
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	cout.flush();
	return 0;
}