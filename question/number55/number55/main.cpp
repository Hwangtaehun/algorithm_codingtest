#include <iostream>
#include <vector>

using namespace std;

static vector<int> parent, correct;
static vector<vector<int>> partys;

int find(int num);
void unionfun(int a, int b);

int main()
{
	int person, party, know, people, result = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> person >> party >> know;
	
	parent.resize(person + 1);
	partys.resize(party + 1);
	correct.resize(know);

	for (int i = 1; i <= person; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < know; i++)
	{
		cin >> correct[i];
	}

	for (int i = 0; i < party; i++)
	{
		cin >> people;
		partys[i].resize(people);

		for (int j = 0; j < people; j++)
		{
			cin >> partys[i][j];
		}
	}

	for (int i = 0; i < party; i++)
	{
		for (int j = 0; j < partys[i].size() - 1; j++)
		{
			unionfun(partys[i][j], partys[i][j + 1]);
		}
	}

	for (int i = 0; i < party; i++)
	{
		int cur = partys[i][0];
		bool isPossible = true;

		for (int j = 0; j < know; j++)
		{
			if (find(cur) == find(correct[j]))
			{
				isPossible = false;
				break;
			}
		}

		if (isPossible)
		{
			result++;
		}
	}

	cout << result;
	cout.flush();
	return 0;
}

int find(int num)
{
	if (parent[num] == num)
	{
		return num;
	}
	else
	{
		return parent[num] = find(parent[num]);
	}
}

void unionfun(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b) 
	{
		parent[b] = a;
	}
}
