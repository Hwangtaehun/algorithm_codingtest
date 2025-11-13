#include <iostream>
#include <vector>

using namespace std;

static int result = 0;
static vector<int> arr;

void backtracking(int row);
bool check(int row);

int main()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	arr.assign(n, 0);
	backtracking(0);
	cout << result;
	cout.flush();
}

void backtracking(int row)
{
	if (row == arr.size())
	{
		result++;
		return;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		arr[row] = i;

		if (check(row))
		{
			backtracking(row + 1);
		}
	}
}

bool check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (arr[i] == arr[row])
		{
			return false;
		}

		if (abs(i - row) == abs(arr[i] - arr[row]))
		{
			return false;
		}
	}
	return true;
}
