#include <iostream>
#include <vector>

using namespace std;

struct RANGE
{
	int start;
	int end;
};

int main() {
	int data, cnt;
	vector<int> sum, result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> data >> cnt;
	sum.resize(data + 1);
	sum[0] = 0;

	for (int i = 0; i < data; i++) {
		int temp;
		cin >> temp;
		sum[i + 1] = sum[i] + temp;
	}

	for (int i = 0; i < cnt; i++) {
		int start, end;
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << "\n";
	}

	cout.flush();
}