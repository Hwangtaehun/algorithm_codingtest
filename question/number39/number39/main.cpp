#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
vector<string> split(string input, char delimiter);
int hap(string a);

int main()
{
	string str;
	int sum = 0;
	vector<string> plus;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	plus = split(str, '-');

	for (int i = 0; i < plus.size(); i++)
	{
		if (i != 0)
		{
			sum -= hap(plus[i]);
		}
		else
		{
			sum += hap(plus[i]);
		}
	}

	cout << sum;
	cout.flush();

	return 0;
}

vector<string> split(string input, char delimiter)
{
	string data;
	vector<string> result;
	stringstream ss(input);

	while (getline(ss, data, delimiter))
	{
		result.push_back(data);
	}

	return result;
}

int hap(string a)
{
	int sum = 0;
	vector<string> temp = split(a, '+');

	for (int i = 0; i < temp.size(); i++)
	{
		sum += stoi(temp[i]);
	}

	return sum;
}