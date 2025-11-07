#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& v, int i, int j);
void quickSort(vector<int>& v, int s, int e, int k);
int partition(vector<int>& v, int s, int e);

int main() {
	int cnt, idx;
	vector<int> data;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt >> idx;
	data.resize(cnt);

	for (int i = 0; i < cnt; i++)
	{
		cin >> data[i];
	}

	quickSort(data, 0, cnt - 1, idx - 1);
	cout << data[idx - 1];
	cout.flush();
}

void swap(vector<int>& v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void quickSort(vector<int>& v, int s, int e, int k)
{
	int pivot = partition(v, s, e);
	if (pivot == k)
	{
		return;
	}
	else if (k < pivot)
	{
		quickSort(v, s, pivot - 1, k);
	}
	else
	{
		quickSort(v, pivot + 1, e, k);
	}
}

int partition(vector<int>& v, int s, int e)
{
	if (s + 1 == e)
	{
		if (v[s] > v[e])
		{
			swap(v, s, e);
		}
		return e;
	}

	int m = (s + e) / 2;
	swap(v, s, m);
	int pivot = v[s];
	int i = s + 1, j = e;

	while (i <= j)
	{
		while (j >= s + 1 && pivot < v[j])
		{
			j--;
		}
		
		while (i <= e && pivot > v[i])
		{
			i++;
		}

		if (i < j) 
		{
			swap(v, i++, j--);
		}
		else
		{
			break;
		}
	}

	v[s] = v[j];
	v[j] = pivot;
	return j;
}
