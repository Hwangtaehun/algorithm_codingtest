#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, cnt = 0, i = 0, j;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	data.resize(N);
	j = N - 1;

	for (int k = 0; k < N; k++)
	{
		cin >> data[k];
	}

	sort(data.begin(), data.end());

	while (i < j) {
		int sum = data[i] + data[j];

		if (sum == M) {
			i++;
			j--;
			cnt++;
		} 
		else if(sum > M) {
			j--;
		}
		else {
			i++;
		}
	}

	cout << cnt << "\n";
	cout.flush();

	return 0;
}