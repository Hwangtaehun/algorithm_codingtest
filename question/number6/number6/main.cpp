#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, cnt = 1, start_index = 1, end_index = 1, sum = 1;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (end_index != N) {
		if (sum == N) {
			end_index++;
			sum += end_index;
			cnt++;
		}
		else if (sum > N) {
			sum -= start_index;
			start_index++;
		}
		else {
			end_index++;
			sum += end_index;
		}
	}

	cout << cnt << "\n";
	cout.flush();

	return 0;
}