#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int size, num = 1;
	vector<int> seq;
	vector<char> res;
	stack<int> store;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;
	seq.resize(size);

	for (int i = 0; i < size; i++)
	{
		cin >> seq[i];
	}

	for (int i = 0; i < size; i++) 
	{
		if (seq[i] >= num) {
			while (seq[i] >= num) {
				store.push(num++);
				res.push_back('+');
			}
			store.pop();
			res.push_back('-');
		}
		else
		{
			int stack_num = store.top();
			store.pop();
			if (stack_num > seq[i]) {
				res = { 'N', 'O' };
				break;
			}
			else {
				res.push_back('-');
			}
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (res[i] != 'N') {
			cout << "\n";
		}
	}
	cout.flush();
}