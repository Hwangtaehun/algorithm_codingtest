#include <iostream>
#include <vector>

using namespace std;

bool sosu(int num);

int main()
{
	int min, max;
	vector<int> result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> min >> max;

	for (int i = min; i <= max; i++)
	{
		if (sosu(i))
		{
			result.push_back(i);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();

	return 0;
}

bool sosu(int num)
{
	for (int i = 2; i < num; i++)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}

	return true;
}
