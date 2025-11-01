#include <iostream>
using namespace std;

int main() {
	int N = 0;
	int count[1001] = { 0 };

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int number = 0;
		cin >> number;
		count[number]++;
	}

	for (int i = 0; i <= 1000; i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				cout << i << " ";
			}
		}
	}
}