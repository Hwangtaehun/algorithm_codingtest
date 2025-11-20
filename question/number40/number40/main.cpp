#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int min, max;
	vector<int> result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> min >> max;
	result.resize(max + 1);

	for (int i = 2; i <= max; i++)
	{
		result[i] = i;
	}

	for (int i = 2; i <= sqrt(max); i++)
	{
		if (result[i] == 0)
		{
			continue;
		}

		for (int j = i + i; j <= max; j = j + i)
		{
			result[j] = 0;
		}
	}

	for (int i = min; i <= max; i++)
	{
		if (result[i] != 0) {
			cout << result[i] << "\n";
		}
	}
	cout.flush();

	return 0;
}
