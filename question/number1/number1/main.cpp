#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	string number;

	cin >> num;
	cin >> number;

	int sum = 0;

	for (int i = 0; i < number.length(); i++) {
		sum += number[i] - '0';
	}

	cout << sum << '\n';
	cout.flush();

	return 0;
}