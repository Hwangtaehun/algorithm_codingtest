#include <iostream>
#include <algorithm>
using namespace std;

struct Score
{
	int english, math;
};

bool compare(const Score& a, const Score& b) {
	if (a.english != b.english) {
		return a.english > b.english;
	}

	return a.math > b.math;
}

int main() {
	Score score[] = {
		{80, 100},
		{100, 50},
		{70, 100},
		{80, 90}
	};

	int n = sizeof(score) / sizeof(score[0]);
	sort(score, score + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << "영어: " << score[i].english << ", 수학: " << score[i].math << '\n';
	}
}