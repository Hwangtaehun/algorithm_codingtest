#include <iostream>
#include <vector>

using namespace std;

int gcd(int n1, int n2);

int main()
{
	int cnt;
	vector<int> result;
	vector<pair<int, int>> testcase;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;
	result.resize(cnt);
	testcase.resize(cnt);

	for (int i = 0; i < cnt; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		testcase[i] = {n1, n2};
	}

	for (int i = 0; i < cnt; i++)
	{
		result[i] = testcase[i].first * testcase[i].second / gcd(testcase[i].first, testcase[i].second);
	}

	for (int i = 0; i < cnt; i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();

	return 0;
}

int gcd(int n1, int n2)
{
	int big, small, num;

	if (n1 > n2) 
	{
		big = n1;
		small = n2;
	}
	else
	{
		big = n2;
		small = n1;
	}

	num = big % small;

	while (num != 0)
	{
		big = small;
		small = num;

		num = big % small;
	}
	
	return small;
}
