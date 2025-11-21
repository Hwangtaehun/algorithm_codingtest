#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int cnt = 0;
	long min, max;
	vector<bool> check;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> min >> max;
	check.assign(max - min + 1, false);

	for (long i = 2; i * i <= max; i++)
	{
		long pow = i * i;
		long start_index = min / pow;

		if (min % pow != 0)
		{
			start_index++;
		}

		for (long j = start_index; j * pow <= max; j++)
		{
			check[(int)((j * pow) - min)] = true;
		}
	}

	for (int i = 0; i < check.size(); i++)
	{
		if (!check[i])
		{
			cnt++;
		}
	}

	cout << cnt;
	cout.flush();
	return 0;
}