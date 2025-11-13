#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int n, m;
static vector<bool> used;
static vector<string> result;

void casebycase(int leg, string str);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	used.assign(n, false);

	casebycase(0, "");

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	cout.flush();

	return 0;
}

void casebycase(int leg, string str)
{
	if (leg == m) {
		result.push_back(str);
		return;
	}


	for (int i = 1; i <= n; i++) 
	{
		if (!used[i - 1]) 
		{
			used[i - 1] = true;
			casebycase(leg + 1, str + to_string(i) + " ");
			used[i - 1] = false;
		}
	}
}
