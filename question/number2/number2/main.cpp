#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size;
	vector<int> number;

	cin >> size;
	number.resize(size);

	for (int i = 0; i < size; i++)
	{
		cin >> number[i];
	}

	int max = 0, sum = 0;

	for (int i = 0; i < size; i++) {
		if (max < number[i]) {
			max = number[i];
		}
		sum += number[i];
	}

	float result = sum * 100.0 / max / size;

	cout << result << "\n";
	cout.flush();

	return 0;
}