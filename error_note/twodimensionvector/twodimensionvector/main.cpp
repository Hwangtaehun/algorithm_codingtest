#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int endNode;
	int value;
};

int main() {
	int N, E;
	vector<vector<Edge>> A;

	cin >> N >> E;
	A.resize(N + 1);

	for (int i = 0; i < E; i++) {
		int s, e, v = 0;
		cin >> s >> e >> v;
		A[s].push_back({ e, v });
	}

	for (Edge edge : A[1]) {
		int next = edge.endNode;
		int value = edge.value;
		cout << "도착노드: " << next << ", 가중치: " << value << '\n';
	}
}