#include <iostream>
#include <string>
#include <cmath>
#define SIZE 10000001

using namespace std;

bool check(int num);

int main()
{
	long n;
	int r = 0, i;
	long sosu[SIZE];

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 2; i < SIZE; i++)
	{
		sosu[i] = i;
	}

	for (int i = 2; i <= sqrt(SIZE); i++)
	{
		if (sosu[i] == 0)
		{
			continue;
		}

		for (int j = i + i; j < SIZE; j = j + i)
		{
			sosu[j] = 0;
		}
	}

	i = n;

	while (true)
	{
		if (sosu[i] != 0 && check(sosu[i]))
		{
			r = sosu[i];
			break;
		}
		i++;
	}

	cout << r;
	cout.flush();

	return 0;
}

bool check(int num)
{
	string str = to_string(num);
	int s = 0, e = str.length() - 1;

	while (s <= e) {
		if (str[s] != str[e])
		{
			return false;
		}

		s++;
		e--;
	}

	return true;
}
