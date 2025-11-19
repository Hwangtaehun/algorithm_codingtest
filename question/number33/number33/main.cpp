#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> data;
	int num, cnt, start = 0, end = 0;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num >> cnt;
	data.resize(num);
	
	for (int i = 0; i < num; i++)
	{
		cin >> data[i];
		
		if (start < data[i])
		{
			start = data[i];
		}

		end += data[i];
	}

	while (start <=  end)
	{
		int sum = 0;
		int count = 0;
		int middle = (start + end) / 2;

		for (int i = 0; i < num; i++)
		{
			if (sum + data[i] > middle) {
				count++;
				sum = 0;
			}

			sum = sum + data[i];
		}

		if (sum != 0)
		{
			count++;
		}

		if (count > cnt)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}

	cout << start;

	return 0;
}