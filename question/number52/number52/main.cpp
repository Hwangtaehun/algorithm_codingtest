#include<iostream>
#include<queue>
#define SIZE 201

using namespace std;

static int sed[] = { 0, 0, 1, 1, 2, 2 };
static int rev[] = { 1, 2, 0, 2, 0, 1 };
static bool visited[SIZE][SIZE];
static bool answer[SIZE];
static int now[3];

void bfs();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> now[0] >> now[1] >> now[2];
	
	bfs();

	for (int i = 0; i < 201; i++)
	{
		if (answer[i])
		{
			cout << i << ' ';
		}
	}
	cout.flush();
	return 0;
}

void bfs()
{
	queue<pair<int, int>> queue;
	queue.push(make_pair(0, 0));
	visited[0][0] = true;
	answer[now[2]] = true;

	while (!queue.empty())
	{
		int a, b, c;
		pair<int, int> p = queue.front();
		a = p.first;
		b = p.second;
		c = now[2] - a - b;

		for (int k = 0; k < 6; k++)
		{
			int next[] = { a, b, c };
			next[rev[k]] += next[sed[k]];
			next[sed[k]] = 0;

			if (next[rev[k]] > now[rev[k]])
			{
				next[sed[k]] = next[rev[k]] - now[rev[k]];
				next[rev[k]] = now[rev[k]];
			}

			if (!visited[next[0]][next[1]])
			{
				visited[next[0]][next[1]] = true;
				queue.push(make_pair(next[0], next[1]));

				if (next[0] == 0)
				{
					answer[next[2]] = true;
				}
			}
		}
	}
}
