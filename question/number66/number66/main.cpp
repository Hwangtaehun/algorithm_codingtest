#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
	int user, cnt, min, num;
	vector<vector<int>> array;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> user >> cnt;

	array.assign(user + 1, vector<int>(user + 1, 10000001));

	for (int i = 1; i <= user; i++)
	{
		array[i][i] = 0;
	}

	for (int i = 0; i < cnt; i++)
	{
		int s, e;
		cin >> s >> e;
		array[s][e] = array[e][s] = 1;
	}

	for (int i = 1; i <= user; i++)
	{
		for (int j = 1; j <= user; j++)
		{
			for (int k = 1; k <= user; k++)
			{
				if (array[j][k] > array[j][i] + array[i][k])
				{
					array[j][k] = array[j][i] + array[i][k];
				}
			}
		}
	}

	min = INT_MAX;
	num = -1;

	for (int i = 1; i <= user; i++)
	{
		int sum = 0;
		
		for (int j = 1; j <= user; j++)
		{
			sum += array[i][j];
		}

		if (sum < min)
		{
			num = i;
			min = sum;
		}
	}
	
	cout << num;
	cout.flush();
	return 0;
}