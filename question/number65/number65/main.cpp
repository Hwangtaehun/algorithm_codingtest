#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size;
	vector<vector<int>> array;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;
	array.resize(size, vector<int>(size));
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> array[i][j];
		}
	}

	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (array[i][k] == 1 && array[k][j] == 1)
				{
					array[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << ' ';
		}
		cout << '\n';
	}
	cout.flush();
	return 0;
}