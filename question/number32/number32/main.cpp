#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static vector<bool> g_exist;
static vector<int> g_data, g_find;

int main()
{
	int sz, end;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> sz;
	g_data.resize(sz);

	for (int i = 0; i < sz; i++)
	{
		cin >> g_data[i];
	}

	cin >> sz;
	g_find.resize(sz);
	g_exist.assign(sz, false);

	for (int i = 0; i < sz; i++)
	{
		cin >> g_find[i];
	}

	sort(g_data.begin(), g_data.end());

	for (int i = 0; i < g_find.size(); i++)
	{
		int start = 0, end = g_data.size() - 1;
		bool find = false;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (g_data[mid] < g_find[i])
			{
				start = mid + 1;
			}
			else if (g_data[mid] > g_find[i])
			{
				end = mid - 1;
			}
			else
			{
				find = true;
				break;
			}
		}

		g_exist[i] = find;
	}

	for (int i = 0; i < g_exist.size(); i++)
	{
		cout << g_exist[i] << "\n";
	}
	cout.flush();

	return 0;
}