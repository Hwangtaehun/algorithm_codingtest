#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int size;
	queue<int> qu;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;

	for (int i = 1; i <= size; i++)
	{
		qu.push(i);
	}

	while (qu.size() > 1) {
		qu.pop();
		qu.push(qu.front());
		qu.pop();
	}

	cout << qu.front();
}