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
	vector<RANGE> question;

	cin >> data >> cnt;
	sum.resize(data + 1);
	question.resize(cnt);

	sum[0] = 0;

	for (int i = 0; i < data; i++) {
		int temp;
		cin >> temp;
		hap += temp;

		sum[i + 1] = hap;
	}

	for (int i = 0; i < cnt; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		question[i].start = t1;
		question[i].end = t2;
	}

	for (int i = 0; i < cnt; i++) {
		int start = question[i].start - 1;
		int end = question[i].end;
		int temp = sum[end] - sum[start];

		result.push_back(temp);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
		cout.flush();
	}
}