#include <iostream>
using namespace std;

void n1() {
	int N = 1000;
	int cnt = 1;

	for (int i = 0; i < N; i++) {
		cout << "¿¬»ê È½¼ö: " << cnt++ << "\n";
	}
}

void n2() {
	int N = 1000;
	int cnt = 1;

	for (int i = 0; i < N; i++) {
		cout << "¿¬»ê È½¼ö: " << cnt++ << "\n";
	}

	for (int i = 0; i < N; i++) {
		cout << "¿¬»ê È½¼ö: " << cnt++ << "\n";
	}

	for (int i = 0; i < N; i++) {
		cout << "¿¬»ê È½¼ö: " << cnt++ << "\n";
	}
}

void n3() {
	int N = 1000;
	int cnt = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cout << "¿¬»ê È½¼ö: " << cnt++ << "\n";
		}
	}
}

int main() {
	//n1();
	//n2();
	n3();
}