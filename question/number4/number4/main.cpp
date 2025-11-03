#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size, que;
	vector<vector<int>> number, sum;
	vector<int> result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size >> que;
	number.resize(size + 1, vector<int>(size + 1));
	sum.resize(size + 1, vector<int>(size + 1));

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cin >> number[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + number[i][j];
		}
	}

	for (int i = 0; i < que; i++) {
		int x1, y1, x2, y2, hap;
		cin >> x1 >> y1 >> x2 >> y2;
		hap = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		result.push_back(hap);
	}

	cout << "\n";

	for (int i = 0; i < que; i++)
	{
		cout << result[i] << "\n";
	}

	cout.flush();
}