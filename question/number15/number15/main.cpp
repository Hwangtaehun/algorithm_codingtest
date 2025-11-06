#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;
	data.resize(size);
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (data[j] > data[j + 1]) {
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << data[i] << "\n";
	}
	cout.flush();
}