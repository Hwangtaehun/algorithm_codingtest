#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size, max = 0;
	vector<pair<int, int>> data;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> size;
	data.resize(size);
	for (int i = 0; i < size; i++) {
		cin >> data[i].first;
		data[i].second = i;
	}

	sort(data.begin(), data.end());

	for (int i = 0; i < size; i++)
	{
		int value = data[i].second - i;
		if (max < value) {
			max = value;
		}
	}

	cout << max + 1;
	cout.flush();

	return 0;
}