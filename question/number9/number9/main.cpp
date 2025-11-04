#include <iostream>
#include <string>
#include <vector>
#define SIZE 4

using namespace std;

vector<int> compare(string s) {
	vector<int> result(SIZE, 0);

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case 'A':
			result[0]++;
			break;
		case 'C':
			result[1]++;
			break;
		case 'G':
			result[2]++;
			break;
		case 'T':
			result[3]++;
			break;
		}
	}

	return result;
}

void Addremove(vector<int> &count, char c,int n) {
	switch (c)
	{
	case 'A':
		count[0] += n;
		break;
	case 'C':
		count[1] += n;
		break;
	case 'G':
		count[2] += n;
		break;
	case 'T':
		count[3] += n;
		break;
	}
}

bool Check(const vector<int> dnacnt, const vector<int> count) {
	for (int i = 0; i < SIZE; i++) {
		if (dnacnt[i] > count[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	string word, sub_word;
	int leg, sub, cnt = 0;
	vector<int> dnacnt(SIZE, 0), count(SIZE, 0);

	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> leg >> sub >> word;

	for (int i = 0; i < SIZE; i++) {
		cin >> dnacnt[i];
	}

	for (int i = sub; i <= leg; i++) {
		int start = i - sub; // start

		if (sub_word.empty()) {
			sub_word = word.substr(start, sub);
			count = compare(sub_word);
		}
		else {
			Addremove(count, word[i - 1], 1);
			Addremove(count, word[start - 1], -1);
		}
		
		if (Check(dnacnt,count)) {
			cnt++;
		}
	}

	cout << cnt << "\n";
	cout.flush();
	return 0;
}