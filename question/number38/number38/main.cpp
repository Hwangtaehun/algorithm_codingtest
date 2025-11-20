#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int cnt = 0, num, end = -1;
	vector<pair<int, int>> room;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> num;
	room.resize(num);

	for (int i = 0; i < num; i++)
	{
		cin >> room[i].second;
		cin >> room[i].first;
	}

	sort(room.begin(), room.end());

	for (int i = 0; i < num; i++)
	{
		if (room[i].second >= end) {
			end = room[i].first;
			cnt++;
		}
	}

	cout << cnt;
	cout.flush();

	return 0;
}