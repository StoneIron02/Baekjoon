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

void DFS(int s, int m, int count) {
	if (count == m) {
		for (int i = 0; i < currentList.size(); i++)
			cout << currentList[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < vertexList.size(); i++) {
		if (vertexList[i]->key < s) continue;
		if (!vertexList[i]->visited) {
			vertexList[i]->visited = true;
			currentList.push_back(vertexList[i]->key);
			DFS(vertexList[i]->key, m, count + 1);
			vertexList[i]->visited = false;
			currentList.pop_back();
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		vertexList.push_back(new vertex(i));
	DFS(1, m, 0);
}