#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int size;
	stack<int> stack;
	vector<int> data;
	vector<int> result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;
	data.resize(size);
	result.assign(size, 0);

	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}

	stack.push(0);

	for (int i = 1; i < size; i++) 
	{
		while (!stack.empty() && data[stack.top()] < data[i]) {
			result[stack.top()] = data[i];
			stack.pop();
		}

		stack.push(i);
	}

	while (!stack.empty()) {
		result[stack.top()] = -1;
		stack.pop();
	}

	for (int i = 0; i < size; i++) {
		cout << result[i] << " ";
	}
	cout.flush();
}