#include <iostream>
#include <algorithm>
using namespace std;

int A[] = { 5, 3, 2, 4, 1 };

void asc() {
	int n = sizeof(A) / sizeof(A[0]);
	sort(A, A + n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
	cout.flush();
}

void desc() {
	int n = sizeof(A) / sizeof(A[0]);
	sort(A, A + n, greater<int>());
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
	cout.flush();
}

void main() {
	asc();
	desc();
}