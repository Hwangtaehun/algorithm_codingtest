#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int cnt, size;
	vector<int> result;
	vector<pair<int, int>> data; //first: index, second: value
	deque<pair<int, int>> process;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt >> size;
	data.resize(cnt);
	for (int i = 0; i < cnt; i++)
	{
		data[i].first = i;
		cin >> data[i].second;
	}

	for (int i = 0; i < cnt; i++) {
		while(process.size() && process.back().second > data[i].second) {
			process.pop_back();
		}
		process.push_back({ data[i].first, data[i].second });

		if (process.front().first <= i - size) {
			process.pop_front();
		}

		result.push_back(process.front().second);
	}
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout.flush();

	return 0;
}