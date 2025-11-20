#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int cnt, one = 0, zero = 0, sum = 0;
	priority_queue<int> plusPq;
	priority_queue<int, vector<int>, greater<int>> minusPq;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		if (num == 0) 
		{
			zero++;
		}
		else if (num == 1)
		{
			one++;
		}
		else if (num < 0)
		{
			minusPq.push(num);
		}
		else
		{
			plusPq.push(num);
		}
	}

	while (plusPq.size() > 1)
	{
		int data1 = plusPq.top();
		plusPq.pop();
		int data2 = plusPq.top();
		plusPq.pop();
		sum += data1 * data2;
	}

	if (!plusPq.empty())
	{
		sum += plusPq.top();
		plusPq.pop();
	}

	while (minusPq.size() > 1)
	{
		int data1 = minusPq.top();
		minusPq.pop();
		int data2 = minusPq.top();
		minusPq.pop();
		sum += data1 * data2;
	}

	if (!minusPq.empty())
	{
		if (zero == 0)
		{
			sum += minusPq.top();
		}
		minusPq.pop();
	}

	sum += one;

	cout << sum;
	cout.flush();

	return 0;
}