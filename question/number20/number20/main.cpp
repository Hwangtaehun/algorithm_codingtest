#include <iostream>
#include <vector>

using namespace std;

int cnt;
void compareSort(vector<int>& v, int s, int e);

int main() {
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	data.resize(cnt);

	for (int i = 0; i < cnt; i++)
	{
		cin >> data[i];
	}

	compareSort(data, 0, cnt - 1);

	for (int i = 0; i < cnt; i++)
	{
		cout << data[i] << " ";
	}
	cout.flush();

	return 0;
}

void compareSort(vector<int>& v, int s, int e)
{
	int m, k, idx1, idx2;
	vector<int> temp;

	if (e - s < 1) {
		return;
	}

	m = (s + e) / 2;
	compareSort(v, s, m);
	compareSort(v, m + 1, e);

	temp.assign(cnt, 0);

	for (int i = s; i <= e; i++)
	{
		temp[i] = v[i];
	}

	k = s;
	idx1 = s;
	idx2 = m + 1;

	while (idx1 <= m && idx2 <= e)
	{
		if (temp[idx1] > temp[idx2])
		{
			v[k] = temp[idx2];
			k++;
			idx2++;
		}
		else 
		{
			v[k] = temp[idx1];
			k++;
			idx1++;
		}
	}

	while (idx1 <= m)
	{
		v[k] = temp[idx1];
		k++;
		idx1++;
	}

	while (idx2 <= e)
	{
		v[k] = temp[idx2];
		k++;
		idx2++;
	}
}
