#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int kind;
	queue<int> sequence;
	vector<vector<int>> graph;
	vector<int> result, grade, build;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> kind;

	graph.resize(kind + 1);
	grade.resize(kind + 1);
	build.resize(kind + 1);
	result.resize(kind + 1);

	for (int i = 1; i <= kind; i++)
	{
		int degree = 0;
		while (true)
		{
			int num;
			cin >> num;
			
			if (num == -1)
			{
				grade[i] = degree - 1;
				break;
			}

			if (degree == 0)
			{
				build[i] = num;
			}
			else
			{
				graph[num].push_back(i);
			}

			degree++;
		}
	}

	for (int i = 1; i <= kind; i++)
	{
		if (grade[i] == 0)
		{
			sequence.push(i);
		}
	}

	while (!sequence.empty())
	{
		int s = sequence.front();
		sequence.pop();

		for (int i = 0; i < graph[s].size(); i++)
		{
			int e = graph[s][i];
			grade[e]--;
			result[e] = max(result[s] + build[s], result[e]);
			
			if (grade[e] == 0)
			{
				sequence.push(e);
			}
		}
	}

	for (int i = 1; i <= kind; i++)
	{
		cout << result[i] + build[i] << "\n";
	}
	cout.flush();

	return 0;
}