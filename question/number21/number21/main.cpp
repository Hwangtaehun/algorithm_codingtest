#include <iostream>
#include <vector>

using namespace std;

static int result;

void mergesort(vector<int>& v, int s, int e);

int main() {
	int cnt;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	data.assign(cnt, 0);

	for (int i = 0; i < cnt; i++) {
		cin >> data[i];
	}

	mergesort(data, 0, cnt - 1);
	
	cout << result;
	cout.flush();
}

void mergesort(vector<int>& v, int s, int e) {
	int m, k, idx1, idx2;
	vector<int> tmp(e + 1, 0);

	if (e - s < 1) {
		return;
	}

	m = (s + e) / 2;

	mergesort(v, s, m);
	mergesort(v, m + 1, e);

	for (int i = s; i <= e; i++) {
		tmp[i] = v[i];
	}

	k = s;
	idx1 = s;
	idx2 = m + 1;

	while (idx1 <= m && idx2 <= e)
	{
		if (tmp[idx1] > tmp[idx2])
		{
			v[k] = tmp[idx2];
			idx2++;
			k++;
			result = result + idx2 - k;
		}
		else
		{
			v[k] = tmp[idx1];
			idx1++;
			k++;
		}
	}

	while (idx1 <= m) {
		v[k] = tmp[idx1];
		idx1++;
		k++;
	}

	while (idx2 <= e)
	{
		v[k] = tmp[idx2];
		idx2++;
		k++;
	}
}