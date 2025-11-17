#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define SIZE 4

using namespace std;

static int n, m;
static vector<vector<int>> maze;
static vector<vector<bool>> visited;
static int dx[SIZE] = { 1, 0, -1, 0 };
static int dy[SIZE] = { 0, 1, 0, -1 };

bool check(pair<int, int> xy);
void bfs(int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	maze.assign(n + 1, vector<int>(m + 1, 0));
	visited.assign(n + 1, vector<bool>(m + 1, false));

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= str.length(); j++)
		{
			maze[i][j] = str[j - 1] - '0';
			if (maze[i][j] == 0) {
				visited[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		if (!visited[1][i])
		{
			bfs(1, i);
			break;
		}
	}

	cout << maze[n][m];
	cout.flush();

	return 0;
}

bool check(pair<int, int> xy)
{
	int x = xy.first, y = xy.second;

	if (x < 1 || x > n)
		return false;

	if (y < 1 || y > m)
		return false;

	if (visited[x][y])
		return false;

	return true;
}

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	visited[x][y] = true;

	while (!que.empty()) 
	{
		pair<int, int> temp1 = que.front();
		que.pop();

		for (int i = 0; i < SIZE; i++)
		{
			pair<int, int> temp2 = temp1;
			temp2.first += dx[i];
			temp2.second += dy[i];

			if (check(temp2)) {
				que.push(temp2);
				visited[temp2.first][temp2.second] = true;
				maze[temp2.first][temp2.second] = maze[temp1.first][temp1.second] + 1;
			}
		}
	}
}