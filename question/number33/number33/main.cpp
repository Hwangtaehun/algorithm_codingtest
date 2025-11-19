#include <iostream>
#include <vector>

using namespace std;

static int cnt;
static vector<int> g_data;

int main()
{
	int num;
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num >> cnt;
	g_data.resize(num);

	for (int i = 0; i < num; i++)
	{
		cin >> g_data[i];
	}

	return 0;
}