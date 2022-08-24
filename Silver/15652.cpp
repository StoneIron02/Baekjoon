#include <iostream>
#include <vector>
using namespace std;

struct vertex {
	int key;
	bool visited;
	vertex(int key) : key(key) {
		visited = false;
	}
};

vector<vertex*> vertexList;
vector<int> currentList;

void DFS(int m, int count) {
	if (count == m) {
		for (int i = 0; i < currentList.size(); i++)
			cout << currentList[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < vertexList.size(); i++) {
		if (!currentList.empty() && vertexList[i]->key < currentList.back()) continue;
		currentList.push_back(vertexList[i]->key);
		DFS(m, count + 1);
		currentList.pop_back();
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		vertexList.push_back(new vertex(i));
	DFS(m, 0);
}