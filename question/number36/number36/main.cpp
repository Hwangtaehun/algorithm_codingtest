#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int cnt, data1, data2, sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() != 1)
	{
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();
		sum += data1 + data2;
		pq.push(sum);
	}

	cout << sum;

	return 0;
}