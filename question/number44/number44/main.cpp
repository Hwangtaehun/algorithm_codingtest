#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long num, result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	result = num;

	for (long p = 2; p <= sqrt(num); p++)
	{
		if (num % p == 0)
		{
			result -= result / p;
		}

		while (num % p == 0)
		{
			num /= p;
		}
	}

	if (num > 1)
	{
		result -= result / num;
	}
	
	cout << result;
	cout.flush();

	return 0;
}