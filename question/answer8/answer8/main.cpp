#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, cnt = 0;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	data.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}

	sort(data.begin(), data.end());

	for (int i = 0; i < N; i++) {
		int key = data[i], start = 0, end = N - 1;

		while (start < end) {
			if (data[start] + data[end] == key) {
				if (start != i && end != i) {
					cnt++;
					break;
				}
				else if (start == i) {
					start++;
				}
				else {
					end--;
				}
			}
			else if (data[start] + data[end] < key) {
				start++;
			}
			else {
				end--;
			}
		}
	}

	cout << cnt << "\n";
	cout.flush();

	return 0;
}