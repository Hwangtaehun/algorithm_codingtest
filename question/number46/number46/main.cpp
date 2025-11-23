#include <iostream>

using namespace std;

int gcd(long a, long b);

int main()
{
	long n1, n2, temp;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n1 >> n2;

	if (n1 > n2)
	{
		int t = n1;
		n1 = n2;
		n2 = t;
	}

	/*temp = n2 % n1;

	while (temp != 0) {
		n2 = n1;
		n1 = temp;

		temp = n2 % n1;
	}

	for (int i = 0; i < n1; i++)
	{
		cout << "1";
	}*/

	temp = gcd(n1, n2);

	for (long i = 0; i < temp; i++)
	{
		cout << 1;
	}
	cout.flush();

	return 0;
}

int gcd(long a, long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return (b, a % b);
	}
}
