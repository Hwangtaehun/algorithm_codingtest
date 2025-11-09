#include <iostream>
#include <vector>
#define SIZE 10001

using namespace std;

int main() {
	int cnt;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	data.assign(SIZE, 0);

	for (int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		data[num]++;
	}

	for (int i = 0; i < SIZE; i++)
	{
		if(data[i] != 0)
		{
			cout << i << "\n";
		}
	}

	cout.flush();

	return 0;
}