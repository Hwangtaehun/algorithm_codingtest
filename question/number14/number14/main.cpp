#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(int o1, int o2) {
		int first_abs = abs(o1);
		int second_abs = abs(o2);

		if (first_abs == second_abs) {
			return o1 > o2;
		}
		else
		{
			return first_abs > second_abs;
		}
	}
};

int main() {
	int size;
	vector<int> data;
	vector<int> result;
	priority_queue<int, vector<int>, compare> que;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;
	data.resize(size);
	for (int i = 0; i < size; i++) {
		cin >> data[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (data[i] == 0) {
			if (que.empty()) {
				result.push_back(0);
			}
			else
			{
				result.push_back(que.top());
				que.pop();
			}
		}
		else
		{
			que.push(data[i]);
		}
	}

	return 0;
}