#include <iostream>
#include <vector>

using namespace std;

bool sosu(int n);
void bnf(vector<int> &v, int n, int c);
static int g_size, first[4] = { 2, 3, 5, 7 }, rest[5] = { 1, 3, 5, 7, 9 };

int main()
{
	vector<int> result;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> g_size;

	for (int i = 0; i < 4; i++) {
		bnf(result, first[i], 1);
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();

	return 0;
}

bool sosu(int n)
{
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void bnf(vector<int>& v, int n, int c)
{
	if (c == g_size) 
	{
		if(sosu(n))
		{
			v.push_back(n);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int num = (n * 10) + rest[i];

		if (sosu(num))
		{
			bnf(v, num, c + 1);
		}
	}
}
