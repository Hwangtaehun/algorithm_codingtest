#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long N, K, start = 1, end, ans = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	end = K;

	while (start <= end)
	{
		long middle = (start + end) / 2;
		long cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(middle / i, N);
		}

		if (cnt < K)
		{
			start = middle + 1;
		}
		else
		{
			ans = middle;
			end = middle - 1;
		}
	}

	cout << ans << "\n";
}