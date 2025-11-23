#include <iostream>
#include <vector>

using namespace std;

long gcd(long a, long b);
vector<long> Execute(long a, long b);

int main()
{
	long a, b, c, tgcd;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	tgcd = gcd(a, b);

	if (c % tgcd != 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		int mok = (int)(c / tgcd);
		vector<long> ret = Execute(a, b);
		cout << ret[0] * mok << " " << ret[1] * mok;
	}

	return 0;
}

long gcd(long a, long b)
{
	if (b == 0) 
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

vector<long> Execute(long a, long b)
{
	long q;
	vector<long> ret(2);

	if (b == 0)
	{
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}

	q = a / b;
	vector<long> v = Execute(b, a % b);
	ret[0] = v[1];
	ret[1] = v[0] - v[1] * q;

	return ret;
}
