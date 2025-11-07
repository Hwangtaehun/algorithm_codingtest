#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string in;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> in;
	for (int i = 0; i < in.length(); i++)
	{
		//data.push_back(in[i] - '0');
		data.push_back(stoi(in.substr(i, 1)));
	}

	for (int i = 0; i < data.size(); i++) {
		int max = 0, idx = i;

		for (int j = i; j < data.size(); j++) {
			if (data[j] > max) {
				idx = j;
				max = data[j];
			}
		}

		if (idx != i) {
			int temp = data[i];
			data[i] = data[idx];
			data[idx] = temp;
		}
	}

	for (int i = 0; i < data.size(); i++) {
		cout << data[i];
	}
	cout.flush();
}