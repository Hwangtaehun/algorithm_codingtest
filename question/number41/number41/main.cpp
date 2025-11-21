#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long result[10000001];
	int left, right, cnt = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> left >> right;

	for (int i = 2; i < 10000001; i++)
	{
		result[i] = i;
	}

	for (int i = 2; i < sqrt(10000001); i++)
	{
		if (result[i] == 0)
		{
			continue;
		}

		for (int j = i + i; j < 10000001; j = j + i)
		{
			result[j] = 0;
		}
	}

	for (int i = 2; i < sqrt(10000001); i++)
	{
		if (result[i] != 0)
		{
			long temp = result[i];

			while ((double)result[i] <= (double)right / (double)temp)
			{
				if ((double)result[i] >= (double)left / (double)temp)
				{
					cnt++;
				}
				temp *= result[i];
			}
		}
	}

	cout << cnt;
	cout.flush();

	return 0;
}