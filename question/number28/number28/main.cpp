#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

static int g_data[10][10];
static int paper[6] = { 0, 5, 5, 5, 5, 5 };
static int result = INT_MAX;

bool check(int x, int y, int size);
void backtracking(int xy, int cnt);
void fill(int x, int y, int size, int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> g_data[i][j];
		}
	}

	backtracking(0, 0);

	if (result == INT_MAX) {
		result = -1;
	}

	cout << result << "\n";
	cout.flush();

	return 0;
}

bool check(int x, int y, int size)
{
	if (x + size > 10 || y + size > 10)
		return false;

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (g_data[i][j] != 1)
				return false;
		}
	}

	return true;
}

void backtracking(int xy, int cnt)
{
	if (xy == 100) {
		result = min(result, cnt);
		return;
	}

	int x = xy % 10;
	int y = xy / 10;

	if (result <= cnt)
		return;

	if (g_data[y][x] == 1) 
	{
		for (int i = 5; i >= 1; i--)
		{
			if (paper[i] > 0 && check(x, y, i)) 
			{
				paper[i]--;
				fill(x, y, i, 0);
				backtracking(xy + 1, cnt + 1);
				paper[i]++;
				fill(x, y, i, 1);
			}
		}
	}
	else
	{
		backtracking(xy + 1, cnt);
	}
}

void fill(int x, int y, int size, int num)
{
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			g_data[i][j] = num;
		}
	}
}
