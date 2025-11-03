#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, cnt = 0;
	vector<int> sum, reminder;

	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	sum.assign(N + 1, 0);
	reminder.assign(N, 0);

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}

	for (int i = 1; i <= N; i++)
	{
		int rest = sum[i] % M;

		if (rest == 0) {
			cnt++;
		}

		reminder[rest]++;
	}

	for (int i = 0; i < reminder.size(); i++) {
		if (reminder[i] > 1) {
			cnt += reminder[i] * (reminder[i] - 1) / 2;
		}
	}

	cout << cnt << "\n";
	cout.flush();

	return 0;
}