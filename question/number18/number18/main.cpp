#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size, result = 0;
	vector<int> sum;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;
	data.resize(size);
	sum.assign(size, 0);
	
	for (int i = 0; i < size; i++) 
	{
		cin >> data[i];
	}

	for (int i = 1; i < size; i++) 
	{
		int point = i;
		int value = data[i];

		for (int j = i - 1; j >= 0; j--)
		{
			if (data[j] < data[i]) 
			{
				point = j + 1;
				break;
			}

			if (j == 0) 
			{
				point = 0;
			}
		}

		for (int j = i; j > point; j--) 
		{
			data[j] = data[j - 1];
		}

		data[point] = value;
	}

	for (int i = 0; i < size; i++)
	{
		if (i != 0) {
			sum[i] = sum[i - 1];
		}
		sum[i] += data[i];
	}

	for (int i = 0; i < size; i++)
	{
		result += sum[i];
	}

	cout << result;
	cout.flush();
}